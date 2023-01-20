#pragma once

#include<bits/stdc++.h>
#include<exception>
using namespace std;

namespace wvl{

class VectorConstructorException : public std::exception{
	public:
		VectorConstructorException(string message){
			cerr << message << '\n';
		}
string what () {
        return "Error constructing vector";
    }
};

class VectorDifferentDimensionsException : public std::exception{
	public:
		VectorDifferentDimensionsException(string message){
			cerr << message << '\n';
		}
string what () {
        return "Vectors have different dimensions";
    }
};

class VectorFixedSizeException : public std::exception{
	public:
		VectorFixedSizeException(string message){
			cerr << message << '\n';
		}
string what () {
        return "Error, can't change number of dimensions. This vector has fixed dimension.";
    }
};

class VectorOutOfRange : public std::exception{
	public:
		VectorOutOfRange(string message){
			cerr << message << '\n';
		}
string what () {
        return "Error, out of dimensions";
    }
};


class VectorException: public std::exception{
	public:
		VectorException(string message){
			cerr << message << '\n';
		}
string what () {
        return "Vector exception";
    }
};



template <class number>
class Math_Vector{
private:
	vector<number> mas;
protected:
	bool fixed_size = false;
public:
	bool operator ==(Math_Vector<number> b)
	{
		return mas == b.mas;
	}

	Math_Vector()
	{
		mas.resize(0);
	}
	Math_Vector(int d)
	{
		if(d < 0)
		{
			throw VectorConstructorException("EXCEPTION: Vector dimension can't be smaller than 0");
		}
		mas.resize(d);
		//dim = d;
	}
	Math_Vector(vector<number> &mas)
	{
		this -> mas = mas;
	}

	vector<number> get()
	{
		return mas;
	}

	Math_Vector& operator =(Math_Vector<number> b)
	{
		if(this -> fixed_size && b.mas.size() != mas.size())throw VectorFixedSizeException("EXCEPTION: Can't change dimensionality of vector.");
		mas = b.mas;
		return *this;
	}

	Math_Vector& operator =(vector<number> b)
	{
		if(this -> fixed_size && b.size() != mas.size())throw VectorFixedSizeException("EXCEPTION: Can't change dimensionality of vector.");
		mas = b;
		return *this;
	}

	void push_back(number a)
	{
		if(this -> fixed_size)throw VectorFixedSizeException("EXCEPTION: Can't change dimensionality of vector.");
		mas.push_back(a);
	}

	void pop_back()
	{
		if(this -> fixed_size)throw VectorFixedSizeException("EXCEPTION: Can't change dimensionality of vector.");
		if(mas.size() == 0) throw VectorOutOfRange("EXCEPTION: can't delete element");
		mas.pop_back();
	}

	number& operator[](int index)
	{
		if(index >= mas.size() || index < 0)throw VectorOutOfRange("EXCEPTION: operator [] can't acces element cause it doesn't exist");
		return mas[index];
	}

	void concatenate(Math_Vector<number> a)
	{
		if(this -> fixed_size)throw VectorFixedSizeException("EXCEPTION: Can't change dimensionality of vector.");
		int was = mas.size();
		mas.resize(mas.size() + a.mas.size());
		for(int i = was; i < mas.size(); i++)
		{
			mas[i] = a.mas[i - was];
		}
	}

	void concatenate(vector<number> a)
	{
		if(this -> fixed_size)throw VectorFixedSizeException("EXCEPTION: Can't change dimensionality of vector.");
		int was = mas.size();
		mas.resize(mas.size() + a.size());
		for(int i = was; i < mas.size(); i++)
		{
			mas[i] = a[i - was];
		}
	}

	void erase(int i){
		if(this -> fixed_size)throw VectorFixedSizeException("EXCEPTION: Can't change dimensionality of vector.");
		if(i >= mas.size() || i < 0)throw VectorOutOfRange("EXCEPTION: erase can't access element cause it doesn't exist");
		mas.erase(mas.begin() + i);
	}

	/*void erase(int i, int j)
	{
		if(this -> fixed_size)throw VectorFixedSizeException("EXCEPTION: Can't change dimensionality of vector.");
		if(i > j) throw VectorException("EXCEPTION: Can't erase elemets from i to j cause i > j");
		if(i >= mas.size() || i < 0 || j >= mas.size() || j < 0)throw VectorOutOfRange("EXCEPTION: erase can't access element cause it doesn't exist");
		mas.erase(mas.begin() + i, mas.begin() + j);
	}*/

	Math_Vector operator +(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't sum vectors with different dimensions");
		Math_Vector<number> c(mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c.mas[i] = mas[i] + b.mas[i];
		}
		return c;
	}

	template <class number2>
	Math_Vector operator +(number2 b)
	{
		Math_Vector<number> c(this -> mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c.mas[i] = mas[i] + b;
		}
		return c;
	}

