#ifndef __tmsort__
#define __tmsort__ 455
#include<tmerr.h>
#include<tmconst.h>
#include<tmstack.h>
#include<tmutils.h>
void mergeSort(void *x, int (*p2f)(void *, void *), int es, int lowerBound, int upperBound, int *successful, int *error);
#endif