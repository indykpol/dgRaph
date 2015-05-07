#' Calculate likelihood of observation
#' @param data      dataframe or matrix with observed data. The mapping between columns and rows will be performed automatically. NA will be interpreted as a missing variable
#' @param dfg       discrete factor graph object
#' @param log       calculate loglikelihood
#' @return A vector of likelihoods for each observation
likelihood <- function(data, dfg, log = FALSE){
  # Correct number of columns
  stopifnot(ncol(data) == length(dfg$varNames))
  
  # Correct data type
  if(is.matrix(data))
      stopifnot(is.numeric(data))
  # TODO NA's has type logical
  #if(is.data.frame(data))
  #    stopifnot(all(lapply(data, is.numeric)))
  
  # Calculate likelihood
  apply(data, 1, FUN=function(x){
    obs <- x
    obs[is.na(obs)] <- 1
    dfg$dfgmodule$calcLikelihood(obs ,!is.na(x))
  })
}