	Math_Vector& operator +=(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't sum vectors with different dimensions");
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] += b.mas[i];
		}
		return *this;
	}

	template <class number2>
	Math_Vector& operator +=(number2 b)
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] += b;
		}
		return *this;
	}

	Math_Vector operator -(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't substract vectors with different dimensions");
		Math_Vector<number> c(mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c.mas[i] = mas[i] - b.mas[i];
		}
		return c;
	}

	template <class number2>
	Math_Vector operator -(number2 b)
	{
		Math_Vector<number> c(this -> mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c.mas[i] = mas[i] - b;
		}
		return c;
	}

	Math_Vector<number> operator -()
	{
		Math_Vector<number> c = *this;
		for(int i = 0; i < mas.size(); i++)
		{
			c.mas[i] = -mas[i];
		}
		return c;
	}

	Math_Vector& operator -=(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't substract vectors with different dimensions");
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] -= b.mas[i];
		}
		return *this;
	}

	template <class number2>
	Math_Vector& operator -=(number2 b)
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] -= b;
		}
		return *this;
	}

	Math_Vector operator ++()
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i]++;
		}
		return *this;
	}

	Math_Vector operator ++(int)
	{
		Math_Vector<number> c = *this;
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i]++;
		}
		return c;
	}

	Math_Vector operator --()
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i]--;
		}
		return *this;
	}

	Math_Vector operator --(int)
	{
		Math_Vector<number> c = *this;
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i]--;
		}
		return c;
	}

	Math_Vector operator *(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't multiply vectors with different dimensions");
		Math_Vector<number> c(mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c[i] = mas[i] * b[i];
		}
		return c;
	}

	template<class number2>
	Math_Vector operator *(number2 b)
	{
		Math_Vector<number> c(mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c.mas[i] = mas[i] * b;
		}
		return c;
	}

	Math_Vector& operator *=(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't multiply vectors with different dimensions");
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] *= b[i];
		}
		return *this;
	}

	template<class number2>
	Math_Vector& operator *=(number2 b)
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] *= b;
		}
		return *this;
	}

	Math_Vector operator /(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't divide vectors with different dimensions");
		Math_Vector<number> c(mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c[i] = mas[i] / b[i];
		}
		return c;
	}

	template<class number2>
	Math_Vector operator /(number2 b)
	{
		Math_Vector<number> c(mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c.mas[i] = mas[i] / b;
		}
		return c;
	}

	Math_Vector& operator /=(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't divide vectors with different dimensions");
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] /= b[i];
		}
		return *this;
	}

	template<class number2>
	Math_Vector& operator %=(number2 b)
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] %= b;
		}
		return *this;
	}

	Math_Vector operator %(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't divide vectors with different dimensions");
		Math_Vector<number> c(mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c[i] = mas[i] % b[i];
		}
		return c;
	}

	template<class number2>
	Math_Vector operator %(number2 b)
	{
		Math_Vector<number> c(mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c.mas[i] = mas[i] % b;
		}
		return c;
	}

	Math_Vector& operator %=(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't divide vectors with different dimensions");
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] %= b[i];
		}
		return *this;
	}

	template<class number2>
	Math_Vector& operator /=(number2 b)
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] /= b;
		}
		return *this;
	}

	bool isEqual(const Math_Vector<number> &b)
	{
		return mas == b.mas;
	}

	number length()
	{
		number sum = 0;
		for(auto j:mas)
		{
			sum += j * j;
		}
		return sqrt(sum);
	}

	int get_dimensions()
	{
		return mas.size();
	}

	int size()
	{
		return mas.size();
	}

	number sum()
	{
		number s = 0;
		for(auto j:mas)
			s += j;
		return s;
	}

	number dot(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw VectorDifferentDimensionsException("EXCEPTION: Can't product vectors with different dimensions");
		number c = 0;
		for(int i = 0; i < mas.size(); i++)
		{
			c += mas[i] * b[i];
		}
		return c;
	}

	Math_Vector<number> concatenated(Math_Vector<number> a)
	{
		Math_Vector<number> c;
		c.mas.resize(c.size() + a.size());
		for(int i = mas.size(); i < mas.size() + a.mas.size(); i++)
		{
			c[i] = a[i - mas.size()];
		}
		return c;
	}

	Math_Vector<number> concatenated(vector<number> a)
	{
		Math_Vector<number> c;
		c.mas.resize(mas.size() + a.size());
		for(int i = mas.size(); i < mas.size() + a.size(); i++)
		{
			c[i] = a[i - mas.size()];
		}
		return c;
	}

	void convert_elements(number (*f)(number))
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] = f(mas[i]);
		}
	}

	Math_Vector<number> converted_elements(number (*f)(number))
	{
		Math_Vector<number> c = *this;
		for(int i = 0; i < c.mas.size(); i++)
		{
			c[i] = f(c[i]);
		}
		return c;
	}

	friend class VectorBlocker;
	
};

class VectorBlocker{
protected:
	template<class number>
	void block(Math_Vector<number> &vec){
		vec.fixed_size = true;
	}

	template<class number>
	void unblock(Math_Vector<number> &vec){
		vec.fixed_size = false;
	}
};

template <class number>
bool operator ==(const Math_Vector<number>& a, const Math_Vector<number>& b)
{
	Math_Vector<number> a2 = a;
	return a2.isEqual(b);
}

template <class number>
bool operator !=(const Math_Vector<number>& a, const Math_Vector<number>& b)
{
	Math_Vector<number> a2 = a;
	return !a2.isEqual(b);
}


template <class number>
std::ostream& operator<<(std::ostream& os, Math_Vector<number> obj)
{
	os << obj.size() << "\n";
	for(int i = 0; i < obj.size(); i++)
	{
		os << obj[i] << ' ';
	}
	os << "\n";
	return os;
}

template <class number>
std::istream& operator>>(std::istream& os, Math_Vector<number> &obj)
{
	int n;
	os >> n;
	vector<number> mas(n);
	for(int i = 0; i < n; i++)
	{
		os >> mas[i];
	}
	obj = mas;
	return os;
}

template <class number,class number2>
Math_Vector<number> operator +(number2 b, Math_Vector<number> a)
{
	return a + b;
}

template <class number,class number2>
Math_Vector<number> operator *(number2 b, Math_Vector<number> a)
{
	return a * b;
}

}