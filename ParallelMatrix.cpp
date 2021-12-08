#include "ParallelMatrix.h"
	ParallelMatrix::ParallelMatrix(int lenght_ , int width_)
:lenght(lenght_)
,width(width_)
,sum_of_matrix(0)
,thread_count(0)
,flag1(0)
,flag2(0)
,matrix(lenght_ , std::vector<int>(width_))
	{
		Init();
	}

	void ParallelMatrix::Init()
	{
		for(int i = 0 ; i < lenght ; ++i)
		{
			for(int j = 0 ; j < width ; ++j)
				matrix[i][j] = rand() % 100;
		}
	}

	int ParallelMatrix::Sum()
	{
	sum_of_matrix = 0;
		for(int i = 0 ; i < this->lenght ; ++i)
	{
			for(int j = 0 ; j < this->width ; ++j)
			{
				sum_of_matrix+=matrix[i][j];
			}
	}
	return sum_of_matrix;
	}

	int ParallelMatrix::SumParallel(int sum_of_threads)
	{
	thread_count = 0;
	std::vector<int> sums(sum_of_threads);
	flag1 = 0;
	flag2 = lenght*width/sum_of_threads;
	while(thread_count != sum_of_threads)
	{
	sum_of_matrix = 0;
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid , &attr , &ParallelMatrix::sum_runner_helper , this);
	pthread_join(tid , NULL);
	++thread_count;
	sums.push_back(sum_of_matrix);
	flag1 = flag2;
	flag2 = lenght * width * (thread_count + 1) / sum_of_threads;
	}
	thread_count = 0;
	int answer = 0;
	for(int i = 0 ; i < sums.size() ; ++i)
	{
		answer+=sums[i];
	}
		return answer;
	}

	void* ParallelMatrix::sum_runner()
	{
	for(int i = flag1 ; i < flag2 ; ++i)
	{
		sum_of_matrix += matrix[i / width][i % width];
	}
	pthread_exit(0);
	}

	int ParallelMatrix::get_lenght() const
	{
		return lenght;
	}

	int ParallelMatrix::get_width() const
	{
		return width;
	}
	
	void* ParallelMatrix::sum_runner_helper(void* ptr)
	{
		return ((ParallelMatrix*)ptr)->sum_runner();
	}
	
