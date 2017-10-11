#pragma once
#include<vector>

template<typename T>
void set_mat(T ** &mat, size_t rows, size_t cols) {
	mat = new T*[rows];
	for (size_t i = 0; i < rows; i++)
		mat[i] = new T[cols];
}

template<typename T>
void convert_vec_to_mat(const T* vec, T **& mat, size_t rows, size_t cols) {
	size_t index = 0;
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			mat[i][j] = vec[index++];
		}
	}
}

//template<typename T>
//void convert_vec_to_mat (const std::vector<T> vec, T **& mat, size_t rows, size_t cols) {
//	size_t index = 0;
//	for (size_t i = 0; i < rows; i++) {
//		for (size_t j = 0; j < cols; j++) {
//			mat[i][j] = vec[index++];
//		}
//	}
//}

int find_min_index(int * vec,int n) {
	int index;
	for (int i = 0; i < n; i++) {
		if (vec[i] != 0) {
			index = i;
			break;
		}
	}
	
	for (int i = n-1; i >=0; i--) {
		if (vec[i]!=0 && vec[index] >= vec[i]) {
			index = i;
		}
	}
	return index;
}
int find_min(int * vec, int n) {
	int index;
	for (int i = 0; i < n; i++) {
		if (vec[i] != 0) {
			index = i;
			break;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		if (vec[i] != 0 && vec[index] >= vec[i]) {
			index = i;
		}
	}
	return vec[index];
}

int get(int **&mat, std::vector<int> &result, std::vector<int> &rows,std::vector<int> &min_index_row,std::vector<int> &min_row,int col) {
	for (int i = 0; i < result.size(); i++) {
		int min_index = find_min_index(mat[result[i]], col);
		int min = find_min(mat[result[i]], col);
		rows.push_back(result[i]);
		min_index_row.push_back(min_index);
		min_row.push_back(min);


	}
	int ind = 0;
	for (int j = 0; j < min_row.size(); j++) {
		if (min_row[ind] > min_row[j]) {
			ind = j;
		}
		
	}
	for (int i = 0; i < result.size(); i++) {
		if (min_index_row[ind] == result[i]) {
			mat[rows[ind]][min_index_row[ind]] = 0;
			mat[min_index_row[ind]][rows[ind]] = 0;
			rows.clear();
			min_index_row.clear();
			min_row.clear();
			ind = get(mat, result, rows, min_index_row, min_row,col);
			break;
		}
	}
	return ind;
}


void prim(int **& mat, std::vector<int> &result ,int row,int col) {
	if(0==result.size()) result.push_back(0);
	if (6 == result.size()) return;
	std::vector<int> rows;
    std::vector<int> min_index_row;
	std::vector<int> min_row;
	
	int ind = get(mat, result, rows, min_index_row, min_row,col);

	mat[rows[ind]][min_index_row[ind]] = 0;
	mat[min_index_row[ind]][rows[ind]] = 0;

	std::cout << "reslut vec:";
	for (int i = 0; i < result.size(); i++) {
		std::cout << result[i] << " ";
	}
	std::cout << "\nrestet:";
	std::cout << rows[ind] << "," << min_index_row[ind] << std::endl;
	std::cout << std::endl;
	std::cout << "current mat:" << std::endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
	result.push_back(min_index_row[ind]);
	rows.clear();
	min_index_row.clear();
	min_row.clear();
	prim(mat, result,row,col);
}
