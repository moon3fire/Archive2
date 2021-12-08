#pragma once
#include <iostream>
#include <vector>
#include <pthread.h>


class ParallelMatrix {
public:
ParallelMatrix(int , int);
int Sum();
int SumParallel(int);
void* sum_runner();
int get_lenght() const;
int get_width() const;
void Init();
static void* sum_runner_helper(void*); // runs sum_runner in thread 
private:
std::vector<std::vector<int>> matrix;
int lenght;
int width;
int sum_of_matrix; //thread
int thread_count;
int flag1;
int flag2;
};
