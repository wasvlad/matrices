#include<bits/stdc++.h>
#include<WVL/matrixes/vector.h>
#include<WVL/matrixes/matrix.h>
using namespace std;
mt19937 rnd(time(0));
void test_matrixes(int &exit_code)
{
	{
		Math_Matrix<int> mat(2, 3);
		vector<vector<int>> res;
		res.resize(2);
		for(int i = 0; i < res.size(); i++)
		{
			res[i].resize(3);
		}
		if(mat.get() == res)
		{
			cout<<"matrix constructor 1 passed\n";
		}
		else
		{
			cout<<"matrix constructor 1 FAILED\n";
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat;
		vector<vector<int>> res;
		res.resize(2);
		for(int i = 0; i < res.size(); i++)
		{
			res[i].resize(2);
		}
		if(mat.get() == res)
		{
			cout<<"matrix constructor 2 passed\n";
		}
		else
		{
			cout<<"matrix constructor 2 FAILED\n";
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat(make_pair(2, 3));
		vector<vector<int>> res;
		res.resize(2);
		for(int i = 0; i < res.size(); i++)
		{
			res[i].resize(3);
		}
		if(mat.get() == res)
		{
			cout<<"matrix constructor 3 passed\n";
		}
		else
		{
			cout<<"matrix constructor 3 FAILED\n";
			exit_code = -1;
		}
	}
	{
		vector<vector<int> > res;
		vector<int> a1 = {1, 2, 3};
		vector<int> a2 = {2, 3, 4};
		res.push_back(a1);
		res.push_back(a2);
		Math_Matrix<int> mat(res);
		if(mat.get() == res)
		{
			cout<<"matrix constructor 4 passed\n";
		}
		else
		{
			cout<<"matrix constructor 4 FAILED\n";
			exit_code = -1;
		}
	}
	{
		vector<Math_Vector<int> > res;
		Math_Vector<int> a1(3);
		a1[0] = 2;
		Math_Vector<int> a2(3);
		a2[2] = 3;
		res.push_back(a1);
		res.push_back(a2);
		Math_Matrix<int> mat(res);
		if(mat.get_vectors() == res)
		{
			cout<<"matrix constructor 5 passed\n";
		}
		else
		{
			cout<<"matrix constructor 5 FAILED\n";
			exit_code = -1;
		}
	}
	{
		vector<Math_Vector<int> > res;
		Math_Vector<int> a1(3);
		a1[0] = 2;
		Math_Vector<int> a2(3);
		a2[2] = 3;
		res.push_back(a1);
		res.push_back(a2);
		Math_Vector<int> mas[2];
		mas[0] = a1;
		mas[1] = a2;
		Math_Matrix<int> mat(2, mas);
		if(mat.get_vectors() == res)
		{
			cout<<"matrix constructor 6 passed\n";
		}
		else
		{
			cout<<"matrix constructor 6 FAILED\n";
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> res(3, 6);
		Math_Matrix<int> mat(3, 1);
		mat = res;
		if(mat.get_vectors() == res.get_vectors())
		{
			cout<<"matrix = matrix passed\n";
		}
		else
		{
			cout<<"matrix = matrix FAILED\n";
			exit_code = -1;
		}
	}
	{
		vector<vector<int> > res;
		vector<int> a1 = {1, 2, 3};
		vector<int> a2 = {2, 3, 4};
		res.push_back(a1);
		res.push_back(a2);
		Math_Matrix<int> mat(5, 7);
		mat = res;
		if(mat.get() == res)
		{
			cout<<"matrix = arrays passed\n";
		}
		else
		{
			cout<<"matrix = arrays FAILED\n";
			exit_code = -1;
		}
	}
	{
		vector<Math_Vector<int> > res;
		Math_Vector<int> a1(3);
		a1[0] = 2;
		Math_Vector<int> a2(3);
		a2[2] = 3;
		res.push_back(a1);
		res.push_back(a2);
		Math_Matrix<int> mat(3, 1);
		mat = res;
		if(mat.get_vectors() == res)
		{
			cout<<"matrix = vectors passed\n";
		}
		else
		{
			cout<<"matrix = vectors FAILED\n";
			exit_code = -1;
		}
	}

	{
		Math_Matrix<int> mat1(3, 4);
		Math_Matrix<int> mat2(3, 7);
		if(!(mat1 == mat2) && mat1 == mat1 && mat2 == mat2)
		{
			cout<<"matrix == matrix passed\n";
		}
		else
		{
			cout<<"matrix == matrix FAILED\n";
			exit_code = -1;
		}
	}

	{
		Math_Matrix<int> mat1(3, 4);
		Math_Matrix<int> mat2(3, 7);
		if(mat1 != mat2 && !(mat1 != mat1) && !(mat2 != mat2))
		{
			cout<<"matrix != matrix passed\n";
		}
		else
		{
			cout<<"matrix != matrix FAILED\n";
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(3, 4);
		mat1.set(0, 0, 1);
		mat1.set(2, 3, 3);
		mat1.set(0, 1, 5);
		vector<vector<int> > mas;
		vector<int> a(4);
		a[0] = 1;
		a[1] = 5;
		mas.push_back(a);
		a.clear();
		a.resize(4);
		mas.push_back(a);
		a[3] = 3;
		mas.push_back(a);
		Math_Matrix<int> res(mas);
		if(res == mat1)
		{
			cout<<"matrix set passed\n";
		}
		else
		{
			cout<<"matrix set FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(3, 4);
		if(3 == mat1.get_m() && 4 == mat1.get_n())
		{
			cout<<"matrix get n and m passed\n";
		}
		else
		{
			cout<<"matrix get n and m FAILED\n";
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(3, 4);
		mat1.set(0, 0, 1);
		mat1.set(2, 3, 3);
		mat1.set(0, 1, 5);
		mat1 = mat1 + 1;
		vector<vector<int> > mas;
		vector<int> a = {2, 6, 1, 1};
		mas.push_back(a);
		a.clear();
		a = {1, 1, 1, 1};
		mas.push_back(a);
		a.clear();
		a = {1, 1, 1, 4};
		mas.push_back(a);
		Math_Matrix<int> res(mas);
		if(res == mat1)
		{
			cout<<"matrix + number passed\n";
		}
		else
		{
			cout<<"matrix + number FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(2, 3);
		Math_Matrix<int> res(2, 4);
		res.set(0, 3, 3);
		res.set(1, 3, 1);
		Math_Vector<int> a(2);
		a[0] = 3;
		a[1] = 1;
		mat1 = mat1 + a;
		if(res == mat1)
		{
			cout<<"matrix + vector passed\n";
		}
		else
		{
			cout<<"matrix + vector FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(2, 2);
		mat1.set(0, 0, 1);
		mat1.set(1, 1, 3);
		Math_Matrix<int> mat2(2, 2);
		mat2.set(0, 0, 2);
		mat2.set(1, 0, 3);
		Math_Matrix<int> res(2, 0);
		vector<int> a = {3, 3};
		res = res + Math_Vector<int>(a);
		a = {0, 3};
		res = res + Math_Vector<int>(a);
		if(res == mat1 + mat2)
		{
			cout<<"matrix + matrix passed\n";
		}
		else
		{
			cout<<"matrix + matrix FAILED\n";
			cout << "GET\n" << mat1 + mat2 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(3, 4);
		mat1.set(0, 0, 1);
		mat1.set(2, 3, 3);
		mat1.set(0, 1, 5);
		mat1 += 1;
		vector<vector<int> > mas;
		vector<int> a = {2, 6, 1, 1};
		mas.push_back(a);
		a.clear();
		a = {1, 1, 1, 1};
		mas.push_back(a);
		a.clear();
		a = {1, 1, 1, 4};
		mas.push_back(a);
		Math_Matrix<int> res(mas);
		if(res == mat1)
		{
			cout<<"matrix += number passed\n";
		}
		else
		{
			cout<<"matrix += number FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(2, 3);
		Math_Matrix<int> res(2, 4);
		res.set(0, 3, 3);
		res.set(1, 3, 1);
		Math_Vector<int> a(2);
		a[0] = 3;
		a[1] = 1;
		mat1 += a;
		if(res == mat1)
		{
			cout<<"matrix += vector passed\n";
		}
		else
		{
			cout<<"matrix += vector FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(2, 2);
		mat1.set(0, 0, 1);
		mat1.set(1, 1, 3);
		Math_Matrix<int> mat2(2, 2);
		mat2.set(0, 0, 2);
		mat2.set(1, 0, 3);
		Math_Matrix<int> res(2, 0);
		vector<int> a = {3, 3};
		res += Math_Vector<int>(a);
		a = {0, 3};
		res += Math_Vector<int>(a);
		mat1 += mat2;
		if(res == mat1)
		{
			cout<<"matrix += matrix passed\n";
		}
		else
		{
			cout<<"matrix += matrix FAILED\n";
			cout << "GET\n" << mat1 + mat2 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(3, 4);
		mat1.set(0, 0, 1);
		mat1.set(2, 3, 3);
		mat1.set(0, 1, 5);
		mat1 = mat1 - 1;
		vector<vector<int> > mas;
		vector<int> a = {0, 4, -1, -1};
		mas.push_back(a);
		a.clear();
		a = {-1, -1, -1, -1};
		mas.push_back(a);
		a.clear();
		a = {-1, -1, -1, 2};
		mas.push_back(a);
		Math_Matrix<int> res(mas);
		if(res == mat1)
		{
			cout<<"matrix - number passed\n";
		}
		else
		{
			cout<<"matrix - number FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(2, 2);
		mat1.set(0, 0, 1);
		mat1.set(1, 1, 3);
		Math_Matrix<int> mat2(2, 2);
		mat2.set(0, 0, 2);
		mat2.set(1, 0, 3);
		Math_Matrix<int> res(2, 0);
		vector<int> a = {-1, -3};
		res = res + Math_Vector<int>(a);
		a = {0, 3};
		res = res + Math_Vector<int>(a);
		if(res == mat1 - mat2)
		{
			cout<<"matrix - matrix passed\n";
		}
		else
		{
			cout<<"matrix - matrix FAILED\n";
			cout << "GET\n" << mat1 + mat2 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(3, 4);
		mat1.set(0, 0, 1);
		mat1.set(2, 3, 3);
		mat1.set(0, 1, 5);
		mat1 -= 1;
		vector<vector<int> > mas;
		vector<int> a = {0, 4, -1, -1};
		mas.push_back(a);
		a.clear();
		a = {-1, -1, -1, -1};
		mas.push_back(a);
		a.clear();
		a = {-1, -1, -1, 2};
		mas.push_back(a);
		Math_Matrix<int> res(mas);
		if(res == mat1)
		{
			cout<<"matrix -= number passed\n";
		}
		else
		{
			cout<<"matrix -= number FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(2, 2);
		mat1.set(0, 0, 1);
		mat1.set(1, 1, 3);
		Math_Matrix<int> mat2(2, 2);
		mat2.set(0, 0, 2);
		mat2.set(1, 0, 3);
		Math_Matrix<int> res(2, 0);
		vector<int> a = {-1, -3};
		res = res + Math_Vector<int>(a);
		a = {0, 3};
		res = res + Math_Vector<int>(a);
		mat1 -= mat2;
		if(res == mat1)
		{
			cout<<"matrix -= matrix passed\n";
		}
		else
		{
			cout<<"matrix -= matrix FAILED\n";
			cout << "GET\n" << mat1 + mat2 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat(2, 2);
		mat.set(0, 0, 1);
		mat.set(0, 1, 2);
		mat.set(1, 0, 3);
		mat.set(1, 1, 4);
		Math_Matrix<int> res;
		res.set(0, 0, 2);
		res.set(0, 1, 4);
		res.set(1, 0, 6);
		res.set(1, 1, 8);
		mat = mat * 2;
		if(res == mat)
		{
			cout<<"matrix * number passed\n";
		}
		else
		{
			cout<<"matrix * number FAILED\n";
			cout << "GET\n" << mat << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat(2, 2);
		mat.set(0, 0, 1);
		mat.set(0, 1, 2);
		mat.set(1, 0, 3);
		mat.set(1, 1, 4);
		Math_Matrix<int> res;
		res.set(0, 0, 2);
		res.set(0, 1, 4);
		res.set(1, 0, 6);
		res.set(1, 1, 8);
		mat *= 2;
		if(res == mat)
		{
			cout<<"matrix *= number passed\n";
		}
		else
		{
			cout<<"matrix *= number FAILED\n";
			cout << "GET\n" << mat << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}

	{
		Math_Matrix<int> mat(2, 2);
		Math_Matrix<int> res;
		mat.set(0, 0, 2);
		mat.set(0, 1, 4);
		mat.set(1, 0, 6);
		mat.set(1, 1, 8);
		res.set(0, 0, 1);
		res.set(0, 1, 2);
		res.set(1, 0, 3);
		res.set(1, 1, 4);
		mat = mat / 2;
		if(res == mat)
		{
			cout<<"matrix / number passed\n";
		}
		else
		{
			cout<<"matrix / number FAILED\n";
			cout << "GET\n" << mat << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat(2, 2);
		Math_Matrix<int> res;
		mat.set(0, 0, 2);
		mat.set(0, 1, 4);
		mat.set(1, 0, 6);
		mat.set(1, 1, 8);
		res.set(0, 0, 1);
		res.set(0, 1, 2);
		res.set(1, 0, 3);
		res.set(1, 1, 4);
		mat /= 2;
		if(res == mat)
		{
			cout<<"matrix /= number passed\n";
		}
		else
		{
			cout<<"matrix /= number FAILED\n";
			cout << "GET\n" << mat << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}

	{
		Math_Matrix<int> mat1(3, 2);
		vector<Math_Vector<int> > mas1;
		vector<int> vec = {2, 3, 2};
		mas1.push_back(Math_Vector(vec));
		vec = {1, 4, 1};
		mas1.push_back(Math_Vector(vec));
		mat1 = mas1;
		Math_Matrix<int> mat2(2, 4);
		vector<Math_Vector<int> > mas2;
		vec = {1, 3};
		mas2.push_back(Math_Vector(vec));
		vec = {1, 2};
		mas2.push_back(Math_Vector(vec));
		vec = {1, 3};
		mas2.push_back(Math_Vector(vec));
		vec = {4, 3};
		mas2.push_back(Math_Vector(vec));
		mat2 = mas2;
		Math_Matrix<int> mat3 = mat1 * mat2;
		Math_Matrix<int> res(3, 4);
		vector<Math_Vector<int> > mas3;
		vec = {5, 15, 5};
		mas3.push_back(Math_Vector(vec));
		vec = {4, 11, 4};
		mas3.push_back(Math_Vector(vec));
		vec = {5, 15, 5};
		mas3.push_back(Math_Vector(vec));
		vec = {11, 24, 11};
		mas3.push_back(Math_Vector(vec));
		res = mas3;
		if(res == mat3)
		{
			cout<<"matrix * matrix passed\n";
		}
		else
		{
			cout<<"matrix * matrix FAILED\n";
			cout << "GET\n" << mat3 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}

	{
		Math_Matrix<int> mat1(3, 2);
		vector<Math_Vector<int> > mas1;
		vector<int> vec = {2, 3, 2};
		mas1.push_back(Math_Vector(vec));
		vec = {1, 4, 1};
		mas1.push_back(Math_Vector(vec));
		mat1 = mas1;
		Math_Matrix<int> mat3 = mat1.transpose();
		Math_Matrix<int> res(2, 3);
		vector<Math_Vector<int> > mas3;
		vec = {2, 1};
		mas3.push_back(Math_Vector(vec));
		vec = {3, 4};
		mas3.push_back(Math_Vector(vec));
		vec = {2, 1};
		mas3.push_back(Math_Vector(vec));
		res = mas3;
		if(res == mat3)
		{
			cout<<"matrix transpose passed\n";
		}
		else
		{
			cout<<"matrix transpose FAILED\n";
			cout << "GET\n" << mat3 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}

	{
		Math_Matrix<double> mat1(3, 3);
		vector<Math_Vector<double> > mas1;
		vector<double> vec = {2, 2, 1};
		mas1.push_back(Math_Vector(vec));
		vec = {3, 4, 4};
		mas1.push_back(Math_Vector(vec));
		vec = {1, 5, 2};
		mas1.push_back(Math_Vector(vec));
		mat1 = mas1;
		double res = -17;
		if(res == mat1.det0())
		{
			cout<<"matrix determinant method 0 passed\n";
		}
		else
		{
			cout<<"matrix determinant method 0 FAILED\n";
			cout << "GET\n" << mat1.det0() << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}

	{
		Math_Matrix<int> mat1(3, 3);
		vector<Math_Vector<int> > mas1;
		vector<int> vec = {2, 12, 21};
		mas1.push_back(Math_Vector(vec));
		vec = {41, 3, 33};
		mas1.push_back(Math_Vector(vec));
		vec = {4, 31, 12};
		mas1.push_back(Math_Vector(vec));
		mat1 = mas1;
		int res = 20145;
		Math_Matrix<int> mat2(3, 3);
		vector<Math_Vector<int> > mas2;
		vec = {2, 2, 1};
		mas2.push_back(Math_Vector(vec));
		vec = {3, 4, 4};
		mas2.push_back(Math_Vector(vec));
		vec = {1, 5, 2};
		mas2.push_back(Math_Vector(vec));
		mat2 = mas2;
		int res2 = -17;
		if(res == mat1.det1() && res2 == mat2.det1())
		{
			cout<<"matrix determinant method 1 passed\n";
		}
		else
		{
			cout<<"matrix determinant method 1 FAILED\n";
			cout << "GET\n" << mat1.det1() << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(3, 3);
		vector<Math_Vector<int> > mas1;
		vector<int> vec = {2, 12, 21};
		mas1.push_back(Math_Vector(vec));
		vec = {41, 3, 33};
		mas1.push_back(Math_Vector(vec));
		vec = {4, 31, 12};
		mas1.push_back(Math_Vector(vec));
		mat1 = mas1;
		Math_Matrix<int> mat2(3, 2);
		vector<Math_Vector<int> > mas2;
		vec = {2, 12, 21};
		mas2.push_back(Math_Vector(vec));
		vec = {41, 3, 33};
		mas2.push_back(Math_Vector(vec));
		mat2 = mas2;
		mat1.pop_back();
		if(mat1 == mat2)
		{
			cout<<"matrix pop_back passed\n";
		}
		else
		{
			cout<<"matrix pop_back FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << mat2 << '\n';
			exit_code = -1;
		}
	}
	{
		Math_Matrix<int> mat1(3, 3);
		vector<Math_Vector<int> > mas1;
		vector<int> vec = {2, 12, 21};
		mas1.push_back(Math_Vector(vec));
		vec = {41, 3, 33};
		mas1.push_back(Math_Vector(vec));
		vec = {4, 31, 12};
		mas1.push_back(Math_Vector(vec));
		mat1 = mas1;
		Math_Matrix<int> mat2(3, 2);
		vector<Math_Vector<int> > mas2;
		vec = {4, 31, 12};
		mas2.push_back(Math_Vector(vec));
		vec = {41, 3, 33};
		mas2.push_back(Math_Vector(vec));
		vec = {2, 12, 21};
		mas2.push_back(Math_Vector(vec));
		mat2 = mas2;
		mat1.SwapColumns(0, 2);
		if(mat1 == mat2)
		{
			cout<<"matrix SwapColumns passed\n";
		}
		else
		{
			cout<<"matrix Swap_Columns FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << mat2 << '\n';
			exit_code = -1;
		}
	}

	{
		Math_Matrix<int> mat1(3, 3);
		vector<Math_Vector<int> > mas1;
		vector<int> vec = {2, 12, 21};
		mas1.push_back(Math_Vector(vec));
		vec = {41, 3, 33};
		mas1.push_back(Math_Vector(vec));
		vec = {4, 31, 12};
		mas1.push_back(Math_Vector(vec));
		mat1 = mas1;
		Math_Matrix<int> mat2(3, 2);
		vector<Math_Vector<int> > mas2;
		vec = {12, 2, 21};
		mas2.push_back(Math_Vector(vec));
		vec = {3, 41, 33};
		mas2.push_back(Math_Vector(vec));
		vec = {31, 4, 12};
		mas2.push_back(Math_Vector(vec));
		mat2 = mas2;
		mat1.SwapRows(0, 1);
		if(mat1 == mat2)
		{
			cout<<"matrix SwapRows passed\n";
		}
		else
		{
			cout<<"matrix SwapRows FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << mat2 << '\n';
			exit_code = -1;
		}
	}

	{
		Math_Matrix<int> mat1(3, 3);
		vector<Math_Vector<int> > mas1;
		vector<int> vec;
		vec = {2, 12, 21};
		mas1.push_back(Math_Vector(vec));
		vec = {41, 3, 33};
		mas1.push_back(Math_Vector(vec));
		vec = {4, 31, 12};
		mas1.push_back(Math_Vector(vec));
		mat1 = mas1;
		Math_Matrix<int> mat2(3, 2);
		vector<Math_Vector<int> > mas2;
		vec = {12, 2, 21};
		mas2.push_back(Math_Vector(vec));
		vec = {3, 41, 33};
		mas2.push_back(Math_Vector(vec));
		vec = {31, 4, 12};
		mas2.push_back(Math_Vector(vec));
		mat2 = mas2;
		vector<Math_Vector<int> > mas3;
		Math_Matrix<int> res;
		vec = {2, 12, 21, 12, 2, 21};
		mas3.push_back(Math_Vector(vec));
		vec = {41, 3, 33, 3, 41, 33};
		mas3.push_back(Math_Vector(vec));
		vec = {4, 31, 12, 31, 4, 12};
		mas3.push_back(Math_Vector(vec));
		res = mas3;
		mat1.add_Rows(mat2);
		if(mat1 == res)
		{
			cout<<"matrix add_Rows passed\n";
		}
		else
		{
			cout<<"matrix add_Rows FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}

	{
		Math_Matrix<int> mat1(3, 3);
		vector<Math_Vector<int> > mas1;
		vector<int> vec;
		vec = {2, 12, 21};
		mas1.push_back(Math_Vector(vec));
		vec = {41, 3, 33};
		mas1.push_back(Math_Vector(vec));
		vec = {4, 31, 12};
		mas1.push_back(Math_Vector(vec));
		mat1 = mas1;
		Math_Matrix<int> mat2(3, 2);
		vector<Math_Vector<int> > mas2;
		vec = {12, 2, 21};
		mas2.push_back(Math_Vector(vec));
		vec = {3, 41, 33};
		mas2.push_back(Math_Vector(vec));
		vec = {31, 4, 12};
		mas2.push_back(Math_Vector(vec));
		mat2 = mas2;
		vector<Math_Vector<int> > mas3;
		Math_Matrix<int> res;
		vec = {2, 12, 21};
		mas3.push_back(Math_Vector(vec));
		vec = {41, 3, 33};
		mas3.push_back(Math_Vector(vec));
		vec = {4, 31, 12};
		mas3.push_back(Math_Vector(vec));
		vec = {12, 2, 21};
		mas3.push_back(Math_Vector(vec));
		vec = {3, 41, 33};
		mas3.push_back(Math_Vector(vec));
		vec = {31, 4, 12};
		mas3.push_back(Math_Vector(vec));
		res = mas3;
		mat1.add_Columns(mat2);
		if(mat1 == res)
		{
			cout<<"matrix add_Columns passed\n";
		}
		else
		{
			cout<<"matrix add_Columns FAILED\n";
			cout << "GET\n" << mat1 << '\n' << "EXCPECTED\n" << res << '\n';
			exit_code = -1;
		}
	}
}
int main()
{

	int exit_code = 0;
	vector<int> mas;
	int n = rnd() % 10 + 1;
	Math_Vector<int> vec(n);
	mas.resize(n);
	if(mas == vec.get())
	{
		cout << "vector constructor 1 passed\n";
	}
	else
	{
		cout << "vector constructor 1 FAILED\n";
		exit_code = -1;
	}

	n = rnd() % 10;
	mas.clear();
	while(n--)
	{
		mas.push_back(rnd()%100);
	}
	vec = Math_Vector<int>(mas);
	if(mas == vec.get())
	{
		cout << "vector constructor 2 passed\n";
	}
	else
	{
		cout << "vector constructor 2 FAILED\n";
		exit_code = -1;
	}
	cout << vec << '\n';

	mas = {1, 2};
	vector<int> res = {3, 4};
	vec = Math_Vector<int>(mas);
	vec = vec + 2;
	if(res == vec.get())
	{
		cout << "vector + number passed\n";
	}
	else
	{
		cout << "vector + number FAILED\n";
		exit_code = -1;
	}

	vector<int> mas2;
	mas = {1, 2};
	mas2 = {2, 1};
	res = {3, 3};
	vec = Math_Vector<int>(mas);
	vec = vec + Math_Vector<int>(mas2);
	if(res == vec.get())
	{
		cout << "vector + vector passed\n";
	}
	else
	{
		cout << "vector + vector FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {3, 4};
	vec = Math_Vector<int>(mas);
	vec += 2;
	if(res == vec.get())
	{
		cout << "vector += number passed\n";
	}
	else
	{
		cout << "vector += number FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	mas2 = {2, 1};
	res = {3, 3};
	vec = Math_Vector<int>(mas);
	vec += Math_Vector<int>(mas2);
	if(res == vec.get())
	{
		cout << "vector += vector passed\n";
	}
	else
	{
		cout << "vector += vector FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {-1, 0};
	vec = Math_Vector<int>(mas);
	vec = vec - 2;
	if(res == vec.get())
	{
		cout << "vector - number passed\n";
	}
	else
	{
		cout << "vector - number FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	mas2 = {2, 1};
	res = {-1, 1};
	vec = Math_Vector<int>(mas);
	vec = vec - Math_Vector<int>(mas2);
	if(res == vec.get())
	{
		cout << "vector - vector passed\n";
	}
	else
	{
		cout << "vector - vector FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {-1, 0};
	vec = Math_Vector<int>(mas);
	vec -= 2;
	if(res == vec.get())
	{
		cout << "vector -= number passed\n";
	}
	else
	{
		cout << "vector -= number FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	mas2 = {2, 1};
	res = {-1, 1};
	vec = Math_Vector<int>(mas);
	vec -= Math_Vector<int>(mas2);
	if(res == vec.get())
	{
		cout << "vector -= vector passed\n";
	}
	else
	{
		cout << "vector -= vector FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {0, 1};
	vec = Math_Vector<int>(mas);
	Math_Vector<int> vec2(res);
	vec = vec2;
	if(res == vec.get())
	{
		cout << "vector = vector passed\n";
	}
	else
	{
		cout << "vector = vector FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {0, 1};
	vec = Math_Vector<int>(mas);
	vec = res;
	if(res == vec.get())
	{
		cout << "vector = std::vector passed\n";
	}
	else
	{
		cout << "vector = std::vector FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {0, 1};
	vec = mas;
	vec2 = mas;
	if(vec == vec2 && !(vec == (vec2 + 1)))
	{
		cout << "vector == vector passed\n";
	}
	else
	{
		cout << "vector == vector FAILED\n";
	}

	mas = {1, 2};
	res = {0, 1};
	vec = mas;
	vec2 = mas;
	if(!(vec != vec2) && vec != (vec2 + 1))
	{
		cout << "vector != vector passed\n";
	}
	else
	{
		cout << "vector != vector FAILED\n";
	}

	mas = {1, 2};
	res = {2, 3};
	vec = Math_Vector<int>(mas);
	vec2 = vec++;
	if(res == vec.get() && vec != vec2)
	{
		cout << "vector++ passed\n";
	}
	else
	{
		cout << "vector++ FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {0, 1};
	vec = Math_Vector<int>(mas);
	vec2 = vec--;
	if(res == vec.get() && vec != vec2)
	{
		cout << "vector-- passed\n";
	}
	else
	{
		cout << "vector-- FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {2, 3};
	vec = Math_Vector<int>(mas);
	vec2 = ++vec;
	if(res == vec.get() && vec2 == vec)
	{
		cout << "++vector passed\n";
	}
	else
	{
		cout << "++vector FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {0, 1};
	vec = Math_Vector<int>(mas);
	vec2 = --vec;
	if(res == vec.get() && vec2 == vec)
	{
		cout << "--vector passed\n";
	}
	else
	{
		cout << "--vector FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {2, 4};
	vec = mas;
	if(vec * 2 == res)
	{
		cout << "vector * number passed\n";
	}
	else
	{
		cout << "vector * number FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	res = {2, 4};
	vec = mas;
	vec *= 2;
	if(vec == res)
	{
		cout << "vector *= number passed\n";
	}
	else
	{
		cout << "vector *= number FAILED\n";
		exit_code = -1;
	}

	mas = {1, 2};
	vec = mas;
	if(vec[0] == 1 && vec[1] == 2)
	{
		cout << "vector[i] passed\n";
	}
	else
	{
		cout << "vector[i] FAILED\n";
		exit_code = -1;
	}

	mas = {2, 4};
	res = {1, 2};
	vec = mas;
	if(vec / 2 == res)
	{
		cout << "vector / number passed\n";
	}
	else
	{
		cout << "vector / number FAILED\n";
		exit_code = -1;
	}

	mas = {2, 4};
	res = {1, 2};
	vec = mas;
	vec /= 2;
	if(vec == res)
	{
		cout << "vector /= number passed\n";
	}
	else
	{
		cout << "vector /= number FAILED\n";
		exit_code = -1;
	}

	mas = {2, 4};
	res = {1, 2};
	vec = mas;
	vec2 = res;
	if(vec * vec2 == 10)
	{
		cout << "Dot product passed\n";
	}
	else
	{
		cout << "Dot product FAILED\n";
		exit_code = -1;
	}

	mas = {4, 3};
	vec = mas;
	if(vec.length() == 5)
	{
		cout << "vector length passed\n";
	}
	else
	{
		cout << "vector length FAILED\n";
		exit_code = -1;
	}

	vec = Math_Vector<int>(16);
	if(vec.get_dimensions() == 16)
	{
		cout << "vector number of dimensions passed\n";
	}
	else
	{
		cout << "vector number of dimensions FAILED\n";
	}

	vec = Math_Vector<int>(4);
	vec.push_back(4);
	mas = {0, 0, 0, 0, 4};
	res = mas;
	if(vec == res)
	{
		cout << "vector push_back number passed\n";
	}
	else
	{
		cout << "vector push_back number FAILED\n";
	}

	vec = Math_Vector<int>(0);
	vec.push_back(4);
	vec.push_back(2);
	vec2 = Math_Vector<int>(0);
	vec2.push_back(1);
	vec2.push_back(3);
	mas = {4, 2, 1, 3};
	res = mas;
	vec.concatenate(vec2);
	if(vec == res)
	{
		cout << "vector concatenate passed\n";
	}
	else
	{
		cout << "vector concatenate FAILED\n";
	}

	cout << "\n\n******************************MATRIXES******************************\n\n";

	test_matrixes(exit_code);

	return exit_code;
}