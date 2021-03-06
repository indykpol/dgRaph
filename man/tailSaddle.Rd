% Generated by roxygen2 (4.1.1): do not edit by hand
% Please edit documentation in R/tail.R
\name{tailSaddle}
\alias{tailSaddle}
\title{Saddlepoint approximation for tail estimation}
\usage{
tailSaddle(x, dfg1, dfg2)
}
\arguments{
\item{x}{points to evaluate tail probabilities in}

\item{dfg1}{dfg object specifying null model}

\item{dfg2}{dfg object specifying foreground model}
}
\value{
A dataframe with columns, x, tail estimate and confidence intervals
}
\description{
Saddlepoint approximation for tail estimation
}

