#ifndef INFO_X_TAG
#define INFO_X_TAG

#include "ns3/tag.h"
#include "ns3/double.h"
#include <iostream>

using namespace ns3;

class SnrTag : public Tag
{
public:
	SnrTag ();
  static TypeId GetTypeId (void);
  virtual TypeId GetInstanceTypeId (void) const;

  virtual uint32_t GetSerializedSize (void) const;
  virtual void Serialize (TagBuffer i) const;
  virtual void Deserialize (TagBuffer i);
  virtual void Print (std::ostream &os) const;

  void SetSinr (double sinr);
  double GetSinr (void) const;

private:
  double m_sinr;

};

#endif
