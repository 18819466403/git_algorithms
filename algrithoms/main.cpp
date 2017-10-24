#pragma ocne
#include<iostream>
#include"algoritm.h"
#include<time.h>
#include<ctime>
template<typename T>
void show_vec(const T* vec, const size_t rows, const size_t cols) {
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			//mat[i][j] = k++;
			std::cout << vec[k++] << " ";
		}
		std::cout << std::endl;
	}
}

template<typename T>
void show_mat(T** &mat, const size_t rows, const size_t cols) {
	int k = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {

	//prim算法
	//int vec[36] = { 0,6,1,5,0,0,
	//		  	    6,0,5,0,3,0,
	//			    1,5,0,5,6,4,
	//			    5,0,5,0,0,2,
	//			    0,3,6,0,0,6,
	//			    0,0,4,2,6,0 };
	////show_vec<int>(vec,6,6);
	//int **mat = NULL;
	//std::vector<int> result;
	//set_mat<int>(mat, 6, 6);
	//convert_vec_to_mat<int>(vec, mat, 6, 6);
 //  // show_mat<int>(mat, 6, 6);

	////std::cout<<find_min(vec, 36);
	//prim(mat, result,6,6);

	//std::cout << "The result:";
	//for (int i = 0; i < result.size(); i++) {
	//	std::cout << result[i] << " ";
	//}


	//quicksort算法

	/*int vec[14] = { 2,5,3,6,1,7,8,2,4,23,65,4,3 ,0 };
	for(int i =0;i<14;i++)
	std::cout << vec[i] << " ";
	std::cout << std::endl;
	quick_sort(vec, 14, 0, 13);*/


	//mergesort算法
	/*int vec[14] = { 2,5,3,6,1,7,8,2,4,23,65,4,3 ,0 };
	merge_sort(vec, 14);
	for (int i = 0; i<14; i++)
		std::cout << vec[i] << " ";*/

		//point quicksort算法

	/*std::vector<s_point<int>> vec;
	int j = 10;
	for(int i = 10; i > 0; i--){
		s_point<int> point(i,j++);
		vec.push_back(point);
     }

	quick_sort(vec, 10, 0, 9);*/


	// test three swap functions;
	//int n = 0;
	//clock_t start, finish;
	//start = clock();
	//int a = 1;
	//int b = 1;
	//int c = 1;
	//while (n < 1000000000)
	//{
	//	n++;
	//	//a = a^b; b = a^b; a = a^b;
	//	a = a + b;
	//	b = a - b;
	//	a = a - b;
 //    		
	//}
	//finish = clock();
	//std::cout << (finish - start) / CLOCKS_PER_SEC << std::endl;
	

	//closet_pair funtion
	//std::vector<s_point<int>> vec;
	//s_point<int> p1(23, 12);
	//s_point<int> p2(21, 34);
	//s_point<int> p3(4, 12);
	//s_point<int> p4(12, 2);
	//s_point<int> p5(-2, 89);
	//s_point<int> p6(75, 35);
	//s_point<int> p7(8, 1);
	//s_point<int> p8(5, 2);
	//s_point<int> p9(14, 53); 
	//s_point<int> p10(18, 32);

	//vec.push_back(p1);
	//vec.push_back(p2);
	//vec.push_back(p3);
	//vec.push_back(p4);
	//vec.push_back(p5); 
	//vec.push_back(p6);
	//vec.push_back(p7); 
	//vec.push_back(p8);
	//vec.push_back(p9);
	//vec.push_back(p10);
	///*int j = 10;
	//for (int i = 10; i > 0; i--) {
	//	s_point<int> point(i, j++);
	//	vec.push_back(point);
	//}*/
	//double d=10;
	//for(int i=0;i<10;i++)
	//	for (int j = i; j < 10; j++) {
	//		if (d >= get_point_distance(vec[i], vec[j]) && get_point_distance(vec[i], vec[j]) > 0.00001) d = get_point_distance(vec[i], vec[j]);
	//	}
	//std::cout << d << std::endl;
	//closet_pair(vec);


	int vec[36] = { 0,6,1,5,0,0,
			  	    6,0,5,0,3,0,
				    1,5,0,5,6,4,
				    5,0,5,0,0,2,
				    0,3,6,0,0,6,
				    0,0,4,2,6,0 };
	//show_vec<int>(vec,6,6);
	int **mat = NULL;
	std::vector<int> result;
	set_mat<int>(mat, 6, 6);
	convert_vec_to_mat<int>(vec, mat, 6, 6);
	deep_first_search(mat, result, 6, 6);
	  // show_mat<int>(mat, 6, 6);

}