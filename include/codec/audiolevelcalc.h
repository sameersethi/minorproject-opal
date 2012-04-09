/*
 * audiolevelcalc.h
 *
 *  Created on: Mar 16, 2012
 *      Author: Sameer
 */

#ifndef AUDIOLEVELCALC_H_
#define AUDIOLEVELCALC_H_

#ifdef P_USE_PRAGMA
#pragma interface
#endif

#include <opal/buildopts.h>
#include <rtp/rtp.h>
#include <math.h>



class OpalAudioLevelCalculator : public PObject
{
    PCLASSINFO(OpalAudioLevelCalculator, PObject);
  public:
    enum Mode {
      NoAudioLevelCalculation,
      DoAudioLevelCalculation,
      AudioLevelCalculationWithVAD,
      NumModes
    };

    struct Params {
      Params(
        Mode mode = DoAudioLevelCalculation
      )
        : m_mode(mode)
      { }

      Mode     m_mode;             /// Audio Level Calculator Mode
    };

  /**@name Construction */
  //@{
    /**Create a new connection.
     */
    OpalAudioLevelCalculator(
      const Params & newParam ///<  New parameters for audio level calculation
    );
  //@}

  /**@name Basic operations */
  //@{
    const PNotifier & GetReceiveHandler() const { return receiveHandler; }

    /**Set the audio level calculator parameters.
       This enables and disables the audio level calculation.
      */
    void SetParameters(
      const Params & newParam ///<  New parameters for for audio level calculation
    );

    void GetAudioLevelStatus(
      PINDEX * audioLevel,
      int * vad
    ) const;

    /**Get the audio level and VAD status
       This is called from within the audio level calculation algorithm to
       calculate the audio level of the packet in dBov and also the
       VAD status.

       The default behaviour returns -1 in VAD to indicate VAD is not enabled.
      */
    virtual PINDEX GetAudioLevel(
      const BYTE * buffer,  ///<  RTP payload being detected
      PINDEX size           ///<  Size of payload buffer
    );

  protected:
    PDECLARE_NOTIFIER(RTP_DataFrame, OpalAudioLevelCalculator, ReceivedPacket);

    PNotifier receiveHandler;

    Params param;

    PINDEX     m_audioLevel;
    int 	m_vad;
};


extern ostream & operator<<(ostream & strm, OpalAudioLevelCalculator::Mode mode);


#endif /* AUDIOLEVELCALC_H_ */
