#pragma ocne
#include<iostream>
#include"algoritm.h"

template<typename T>
void show_vec(const T* vec,const size_t rows,const size_t cols) {
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

	int vec[14] = { 2,5,3,6,1,7,8,2,4,23,65,4,3 ,0};
	for(int i =0;i<14;i++)
	std::cout << vec[i] << " ";
	std::cout << std::endl;
	quick_sort<int>(vec, 14, 0, 13);

}