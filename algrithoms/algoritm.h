#pragma once
#include<vector>
#define SWAP(a,b){a = a^b; b = a^b; a = a^b;}

template<typename T>
struct s_point {
	T m_x;
	T m_y;
	s_point(T x, T y) :m_x(x), m_y(y) {};
};
template<typename T>
void swap(T a, T b) {
	a = a^b; b = a^b; a = a^b;
}

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

//template<typename T>
//void swap(T* &vec, size_t i, size_t j) {
//	T temp = vec[i];
//	vec[i] = vec[j];
//	vec[j] = temp;
//}
//
//template<typename T>
//void swap(T i, T j) {
//	T temp = i;
//	i = j;
//	j = temp;
//}

template<typename T>
void quick_sort(T * vec, size_t n, size_t i, size_t j) {
	size_t temp = i;
	size_t index = j;
	std::cout << i << "------" << j << std::endl;
	T ref = vec[temp];
	if (i >=j) return;
	while (i < j) {
		while (i<j && vec[j] >= ref) j--;
		while (i<j && vec[i] < ref) i++;
		
		if (i != j) {
			std::cout << i << "<->" << j << std::endl;
			SWAP(vec[i], vec[j]);
			for (size_t k = 0; k < n; k++)
				std::cout << vec[k] << " ";
			std::cout << std::endl;
		}
	}
	if (temp != j)
	{
		std::cout << temp << "<->" << j << std::endl;
		//swap(vec, temp, j);
		SWAP(vec[temp], vec[j]);
	}
	for (size_t k = 0; k < n; k++)
		std::cout << vec[k] << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	quick_sort(vec, n, temp, i);
	quick_sort(vec, n, j+1, index);
}


template<typename T>
void quick_sort(std::vector<s_point<T>> &vec, size_t n, size_t i, size_t j) {
	size_t temp = i;
	size_t index = j;
	std::cout << i << "------" << j << std::endl;
	T ref = vec[temp].m_x;
	if (i >= j) return;
	while (i < j) {
		while (i<j && vec[j].m_x >= ref) j--;
		while (i<j && vec[i].m_x < ref) i++;

		if (i != j) {
			std::cout << i << "<->" << j << std::endl;
			SWAP(vec[i].m_x, vec[j].m_x);
			SWAP(vec[i].m_y, vec[j].m_y);
			for (size_t k = 0; k < n; k++)
				std::cout << vec[k].m_x << " ";
			std::cout << std::endl;
		}
	}
	if (temp != j)
	{
		std::cout << temp << "<->" << j << std::endl;
		//swap(vec, temp, j);
		SWAP(vec[temp].m_x, vec[j].m_x);
		SWAP(vec[temp].m_y, vec[j].m_y);
	}
	for (size_t k = 0; k < n; k++)
		std::cout << vec[k].m_x << " ";
	std::cout << std::endl;
	std::cout << std::endl;
	quick_sort(vec, n, temp, i);
	quick_sort(vec, n, j + 1, index);
}


template<typename T>
void divise(T *& vec , int l, int r, T *& result) {
	if (l < r)

	{	
		int mid = (l + r) / 2;		
		divise(vec, l, mid, result);
		divise(vec, mid + 1, r, result);	
		merge(vec, l, mid, r, result);
	}
	else
		return;
}

template<typename T>
void merge(T *& vec, int l,int mid, int r, T *& result) {
	int m = l;
	int n = mid + 1;
	int temp = l;
	while (m <= mid && n <= r) {
		if (vec[m] < vec[n])
			result[temp++] = vec[m++];
		else
			result[temp++] = vec[n++];
	}
	while (m <= mid)
		result[temp++] = vec[m++];
	while (n <= r)
		result[temp++] = vec[n++];
	temp = l;
	while (l <= r)
		vec[l++] = result[temp++];
}

template<typename T>
void merge_sort(T * vec, int n) {
	T * result = new T[n];
	divise(vec, 0, n-1, result);
}


template<typename T>
void divise(std::vector<s_point<T>> &vec, size_t begin, size_t end) {

}

template<typename T>
void clost_pair(std::vector<s_point<T>> & vec) {
	size_t size = vec.size();

	divise(vec, 0, size - 1);
}