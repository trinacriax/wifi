#include "ns3/snr-tag.h"

using namespace ns3;

SnrTag::SnrTag(): m_sinr (0)
{}
TypeId
SnrTag::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::InfoXTag")
    .SetParent<Tag> ()
    .AddConstructor<SnrTag> ()
    .AddAttribute ("sinr", "The sinr of the last packet received",
                   DoubleValue (0.0),
                   MakeDoubleAccessor (&SnrTag::SetSinr,&SnrTag::GetSinr),
                   MakeDoubleChecker<double> ())
//    .AddAttribute ("rssi", "The rssi of the last packet received",
//				   DoubleValue (0.0),
//				   MakeDoubleAccessor (&InfoXTag::SetRssi,&InfoXTag::GetRssi),
//				   MakeDoubleChecker<double> ())
  ;
  return tid;
}

TypeId
SnrTag::GetInstanceTypeId (void) const
{
  return GetTypeId ();
}

uint32_t
SnrTag::GetSerializedSize (void) const
{
  return sizeof (double);
}

void
SnrTag::Serialize (TagBuffer i) const
{
  i.WriteDouble (m_sinr);
//  i.WriteDouble (m_rssi);
}

void
SnrTag::Deserialize (TagBuffer i)
{
	m_sinr = i.ReadDouble ();
//	m_rssi = i.ReadDouble ();
}

void
SnrTag::Print (std::ostream &os) const
{
  os << "SINR="<<m_sinr;//<<" RSSI=" << m_rssi;
}

void
SnrTag::SetSinr (double sinr)
{
	m_sinr = sinr;
}

double
SnrTag::GetSinr (void) const
{
  return m_sinr;
}
