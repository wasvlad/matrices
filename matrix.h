#pragma once

#include<vector>
#include<string>
#include<iostream>
#include"vector.h"
#include<exception>

namespace wvl{

class ConvertingToMatrixException : public std::exception {
    public:
		ConvertingToMatrixException(std::string message){
			std::cerr << message << '\n';
		}
std::string what () {
        return "Error converting to matrix, please check that your data can be converted to Math_Matrix";
    }
};

class MatrixConstructorException : public std::exception {
    public:
		MatrixConstructorException(std::string message){
			std::cerr << message << '\n';
		}
std::string what () {
        return "Constructing matrix exception";
    }
};

class MatrixIndexException{
	public:
		MatrixIndexException(std::string message){
			std::cerr << message << '\n';
		}
std::string what () {
        return "Matrix index out of range";
    }
};

class MatrixDifferentDimensionException{
	public:
		MatrixDifferentDimensionException(std::string message){
			std::cerr << message << '\n';
		}
std::string what () {
        return "Can't process operations between different dimensions";
    }
};

template <class number>
class Math_Matrix: public VectorBlocker
{
private:
	bool allow_block = false;
	int m,n;
	std::vector<Math_Vector<number> > mas;
	void block_all()
	{
		for(int i = 0; i < n; i++)
		{
			block(mas[i]);
		}
	}
	void unblock_all()
	{
		for(int i = 0; i < n; i++)
		{
			unblock(mas[i]);
		}
	}
public:
	vector<vector<number> > get()
	{
		vector<vector<number> > res(m);
		for(int j = 0; j < m; j++)
		{
			res[j].resize(n);
			for(int i = 0; i < n; i++)
			{
				res[j][i] = mas[i][j];
			}
		}
		return res;
	}

	Math_Matrix(vector<vector<number> > &mas)
	{
		this -> m = mas.size();
		this -> n = mas[0].size();
		for(int i = 0; i < m; i++)
		{
			if(mas[i].size() != n)
			{
				throw MatrixConstructorException("Given data doesn't have the same dimensions.");
			}
		}
		this -> mas.resize(n);
		for(int i = 0; i < n; i++)
		{
			this -> mas[i] = Math_Vector<number>(m);
			for(int j = 0; j < m; j++)
			{
				this -> mas[i][j] = mas[j][i];
			}
		}
		block_all();
	}

	Math_Matrix(int m, int n)
	{
		if(m < 0 || n < 0)throw MatrixConstructorException("Matrix dimensionality can't be smaller than 0.");
		this -> m = m;
		this -> n = n;
		mas.resize(n);
		for(int i = 0; i < n; i++)
		{
			mas[i] = Math_Vector<number>(m);
		}
		block_all();
	}

	Math_Matrix()
	{
		this -> m = 0;
		this -> n = 0;
		mas.resize(n);
		for(int i = 0; i < n; i++)
		{
			mas[i] = Math_Vector<number>(m);
		}
		block_all();
	}

	Math_Matrix(pair<int, int> mn)
	{
		if(mn.first < 0 || mn.second < 0)throw MatrixConstructorException("Matrix dimensionality can't be smaller than 0.");
		this -> m = mn.first;
		this -> n = mn.second;
		mas.resize(n);
		for(int i = 0; i < n; i++)
		{
			mas[i] = Math_Vector<number>(m);
		}
		block_all();
	}

	Math_Matrix(vector<Math_Vector<number>> &vectors)
	{
		n = vectors.size();
		m = vectors[0].get_dimensions();
		for(int i = 1; i < n; i++)
		{
			if (vectors[i].get_dimensions() != m)
				throw MatrixConstructorException("Can't construct matrix from vectors with different dimensions.");
		}
		mas = vectors;
		block_all();
	}

	Math_Matrix(Math_Vector<number> vector)
	{
		n = 1;
		m = vector.get_dimensions();
		mas.push_back(vector);
		block_all();
	}

	Math_Vector<number>& operator[](int index)
	{
		if(index >= mas.size())throw MatrixIndexException("Matrix index out of range");
		if(index < 0)throw MatrixIndexException("Index can't be smaller than 0");
		return mas[index];
	}

	vector<Math_Vector<number> > get_vectors()
	{
		return mas;
	}

