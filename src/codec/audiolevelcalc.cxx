/*
 * audiolevelcal.cxx
 *
 *  Created on: Mar 16, 2012
 *      Author: Sameer
 */

#include <ptlib.h>

#ifdef __GNUC__
#pragma implementation "audiolevelcalc.h"
#endif
#include <opal/buildopts.h>

#include <codec/audiolevelcalc.h>
#include <opal/patch.h>

#define new PNEW

ostream & operator<<(ostream & strm, OpalAudioLevelCalculator::Mode mode)
{
  static const char * const names[OpalAudioLevelCalculator::NumModes] = {
		  "NoAudioLevelCalculation",
	      "DoAudioLevelCalculation",
	      "AudioLevelCalculationWithVAD",
  };

  if (mode >= 0 && mode < OpalAudioLevelCalculator::NumModes && names[mode] != NULL)
    strm << names[mode];
  else
    strm << "OpalAudioLevelCalculator::Modes<" << mode << '>';
  return strm;
}


///////////////////////////////////////////////////////////////////////////////

OpalAudioLevelCalculator::OpalAudioLevelCalculator(const Params & theParam)
#ifdef _MSC_VER
#pragma warning(disable:4355)
#endif
  : receiveHandler(PCREATE_NOTIFIER(ReceivedPacket))
#ifdef _MSC_VER
#pragma warning(default:4355)
#endif
{
  // Initialise the parameters
  SetParameters(theParam);

  PTRACE(4, "Audio Level Calc \tHandler created");
}

void OpalAudioLevelCalculator::SetParameters(const Params & newParam)
{
  param = newParam;

  PTRACE(4, "Audio Level Calc\tParameters set: "
            "mode=" << param.m_mode << ", ");
}

void OpalAudioLevelCalculator::GetAudioLevelStatus(int * audioLevel,int * vad)const
{
	*audioLevel = m_audioLevel;
	*vad = m_vad;
}

void OpalAudioLevelCalculator::ReceivedPacket(RTP_DataFrame & frame, INT)
{
	// Check if we have no data to operate on
	if (frame.GetPayloadSize() == 0)
		return;

	// Return if Audio Level Calculation is disabled
	if (param.m_mode == NoAudioLevelCalculation)
		return;


	// Can never have average signal level that high, this indicates that the
	// hardware cannot do silence detection.
	m_audioLevel = GetAudioLevel(frame.GetPayloadPtr(), frame.GetPayloadSize());

	if (param.m_mode == AudioLevelCalculationWithVAD)
	{

	}


}

int OpalAudioLevelCalculator::GetAudioLevel(const BYTE * buffer, PINDEX size)
{
	double rms = 0;

	for (int i=0; i < size; i++)
	{
		double sample = buffer[i];

		sample /= UCHAR_MAX;
		rms += sample * sample;
	}

	rms = (size == 0) ? 0 : sqrt(rms / size);

	double MIN_AUDIO_LEVEL = -127;
	double MAX_AUDIO_LEVEL = 0;
	double db;

	if (rms > 0)
	{
		db = 20 * log10(rms);

		if (db < MIN_AUDIO_LEVEL)
		{
			db = MIN_AUDIO_LEVEL;
		}
		else if (db > MAX_AUDIO_LEVEL)
		{
			db = MAX_AUDIO_LEVEL;
		}
	}
	else
	{
		db = MIN_AUDIO_LEVEL;
	}

	return (int)floor(db);
}

