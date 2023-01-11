#pragma once

#include<bits/stdc++.h>
#include<exception>
using namespace std;

class DifferentDimensionException : public std::exception {
    public:
char * what () {
        return "Operation beetwen different dimensional vectors";
    }
};

class OutOfDimensionsException : public std::exception {
    public:
char * what () {
        return "Vector don't have soo much dimensions";
    }
};
class WrongDimensionException : public std::exception{
	public:
char * what () {
        return "Wrong dimension";
    }
};

template <class number>
class Math_Vector{
private:
	vector<number> mas;
	//int dim;
public:
	Math_Vector()
	{
		mas.resize(2);
	}
	Math_Vector(int d)
	{
		if(d < 0)
		{
			throw WrongDimensionException();
		}
		mas.resize(d);
		//dim = d;
	}
	Math_Vector(vector<number> &mas)
	{
		this -> mas = mas;
		//dim = mas.size();
	}
	vector<number> get()
	{
		return mas;
	}

	Math_Vector operator +(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw DifferentDimensionException();
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
		if(mas.size() != b.mas.size())throw DifferentDimensionException();
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
		if(mas.size() != b.mas.size())throw DifferentDimensionException();
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

	Math_Vector& operator -=(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw DifferentDimensionException();
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

	Math_Vector& operator ++()
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i]++;
		}
		return *this;
	}

	Math_Vector& operator --()
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i]--;
		}
		return *this;
	}

	Math_Vector& operator =(Math_Vector<number> b)
	{
		mas = b.mas;
		return *this;
	}

	Math_Vector& operator =(vector<number> b)
	{
		mas = b;
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

	Math_Vector operator --(int)
	{
		Math_Vector<number> c = *this;
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i]--;
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

	template<class number2>
	Math_Vector& operator *=(number2 b)
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] *= b;
		}
		return *this;
	}

	bool isEqual(const Math_Vector<number> &b)
	{
		return mas == b.mas;
	}

	bool operator ==(Math_Vector<number> b)
	{
		return mas == b.mas;
	}

	bool operator !=(Math_Vector<number> b)
	{
		return mas != b.mas;
	}

	number& operator[](int index)
	{
		if(index >= mas.size())throw OutOfDimensionsException();
		return mas[index];
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

	template<class number2>
	Math_Vector& operator /=(number2 b)
	{
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] /= b;
		}
		return *this;
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

	void push_back(number a)
	{
		mas.push_back(a);
	}

	void concatenate(Math_Vector<number> b)
	{
		int was = mas.size();
		mas.resize(mas.size() + b.mas.size());
		for(int i = 0; i < b.get_dimensions(); i++)
		{
			mas[i + was] = b[i];
		}
	}

	Math_Vector operator *(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw DifferentDimensionException();
		Math_Vector<number> c(mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c[i] = mas[i] * b[i];
		}
		return c;
	}

	Math_Vector& operator *=(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw DifferentDimensionException();
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] *= b[i];
		}
		return *this;
	}

	Math_Vector operator /(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw DifferentDimensionException();
		Math_Vector<number> c(mas.size());
		for(int i = 0; i < mas.size(); i++)
		{
			c[i] = mas[i] / b[i];
		}
		return c;
	}

	Math_Vector& operator /=(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw DifferentDimensionException();
		for(int i = 0; i < mas.size(); i++)
		{
			mas[i] /= b[i];
		}
		return *this;
	}

	number dot(Math_Vector<number> b)
	{
		if(mas.size() != b.mas.size())throw DifferentDimensionException();
		number c = 0;
		for(int i = 0; i < mas.size(); i++)
		{
			c += mas[i] * b[i];
		}
		return c;
	}

	static number dot(Math_Vector<number> a, Math_Vector<number> b)
	{
		if(a.mas.size() != b.mas.size())throw DifferentDimensionException();
		number c = 0;
		for(int i = 0; i < a.mas.size(); i++)
		{
			c += a[i] * b[i];
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

	Math_Vector<number> converted_elements(number (*f)(number))
	{
		Math_Vector<number> c = *this;
		for(int i = 0; i < c.mas.size(); i++)
		{
			c[i] = f(c[i]);
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

	template <class number2>
	friend std::ostream& operator<<(std::ostream& os, Math_Vector<number2> obj);
	
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
	os << "Vector with " << obj.mas.size() << " dimensions\n";
	for(auto j:obj.mas)
	{
		os << j << ' ';
	}
	os << "\n";
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