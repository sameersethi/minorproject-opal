//
// h235_srtp.h
//
// Code automatically generated by asnparse.
//

#if ! H323_DISABLE_H235_SRTP

#ifndef __H235_SRTP_H
#define __H235_SRTP_H

#ifdef P_USE_PRAGMA
#pragma interface
#endif

#include <ptclib/asner.h>

//
// SrtpCryptoCapability
//

class H235_SRTP_SrtpCryptoInfo;

class H235_SRTP_SrtpCryptoCapability : public PASN_Array
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H235_SRTP_SrtpCryptoCapability, PASN_Array);
#endif
  public:
    H235_SRTP_SrtpCryptoCapability(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    PASN_Object * CreateObject() const;
    H235_SRTP_SrtpCryptoInfo & operator[](PINDEX i) const;
    PObject * Clone() const;
};


//
// SrtpKeys
//

class H235_SRTP_SrtpKeyParameters;

class H235_SRTP_SrtpKeys : public PASN_Array
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H235_SRTP_SrtpKeys, PASN_Array);
#endif
  public:
    H235_SRTP_SrtpKeys(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    PASN_Object * CreateObject() const;
    H235_SRTP_SrtpKeyParameters & operator[](PINDEX i) const;
    PObject * Clone() const;
};


//
// FecOrder
//

class H235_SRTP_FecOrder : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H235_SRTP_FecOrder, PASN_Sequence);
#endif
  public:
    H235_SRTP_FecOrder(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_fecBeforeSrtp,
      e_fecAfterSrtp
    };

    PASN_Null m_fecBeforeSrtp;
    PASN_Null m_fecAfterSrtp;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// SrtpKeyParameters_lifetime
//

class H235_SRTP_SrtpKeyParameters_lifetime : public PASN_Choice
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H235_SRTP_SrtpKeyParameters_lifetime, PASN_Choice);
#endif
  public:
    H235_SRTP_SrtpKeyParameters_lifetime(unsigned tag = 0, TagClass tagClass = UniversalTagClass);

    enum Choices {
      e_powerOfTwo,
      e_specific
    };

    PBoolean CreateObject();
    PObject * Clone() const;
};


//
// SrtpKeyParameters_mki
//

class H235_SRTP_SrtpKeyParameters_mki : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H235_SRTP_SrtpKeyParameters_mki, PASN_Sequence);
#endif
  public:
    H235_SRTP_SrtpKeyParameters_mki(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    PASN_Integer m_length;
    PASN_OctetString m_value;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// ArrayOf_GenericData
//

class GenericData;

class H235_SRTP_ArrayOf_GenericData : public PASN_Array
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H235_SRTP_ArrayOf_GenericData, PASN_Array);
#endif
  public:
    H235_SRTP_ArrayOf_GenericData(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    PASN_Object * CreateObject() const;
    GenericData & operator[](PINDEX i) const;
    PObject * Clone() const;
};


//
// SrtpKeyParameters
//

class H235_SRTP_SrtpKeyParameters : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H235_SRTP_SrtpKeyParameters, PASN_Sequence);
#endif
  public:
    H235_SRTP_SrtpKeyParameters(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_lifetime,
      e_mki
    };

    PASN_OctetString m_masterKey;
    PASN_OctetString m_masterSalt;
    H235_SRTP_SrtpKeyParameters_lifetime m_lifetime;
    H235_SRTP_SrtpKeyParameters_mki m_mki;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// SrtpSessionParameters
//

class H235_SRTP_SrtpSessionParameters : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H235_SRTP_SrtpSessionParameters, PASN_Sequence);
#endif
  public:
    H235_SRTP_SrtpSessionParameters(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_kdr,
      e_unencryptedSrtp,
      e_unencryptedSrtcp,
      e_unauthenticatedSrtp,
      e_fecOrder,
      e_windowSizeHint,
      e_newParameter
    };

    PASN_Integer m_kdr;
    PASN_Boolean m_unencryptedSrtp;
    PASN_Boolean m_unencryptedSrtcp;
    PASN_Boolean m_unauthenticatedSrtp;
    H235_SRTP_FecOrder m_fecOrder;
    PASN_Integer m_windowSizeHint;
    H235_SRTP_ArrayOf_GenericData m_newParameter;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


//
// SrtpCryptoInfo
//

class H235_SRTP_SrtpCryptoInfo : public PASN_Sequence
{
#ifndef PASN_LEANANDMEAN
    PCLASSINFO(H235_SRTP_SrtpCryptoInfo, PASN_Sequence);
#endif
  public:
    H235_SRTP_SrtpCryptoInfo(unsigned tag = UniversalSequence, TagClass tagClass = UniversalTagClass);

    enum OptionalFields {
      e_cryptoSuite,
      e_sessionParams,
      e_allowMKI
    };

    PASN_ObjectId m_cryptoSuite;
    H235_SRTP_SrtpSessionParameters m_sessionParams;
    PASN_Boolean m_allowMKI;

    PINDEX GetDataLength() const;
    PBoolean Decode(PASN_Stream & strm);
    void Encode(PASN_Stream & strm) const;
#ifndef PASN_NOPRINTON
    void PrintOn(ostream & strm) const;
#endif
    Comparison Compare(const PObject & obj) const;
    PObject * Clone() const;
};


#endif // __H235_SRTP_H

#endif // if ! H323_DISABLE_H235_SRTP


// End of h235_srtp.h
