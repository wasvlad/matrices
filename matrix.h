#pragma once

#include<bits/stdc++.h>
#include"vector.h"
#include<exception>

using namespace std;

class ConvertingToMatrixException : public std::exception {
    public:
char * what () {
        return "Error converting to matrix, please check that your data can be converted to Math_Matrix";
    }
};

template <class number>
class Math_Matrix{
private:
	int m,n;
	vector<Math_Vector<number> > mas;
public:
	Math_Vector<number> get_column(int i)
	{
		if(i >= n)throw out_of_range("column index out of range");
		return mas[i];
	}
	number get(int j, int i)
	{
		if(j >= m || i >= n)
			throw out_of_range("matrix index out of range");
		return mas[i][j];
	}
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
	vector<Math_Vector<number> > get_vectors()
	{
		return mas;
	}
	Math_Matrix(int m, int n)
	{
		if(m <= 0 || n < 0)throw WrongDimensionException();
		this -> m = m;
		this -> n = n;
		mas.resize(n);
		for(int i = 0; i < n; i++)
		{
			mas[i] = Math_Vector<number>(m);
		}
	}

	Math_Matrix()
	{
		this -> m = 2;
		this -> n = 2;
		mas.resize(2);
		for(int i = 0; i < n; i++)
		{
			mas[i] = Math_Vector<number>(2);
		}
	}

	Math_Matrix(pair<int, int> mn)
	{
		if(mn.first <= 0 || mn.second < 0)throw WrongDimensionException();
		this -> m = mn.first;
		this -> n = mn.second;
		mas.resize(n);
		for(int i = 0; i < n; i++)
		{
			mas[i] = Math_Vector<number>(m);
		}
	}

	Math_Matrix(vector<vector<number> > &mas)
	{
		this -> m = mas.size();
		this -> n = mas[0].size();
		for(int i = 0; i < m; i++)
		{
			if(mas[i].size() != n)
			{
				throw ConvertingToMatrixException();
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
	}

	Math_Matrix(vector<Math_Vector<number>> &vectors)
	{
		n = vectors.size();
		m = vectors[0].get_dimensions();
		for(int i = 0; i < n; i++)
		{
			if (vectors[i].get_dimensions() != m)
				throw ConvertingToMatrixException();
		}
		mas = vectors;
	}

	Math_Matrix(int n, Math_Vector<number> vectors[])
	{
		this -> n = n;
		m = vectors[0].get_dimensions();
		for(int i = 0; i < n; i++)
		{
			if (vectors[i].get_dimensions() != m)
				throw ConvertingToMatrixException();
		}
		mas.resize(n);
		for(int i = 0; i < n; i++)
		{
			mas[i] = vectors[i];
		}
	}

	Math_Matrix& operator =(Math_Matrix<number> b)
	{
		mas = b.mas;
		m = b.m;
		n = b.n;
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
				cout<<mas[i].size()<<'\n';
				throw ConvertingToMatrixException();
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
				throw ConvertingToMatrixException();
		}
		mas = vectors;
		return *this;
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

	void set(int j, int i, number a)
	{
		if(j < 0 || j >= m || i < 0 || i >= n){
			throw OutOfDimensionsException();
		}
		mas[i][j] = a;
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
		if(b.get_dimensions() != m)throw WrongDimensionException();
		Math_Matrix<number> c = *this;
		c.mas.push_back(b);
		c.n++;
		return c;
	}

	Math_Matrix<number> operator +(Math_Matrix<number> b)
	{
		if(b.m != m || b.n != n)throw WrongDimensionException();
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
		if(b.get_dimensions() != m)throw WrongDimensionException();
		mas.push_back(b);
		n++;
		return *this;
	}

	Math_Matrix& operator +=(Math_Matrix<number> b)
	{
		if(b.m != m || b.n != n)throw WrongDimensionException();
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
		if(b.m != m || b.n != n)throw WrongDimensionException();
		Math_Matrix<number> c = *this;
		for(int i = 0; i < n; i++)
		{
			c.mas[i] -= b.mas[i];
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
		if(b.m != m || b.n != n)throw WrongDimensionException();
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

	template <class number2>
	Math_Matrix& operator *=(number2 a)
	{
		for(int i = 0; i < n; i++)
		{
			mas[i] *= a;
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

	template <class number2>
	Math_Matrix& operator /=(number2 a)
	{
		for(int i = 0; i < n; i++)
		{
			mas[i] /= a;
		}
		return *this;
	}

	Math_Matrix operator *(Math_Matrix<number> b)
	{
		if(n != b.m)throw WrongDimensionException();
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

	Math_Matrix transpose()
	{
		Math_Matrix<number> c(n, m);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				c.mas[j][i] = mas[i][j];
			}
		}
		mas = c.mas;
		return c;
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

	number det0()
	{
		if(n != m)throw WrongDimensionException();
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
		if(n != m)throw WrongDimensionException();
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

	Math_Vector<number> pop_back()
	{
		Math_Vector<number> del = mas[n - 1];
		mas.pop_back();
		n--;
		return del;
	}

	void SwapColumns(int i, int j)
	{
		swap(mas[i], mas[j]);
	}

	void SwapRows(int i, int j)
	{
		for(int z = 0; z < n; z++)
		{
			swap(mas[z][i], mas[z][j]);
		}
	}

	void add_Rows(Math_Matrix<number> b)
	{
		if(b.n != n)throw WrongDimensionException();
		for(int i = 0; i < n; i++)
		{
			mas[i].concatenate(b.get_column(i));
		}
		m += b.m;
	}

	void add_Rows(Math_Vector<number> b)
	{
		if(b.get_dimensions() != n)throw WrongDimensionException();
		for(int i = 0; i < n; i++)
		{
			mas[i].push_back(b[i]);
		}
		m++;
	}

	void add_Columns(Math_Matrix<number> b)
	{
		if(b.m != m)throw WrongDimensionException();
		for(int i = 0; i < b.n; i++)
		{
			mas.push_back(b.mas[i]);
		}
		n += b.n;
	}

	template <class number2>
	friend std::ostream& operator<<(std::ostream& os, Math_Matrix<number2> obj);
};

template <class number>
std::ostream& operator<<(std::ostream& os, Math_Matrix<number> obj)
{
	os << "Matrix " << obj.get_m() << "x" << obj.get_n() << "\n";
	for(int i = 0; i < obj.get_m(); i++)
	{
		for(int j = 0; j < obj.get_n(); j++)
		{
			os << obj.get(i, j) << ' ';
		}
		os << '\n';
	}
	return os;
}