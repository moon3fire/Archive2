#include "ParallelMatrix.h"
int main()
{
ParallelMatrix matrix(10 , 20);
std::cout<<matrix.SumParallel(1) << " ";
std::cout<<matrix.SumParallel(2) << " ";
std::cout<<matrix.SumParallel(4) << " ";
std::cout<<matrix.SumParallel(8) << " ";
std::cout<<matrix.SumParallel(16) << " ";
std::cout<<matrix.SumParallel(100) << " ";
std::cout<<matrix.Sum() << " ";
}
