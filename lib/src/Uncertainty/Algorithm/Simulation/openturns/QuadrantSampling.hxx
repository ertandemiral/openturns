//                                               -*- C++ -*-
/**
 *  @brief Sampling in standard space quadrants
 *
 *  Copyright 2005-2017 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_QUADRANTSAMPLING_HXX
#define OPENTURNS_QUADRANTSAMPLING_HXX

#include "openturns/SamplingStrategy.hxx"
#include "openturns/RandomDirection.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class RandomDirection
 */

class OT_API QuadrantSampling :
  public SamplingStrategyImplementation
{

  CLASSNAME;

public:

  /** Default constructor */
  explicit QuadrantSampling(const SamplingStrategy & samplingStrategy = RandomDirection(),
                            const UnsignedInteger quadrantIndex = 0,
                            const NumericalPoint & quadrantOrientation = NumericalPoint());

  /** Virtual constructor */
  virtual QuadrantSampling * clone() const;

  /** Generate a set of directions */
  virtual NumericalSample generate() const;

  /** Quadrant index accessor */
  void setQuadrantIndex(const UnsignedInteger quadrantIndex);
  UnsignedInteger getQuadrantIndex() const;

  /** Quadrant orientation accessor */
  void setQuadrantOrientation(const NumericalPoint & quadrantOrientation);
  NumericalPoint getQuadrantOrientation() const;

  /** Strata indices accessor */
  void setStrataIndices(const Indices & strataIndices);
  Indices getStrataIndices() const;

  /** String converter */
  String __repr__() const;

protected:
  /** Update rotation parameters */
  void updateRotation();

  // underlying generator
  SamplingStrategy samplingStrategy_;

  // quadrant index in [0; 2^d[
  UnsignedInteger quadrantIndex_;

  // first quadrant bisector
  NumericalPoint quadrantOrientation_;

  // rotation matrix
  SquareMatrix R_;

  // stratification indices
  Indices strataIndices_;

} ; /* class QuadrantSampling */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_QUADRANTSAMPLING_HXX */
