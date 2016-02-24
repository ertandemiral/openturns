// SWIG file CalibrationStrategy.i

%{
#include "openturns/CalibrationStrategy.hxx"
%}

%include CalibrationStrategy_doc.i

OTDefaultCollectionConvertFunctions(CalibrationStrategy)

OTTypedInterfaceObjectHelper(CalibrationStrategy)
OTTypedCollectionInterfaceObjectHelper(CalibrationStrategy)

%include openturns/CalibrationStrategy.hxx

namespace OT {  
%extend CalibrationStrategy {
  const String __str__() const { return self->__repr__(); }
}
}
namespace OT { %extend CalibrationStrategy { CalibrationStrategy(const CalibrationStrategy & other) { return new OT::CalibrationStrategy(other); } } }