	int get_n()
	{
		return n;
	}

	int get_m()
	{
		return m;
	}

	template <class number2>
	Math_Matrix<number> operator +(number2 b)
	{
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			c.mas[i] += b;
		}
		return c;
	}

	Math_Matrix<number> operator +(Math_Vector<number> b)
	{
		if(b.size() != m)throw MatrixDifferentDimensionException("Can't add vector cause dimension of vector is not eqaul to m");
		Math_Matrix<number> c = *this;
		c.mas.push_back(b);
		block(mas[n]);
		c.n++;
		return c;
	}

	Math_Matrix<number> operator +(Math_Matrix<number> b)
	{
		if(b.m != m || b.n != n)throw MatrixDifferentDimensionException("Can't sum matrixes with different dimensions");
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			c.mas[i] += b.mas[i];
		}
		return c;
	}

	template <class number2>
	Math_Matrix& operator +=(number2 b)
	{
		for(int i = 0; i < n; i++)
		{
			mas[i] += b;
		}
		return *this;
	}

	Math_Matrix& operator +=(Math_Vector<number> b)
	{
		if(b.size() != m)throw MatrixDifferentDimensionException("Can't add vector cause dimension of vector is not eqaul to m");
		mas.push_back(b);
		block(mas[n]);
		n++;
		return *this;
	}

	Math_Matrix& operator +=(Math_Matrix<number> b)
	{
		if(b.m != m || b.n != n)throw MatrixDifferentDimensionException("Can't sum matrixes with different dimensions");
		for(int i = 0; i < n; i++)
		{
			mas[i] += b.mas[i];
		}
		return *this;
	}

	template <class number2>
	Math_Matrix<number> operator -(number2 b)
	{
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			c.mas[i] -= b;
		}
		return c;
	}

	Math_Matrix<number> operator -(Math_Matrix<number> b)
	{
		if(b.m != m || b.n != n)throw MatrixDifferentDimensionException("Can't substract matrixes with different dimensions");
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			c.mas[i] -= b.mas[i];
		}
		return c;
	}

	Math_Matrix operator -()
	{
		Math_Matrix<number> c = *this;
		for(int i = 0; i < c.get_n(); i++)
		{
			c[i] = -c[i];
		}
		return c;
	}

	template <class number2>
	Math_Matrix& operator -=(number2 b)
	{
		for(int i = 0; i < n; i++)
		{
			mas[i] -= b;
		}
		return *this;
	}

	Math_Matrix& operator -=(Math_Matrix<number> b)
	{
		if(b.m != m || b.n != n)throw MatrixDifferentDimensionException("Can't substract matrixes with different dimensions");
		for(int i = 0; i < n; i++)
		{
			mas[i] -= b.mas[i];
		}
		return *this;
	}

	template <class number2>
	Math_Matrix operator *(number2 a)
	{
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			c.mas[i] *= a;
		}
		return c;
	}

	Math_Matrix operator *(Math_Matrix<number> b)
	{
		if(b.m != m || b.n != n)throw MatrixDifferentDimensionException("Can't multiply element by element matrixes with different dimensions");
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			c.mas[i] *= b.mas[i];
		}
		return c;
	}

	template <class number2>
	Math_Matrix& operator *=(number2 a)
	{
		for(int i = 0; i < n; i++)
		{
			mas[i] *= a;
		}
		return *this;
	}

	Math_Matrix& operator *=(Math_Matrix<number> b)
	{
		if(b.m != m || b.n != n)throw MatrixDifferentDimensionException("Can't multiply element by element matrixes with different dimensions");
		for(int i = 0; i < n; i++)
		{
			mas[i] *= b.mas[i];
		}
		return *this;
	}

	template <class number2>
	Math_Matrix operator /(number2 a)
	{
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			c.mas[i] /= a;
		}
		return c;
	}

	Math_Matrix operator /(Math_Matrix<number> b)
	{
		if(b.m != m || b.n != n)throw MatrixDifferentDimensionException("Can't divide element by element matrixes with different dimensions");
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			c.mas[i] /= b.mas[i];
		}
		return c;
	}

	template <class number2>
	Math_Matrix& operator /=(number2 a)
	{
		for(int i = 0; i < n; i++)
		{
			mas[i] /= a;
		}
		return *this;
	}

	Math_Matrix& operator /=(Math_Matrix<number> b)
	{
		if(b.m != m || b.n != n)throw MatrixDifferentDimensionException("Can't divide element by element matrixes with different dimensions");
		for(int i = 0; i < n; i++)
		{
			mas[i] /= b.mas[i];
		}
		return *this;
	}

	Math_Matrix operator ++()
	{
		for(int i = 0; i < n; i++)
		{
			mas[i]++;
		}
		return *this;
	}

	Math_Matrix operator ++(int)
	{
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			mas[i]++;
		}
		return c;
	}

	Math_Matrix operator --()
	{
		for(int i = 0; i < n; i++)
		{
			mas[i]--;
		}
		return *this;
	}

	Math_Matrix operator --(int)
	{
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			mas[i]--;
		}
		return c;
	}

	Math_Matrix& operator =(Math_Matrix<number> b)
	{
		mas = b.mas;
		m = b.m;
		n = b.n;
		block_all();
		return *this;
	}

	Math_Matrix& operator =(vector<vector<number> > &mas)
	{
		this -> m = mas.size();
		this -> n = mas[0].size();
		for(int i = 0; i < m; i++)
		{
			if(mas[i].size() != n)
			{
				throw MatrixDifferentDimensionException("Can't create matrix from arrays with different number of elements");
			}
		}
		this -> mas.resize(n);
		for(int i = 0; i < n; i++)
		{
			this -> mas[i] = Math_Vector<number>(m);
			for(int j = 0; j < m; j++)
			{
				this -> mas[i][j] = mas[j][i];
			}
		}
		return *this;
	}

	Math_Matrix& operator =(vector<Math_Vector<number>> &vectors)
	{
		n = vectors.size();
		m = vectors[0].get_dimensions();
		for(int i = 0; i < n; i++)
		{
			if (vectors[i].get_dimensions() != m)
				throw MatrixDifferentDimensionException("Can't create matrix from vectors with different dimensions");
		}
		mas = vectors;
		return *this;
	}

	void transpose()
	{
		unblock_all();
		Math_Matrix<number> c(n, m);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				c.mas[j][i] = mas[i][j];
			}
		}
		mas = c.mas;
		n = c.n;
		m = c.m;
		block_all();
	}

	Math_Matrix transposed()
	{
		Math_Matrix<number> c(n, m);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				c.mas[j][i] = mas[i][j];
			}
		}
		return c;
	}

	Math_Vector<number> pop_back()
	{
		if(n == 0) throw MatrixIndexException("Can't delete vector cause matrix is empty");
		Math_Vector<number> del = mas[n - 1];
		mas.pop_back();
		n--;
		return del;
	}

	void swap_columns(int i, int j)
	{
		if(i < 0 || j < 0 || i >= n || j >= n) throw MatrixIndexException("Can't swap columns, index is out of range");
		swap(mas[i], mas[j]);
	}

	void swap_rows(int i, int j)
	{
		if(i < 0 || j < 0 || i >= m || j >= m) throw MatrixIndexException("Can't swap rows, index is out of range");
		for(int z = 0; z < n; z++)
		{
			swap(mas[z][i], mas[z][j]);
		}
	}

	void add_rows(Math_Matrix<number> b)
	{
		unblock_all();
		if(b.n != n) throw MatrixDifferentDimensionException("Can't add matrix which n is different.");
		for(int i = 0; i < n; i++)
		{
			mas[i].concatenate(b[i]);
		}
		m += b.m;
		block_all();
	}

	void add_row(Math_Vector<number> b)
	{
		unblock_all();
		if(b.get_dimensions() != n)throw MatrixDifferentDimensionException("Can't add vector as row cause it dimension isn't equal n");
		for(int i = 0; i < n; i++)
		{
			mas[i].push_back(b[i]);
		}
		m++;
		block_all();
	}

	void add_columns(Math_Matrix<number> b)
	{
		if(b.m != m)throw MatrixDifferentDimensionException("Can't add columns cause added matrix has different m");
		for(int i = 0; i < b.n; i++)
		{
			mas.push_back(b.mas[i]);
		}
		n += b.n;
	}

	void convert_elements(number (*f)(number))
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i].convert_elements(f);
		}
	}

	Math_Matrix<number> converted_elements(number (*f)(number))
	{
		Math_Matrix<number> c = *this;
		for(int i = 0; i < c.n; i++)
		{
			c.mas[i].convert_elements(f);
		}
		return c;
	}

	bool isEqual(Math_Matrix<number> &b)
	{
		return mas == b.mas;
	}

	bool operator ==(Math_Matrix<number> b)
	{
		return isEqual(b);
	}

	bool operator !=(Math_Matrix<number> b)
	{
		return !isEqual(b);
	}

	Math_Matrix dot(Math_Matrix<number> b)
	{
		if(n != b.m)throw MatrixDifferentDimensionException("Can't dot matrixes cause first matrix's n must be equal second matrix's m");
		Math_Matrix<number> c(m, b.n);
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < b.n; j++)
			{
				for(int k = 0; k < n; k++)
				{
					c.mas[j][i] += mas[k][i] * b.mas[j][k];
				}
			}
		}
		return c;
	}

	/*static Math_Matrix dot(Math_Matrix<number> a, Math_Matrix<number> b)
	{
		//if(a.n != b.m)throw WrongDimensionException();
		Math_Matrix<number> c(a.m, b.n);
		for(int i = 0; i < a.m; i++)
		{
			for(int j = 0; j < b.n; j++)
			{
				for(int k = 0; k < a.n; k++)
				{
					c.mas[j][i] += a.mas[k][i] * b.mas[j][k];
				}
			}
		}
		return c;
	}*/

	number det0()
	{
		if(n != m)throw MatrixDifferentDimensionException("Can't find determinant cause matrix isn't square matrix");
		Math_Matrix<number> c = *this;
		number res = 1;
		for(int j = 0; j < m; j++)
		{
			for(int i = j + 1; i < n; i++)
			{
				if(c.mas[i][j] == 0)continue;
				if(c.mas[j][j] == 0)
				{
					c.mas[j] += c.mas[i];
				}
				number d = c.mas[i][j] / c.mas[j][j];
				c.mas[i] -= c.mas[j] * d;
				c.mas[i][j] = 0;
			}
			res *= c.mas[j][j];
		}
		return res;
	}

	number det1()
	{
		if(n != m)throw MatrixDifferentDimensionException("Can't find determinant cause matrix isn't square matrix");
		Math_Matrix<number> c = *this;
		number res = 1;
		number mn = 1;
		for(int j = 0; j < m; j++)
		{
			for(int i = j + 1; i < n; i++)
			{
				if(c.mas[i][j] == 0)continue;
				if(c.mas[j][j] == 0)
				{
					c.mas[j] += c.mas[i];
				}
				number gcd = __gcd(c.mas[i][j], c.mas[j][i]);
				mn *= c.mas[j][j] / gcd;
				c.mas[i] *= c.mas[j][j] / gcd;
				int d = c.mas[i][j] / c.mas[j][j];
				c.mas[i] -= c.mas[j] * d;
			}
			res *= c.mas[j][j];
		}
		return res / mn;
	}

};

template <class number>
std::ostream& operator<<(std::ostream& os, Math_Matrix<number> obj)
{
	os << obj.get_m() << " " << obj.get_n() << "\n";
	for(int j = 0; j < obj.get_m(); j++)
	{
		for(int i = 0; i < obj.get_n(); i++)
		{
			os << obj[i][j] << ' ';
		}
		os << '\n';
	}
	return os;
}

template <class number>
std::istream& operator>>(std::istream& os, Math_Matrix<number> &obj)
{
	int m, n;
	os >> m >> n;
	obj = Math_Matrix<number>(m, n);
	for(int j = 0; j < m; j++)
	{
		for(int i = 0; i < n; i++)
		{
			os >> obj[i][j];
		}
	}
	return os;
}

template <class number, class number2>
Math_Matrix<number> operator +(number2 &b, Math_Matrix<number> &a)
{
	Math_Matrix<number> c = a + b;
	return c;
}

template <class number, class number2>
Math_Matrix<number> operator *(number2 b, Math_Matrix<number> a)
{
	return a * b;
}


}