#ifndef __RDFG_h
#define __RDFG_h

#include <Rcpp.h>
#include "rToCpp.h"
#include "PhyDef.h"
#include "DiscreteFactorGraph.h"

using namespace Rcpp;

phy::DFG rToDFG(IntegerVector varDimensions, List facPotentials, List facNeighbors);

class RDFG{
public:
  //Constructors
  RDFG(IntegerVector varDimensions, List facPotentials, List facNeighbors, IntegerVector potentialMap);

  // Calculate likelihood of of data frame
  double calcLikelihood(IntegerVector observations, LogicalVector observed);
  double calcLogLikelihood(IntegerVector observations, LogicalVector observed);

  // Calculate Expecations
  NumericVector expect(List facScores);

  // Sampling
  IntegerMatrix simulate(int N);

  //Importance sampling
  DataFrame makeImportanceSamples(int N, double alpha, List facPotentialsFg);
  double calculateExpectedScoreIS(double alpha, List facPotentialsFg);

  //Calculate most probable state given partially observed data
  Rcpp::IntegerVector maxProbState(Rcpp::IntegerVector observations, Rcpp::LogicalVector observed);

  //Calculate expectation counts
  //TODO: Potentially cater for variables that are always unobserved
  Rcpp::List facExpCounts(Rcpp::IntegerMatrix observations );

  // Accessors
  List getPotentials();
  void resetPotentials(List facPotentials);
  void resetScores(List facScores);
  


private:
  phy::DFG dfg;

};

#endif //__RDFG_h
