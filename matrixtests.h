#include"matrix.h"

using namespace std;

TEST(MatrixConstructors, Contructor1){
	vector<vector<int> > mas = {{1, 2}, {4, 2}};
	wvl::Math_Matrix<int> mat1(mas);
	EXPECT_EQ(mat1.get(), mas);
}

TEST(MatrixConstructors, Contructor2){
	vector<vector<int> > mas = {{0, 0, 0}, {0, 0, 0}};
	wvl::Math_Matrix<int> mat1(2, 3);
	EXPECT_EQ(mat1.get(), mas);
	EXPECT_THROW({mat1 = wvl::Math_Matrix<int>(-1, 2);}, wvl::MatrixConstructorException);
	EXPECT_THROW({mat1 = wvl::Math_Matrix<int>(1, -2);}, wvl::MatrixConstructorException);
}

TEST(MatrixConstructors, Contructor3){
	vector<vector<int> > mas;
	wvl::Math_Matrix<int> mat1;
	EXPECT_EQ(mat1.get(), mas);
}

TEST(MatrixConstructors, Contructor4){
	vector<vector<int> > mas = {{0, 0, 0}, {0, 0, 0}};
	wvl::Math_Matrix<int> mat1(make_pair(2, 3));
	EXPECT_EQ(mat1.get(), mas);
	EXPECT_THROW({mat1 = wvl::Math_Matrix<int>(make_pair(1, -2));}, wvl::MatrixConstructorException);
	EXPECT_THROW({mat1 = wvl::Math_Matrix<int>(make_pair(-1, 2));}, wvl::MatrixConstructorException);
}

TEST(MatrixConstructors, Contructor5){
	vector<vector<int> > mas = {{1}, {2}, {3}};
	vector<int> mas2 = {1, 2, 3};
	wvl::Math_Matrix<int> mat1(mas2);
	EXPECT_EQ(mat1.get(), mas);
}

TEST(MatrixGets, SubscriptingOperator){
	vector<vector<int> > mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	EXPECT_EQ(mat1[0][0], mas[0][0]);
	EXPECT_EQ(mat1[2][0], mas[0][2]);
	EXPECT_EQ(mat1[0][1], mas[1][0]);
	EXPECT_THROW({mat1[3];}, wvl::MatrixIndexException);
	EXPECT_THROW({mat1[-1];}, wvl::MatrixIndexException);
	EXPECT_THROW({mat1[0].push_back(2);}, wvl::VectorFixedSizeException);
}

TEST(MatrixGets, get_vectors){
	vector<vector<int> > mas = {{1, 4, 1}, {3, 5, 1}};
	vector<wvl::Math_Vector<int> > res;
	vector<int> a;
	a = {1, 3};
	res.push_back(wvl::Math_Vector(a));
	a = {4, 5};
	res.push_back(wvl::Math_Vector(a));
	a = {1, 1};
	res.push_back(wvl::Math_Vector(a));

	wvl::Math_Matrix<int> mat1(mas);
	EXPECT_EQ(mat1.get_vectors(), res);
}

TEST(MatrixGets, get_n){
	vector<vector<int> > mas = {{1, 4, 1}, {3, 5, 1}};

	wvl::Math_Matrix<int> mat1(mas);
	EXPECT_EQ(mat1.get_n(), 3);
}

TEST(MatrixGets, get_m){
	vector<vector<int> > mas = {{1, 4, 1}, {3, 5, 1}};

	wvl::Math_Matrix<int> mat1(mas);
	EXPECT_EQ(mat1.get_m(), 2);
}

TEST(MatrixAriphmeticOperators, SumOperator1){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 6, 3}, {5, 7, 3}};

	EXPECT_EQ(mas, (mat1 + 2).get());
}

TEST(MatrixAriphmeticOperators, SumOperator2){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	vector<int> mas2 = {2, 5};
	wvl::Math_Vector<int> vec(mas2);
	mas ={{1, 4, 1, 2}, {3, 5, 1, 5}};

	EXPECT_EQ(mas, (mat1 + vec).get());
	EXPECT_THROW({mat1 + wvl::Math_Vector<int>(10);}, wvl::MatrixDifferentDimensionException);
}


TEST(MatrixAriphmeticOperators, SumOperator3){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 1, 7}, {3, 2, 5}};
	wvl::Math_Matrix<int> mat2(mas);
	mas = {{4, 5, 8}, {6, 7, 6}};

	EXPECT_EQ((mat1 + mat2).get(), mas);
	EXPECT_THROW({mat1 + wvl::Math_Matrix<int>(7, 5);}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixAriphmeticOperators, SumAssigmentOperator1){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 6, 3}, {5, 7, 3}};
	mat1 += 2;

	EXPECT_EQ(mas, mat1.get());
}

TEST(MatrixAriphmeticOperators, SumAssigmentOperator2){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	vector<int> mas2 = {2, 5};
	wvl::Math_Vector<int> vec(mas2);
	mas ={{1, 4, 1, 2}, {3, 5, 1, 5}};
	mat1 += vec;

	EXPECT_EQ(mas, mat1.get());
	EXPECT_THROW({mat1 += wvl::Math_Vector<int>(10);}, wvl::MatrixDifferentDimensionException);
}


TEST(MatrixAriphmeticOperators, SumAssigmentOperator3){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 1, 7}, {3, 2, 5}};
	wvl::Math_Matrix<int> mat2(mas);
	mas = {{4, 5, 8}, {6, 7, 6}};
	mat1 += mat2;

	EXPECT_EQ(mat1.get(), mas);
	EXPECT_THROW({mat1 += wvl::Math_Matrix<int>(7, 5);}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixAriphmeticOperators, SubstractionOperator1){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{-1, 2, -1}, {1, 3, -1}};

	EXPECT_EQ(mas, (mat1 - 2).get());
}

TEST(MatrixAriphmeticOperators, SubstractionOperator2){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 1, 7}, {3, 2, 5}};
	wvl::Math_Matrix<int> mat2(mas);
	mas = {{-2, 3, -6}, {0, 3, -4}};

	EXPECT_EQ((mat1 - mat2).get(), mas);
	EXPECT_THROW({mat1 - wvl::Math_Matrix<int>(7, 5);}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixAriphmeticOperators, SubstractionOperator3){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{-1, -4, -1}, {-3, -5, -1}};

	EXPECT_EQ(mas, (-mat1).get());
}

TEST(MatrixAriphmeticOperators, SubstractionAssigmentOperator1){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{-1, 2, -1}, {1, 3, -1}};
	mat1 -= 2;

	EXPECT_EQ(mas, mat1.get());
}

TEST(MatrixAriphmeticOperators, SubstractionAssigmentOperator2){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 1, 7}, {3, 2, 5}};
	wvl::Math_Matrix<int> mat2(mas);
	mas = {{-2, 3, -6}, {0, 3, -4}};
	mat1 -= mat2;

	EXPECT_EQ(mat1.get(), mas);
	EXPECT_THROW({mat1 -= wvl::Math_Matrix<int>(7, 5);}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixAriphmeticOperators, MultiplicationOperator1){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 12, 3}, {9, 15, 3}};

	EXPECT_EQ(mas, (mat1 * 3).get());
}

TEST(MatrixAriphmeticOperators, MultiplicationOperator2){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 1, 7}, {3, 2, 5}};
	wvl::Math_Matrix<int> mat2(mas);
	mas = {{3, 4, 7}, {9, 10, 5}};

	EXPECT_EQ((mat1 * mat2).get(), mas);
	EXPECT_THROW({mat1 * wvl::Math_Matrix<int>(7, 5);}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixAriphmeticOperators, MultiplicationAssigmentOperator1){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 12, 3}, {9, 15, 3}};
	mat1 *= 3;

	EXPECT_EQ(mas, mat1.get());
}

TEST(MatrixAriphmeticOperators, MultiplicationAssigmentOperator2){
	vector<vector<int> > mas;
	mas = {{1, 4, 1}, {3, 5, 1}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 1, 7}, {3, 2, 5}};
	wvl::Math_Matrix<int> mat2(mas);
	mas = {{3, 4, 7}, {9, 10, 5}};
	mat1 *= mat2;

	EXPECT_EQ(mat1.get(), mas);
	EXPECT_THROW({mat1 *= wvl::Math_Matrix<int>(7, 5);}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixAriphmeticOperators, DivisionOperator1){
	vector<vector<int> > mas;
	mas = {{3, 12, 3}, {9, 15, 3}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{1, 4, 1}, {3, 5, 1}};

	EXPECT_EQ(mas, (mat1 / 3).get());
}

TEST(MatrixAriphmeticOperators, DivisionOperator2){
	vector<vector<int> > mas;
	mas = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 1, 7}, {3, 2, 5}};
	wvl::Math_Matrix<int> mat2(mas);
	mas = {{1, 4, 1}, {3, 5, 1}};

	EXPECT_EQ((mat1 / mat2).get(), mas);
	EXPECT_THROW({mat1 / wvl::Math_Matrix<int>(7, 5);}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixAriphmeticOperators, DivisionAssigmentOperator1){
	vector<vector<int> > mas;
	mas = {{3, 12, 3}, {9, 15, 3}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{1, 4, 1}, {3, 5, 1}};
	mat1 /= 3;

	EXPECT_EQ(mas, mat1.get());
}

TEST(MatrixAriphmeticOperators, DivisionAssigmentOperator2){
	vector<vector<int> > mas;
	mas = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas);
	mas = {{3, 1, 7}, {3, 2, 5}};
	wvl::Math_Matrix<int> mat2(mas);
	mas = {{1, 4, 1}, {3, 5, 1}};
	mat1 /= mat2;

	EXPECT_EQ(mat1.get(), mas);
	EXPECT_THROW({mat1 /= wvl::Math_Matrix<int>(7, 5);}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixAriphmeticOperators, prefixIncrement){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	vector<vector<int> > mas2;
	mas2 = {{4, 5, 8}, {10, 11, 6}};
	wvl::Math_Matrix<int> mat2(++mat1);

	EXPECT_EQ(mat1.get(), mas2);
	EXPECT_EQ(mat2.get(), mas2);
}

TEST(MatrixAriphmeticOperators, postfixIncrement){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	vector<vector<int> > mas2;
	mas2 = {{4, 5, 8}, {10, 11, 6}};
	wvl::Math_Matrix<int> mat2(mat1++);

	EXPECT_EQ(mat1.get(), mas2);
	EXPECT_EQ(mat2.get(), mas1);
}

TEST(MatrixAriphmeticOperators, prefixDecrement){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	vector<vector<int> > mas2;
	mas2 = {{2, 3, 6}, {8, 9, 4}};
	wvl::Math_Matrix<int> mat2(--mat1);

	EXPECT_EQ(mat1.get(), mas2);
	EXPECT_EQ(mat2.get(), mas2);
}

TEST(MatrixAriphmeticOperators, postfixDecrement){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	vector<vector<int> > mas2;
	mas2 = {{2, 3, 6}, {8, 9, 4}};
	wvl::Math_Matrix<int> mat2(mat1--);

	EXPECT_EQ(mat1.get(), mas2);
	EXPECT_EQ(mat2.get(), mas1);
}

TEST(MatrixModificating, AssigmentOperator1){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	wvl::Math_Matrix<int> mat2(2, 4);
	mat2 = mat1;

	EXPECT_EQ(mat1.get(), mat2.get());
}

TEST(MatrixModificating, AssigmentOperator2){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	wvl::Math_Matrix<int> mat2(2, 4);
	mat2 = mas1;

	EXPECT_EQ(mat1.get(), mat2.get());

	mas1 = {{3, 4, 7}, {9, 10, 5, 7}};
	EXPECT_THROW({mat2 = mas1;}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixModificating, AssigmentOperator3){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	wvl::Math_Matrix<int> mat2(2, 4);
	vector<wvl::Math_Vector<int> > mas2;
	mas2.push_back(wvl::Math_Vector<int>(mat1[0]));
	mas2.push_back(wvl::Math_Vector<int>(mat1[1]));
	mas2.push_back(wvl::Math_Vector<int>(mat1[2]));
	mat2 = mas2;

	EXPECT_EQ(mat1.get(), mat2.get());
	mas2.push_back(wvl::Math_Vector<int>(5));
	EXPECT_THROW({mat2 = mas2;}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixModificating, transpose){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	mas1 = {{3, 9}, {4, 10}, {7, 5}};
	mat1.transpose();

	EXPECT_EQ(mat1.get(), mas1);
}

TEST(MatrixModificating, transposed){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	mas1 = {{3, 9}, {4, 10}, {7, 5}};
	wvl::Math_Matrix<int> mat2(mat1.transposed());

	EXPECT_EQ(mat2.get(), mas1);
}

TEST(MatrixModificating, pop_back){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	mas1 = {{3, 4}, {9, 10}};
	mat1.pop_back();

	EXPECT_EQ(mat1.get(), mas1);
	mat1 = wvl::Math_Matrix<int> (5, 0);
	EXPECT_THROW({mat1.pop_back();}, wvl::MatrixIndexException);
}

TEST(MatrixModificating, swap_columns){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	mas1 = {{7, 4, 3}, {5, 10, 9}};
	mat1.swap_columns(0, 2);

	EXPECT_EQ(mat1.get(), mas1);

	EXPECT_THROW({mat1.swap_columns(-1, 1);}, wvl::MatrixIndexException);
	EXPECT_THROW({mat1.swap_columns(3, 1);}, wvl::MatrixIndexException);
	EXPECT_THROW({mat1.swap_columns(0, 3);}, wvl::MatrixIndexException);
	EXPECT_THROW({mat1.swap_columns(0, -1);}, wvl::MatrixIndexException);
}

TEST(MatrixModificating, swap_rows){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	mas1 = {{9, 10, 5}, {3, 4, 7}};
	mat1.swap_rows(0, 1);

	EXPECT_EQ(mat1.get(), mas1);

	EXPECT_THROW({mat1.swap_rows(-1, 1);}, wvl::MatrixIndexException);
	EXPECT_THROW({mat1.swap_rows(2, 1);}, wvl::MatrixIndexException);
	EXPECT_THROW({mat1.swap_rows(0, 2);}, wvl::MatrixIndexException);
	EXPECT_THROW({mat1.swap_rows(0, -1);}, wvl::MatrixIndexException);
}


TEST(MatrixModificating, add_rows){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	mas1 = {{9, 10, 4}, {3, 4, 4}};
	wvl::Math_Matrix<int> mat2(mas1);
	mas1 = {{3, 4, 7}, {9, 10, 5}, {9, 10, 4}, {3, 4, 4}};
	wvl::Math_Matrix<int> mat3(mas1);
	mat1.add_rows(mat2);

	EXPECT_EQ(mat1.get(), mat3.get());

	EXPECT_THROW({mat1.add_rows(wvl::Math_Matrix<int>(7, 4));}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixModificating, add_row){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	vector<int> mas2;
	mas2 = {4, 5, 6};
	wvl::Math_Vector<int> mat2(mas2);
	mas1 = {{3, 4, 7}, {9, 10, 5}, {4, 5, 6}};
	wvl::Math_Matrix<int> mat3(mas1);
	mat1.add_row(mat2);

	EXPECT_EQ(mat1.get(), mat3.get());

	EXPECT_THROW({mat1.add_row(wvl::Math_Vector<int>(4));}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixModificating, add_columns){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	mas1 = {{3, 4}, {5, 7}};
	wvl::Math_Matrix<int> mat2(mas1);
	mas1 = {{3, 4, 7, 3, 4}, {9, 10, 5, 5, 7}};
	wvl::Math_Matrix<int> mat3(mas1);
	mat1.add_columns(mat2);

	EXPECT_EQ(mat1.get(), mat3.get());

	EXPECT_THROW({mat1.add_columns(wvl::Math_Matrix<int>(3));}, wvl::MatrixDifferentDimensionException);
}

int f(int a)
{
	return a * a;
}

TEST(MatrixModificating, convert_elements){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	mas1 = {{9, 16, 7 * 7}, {9 * 9, 100, 25}};
	mat1.convert_elements(f);

	EXPECT_EQ(mat1.get(), mas1);
}

TEST(MatrixModificating, converted_elements){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);
	mas1 = {{9, 16, 7 * 7}, {9 * 9, 100, 25}};
	mat1 = mat1.converted_elements(f);

	EXPECT_EQ(mat1.get(), mas1);
}

TEST(MatrixBoolOperations, equal){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);

	EXPECT_TRUE(mat1 == mat1);
	EXPECT_FALSE(mat1 == wvl::Math_Matrix<int>(5, 7));
}

TEST(MatrixBoolOperations, notEqual){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);

	EXPECT_FALSE(mat1 != mas1);
	EXPECT_TRUE(mat1 != wvl::Math_Matrix<int>(5, 7));
}

TEST(MatrixOperations, dot){
	vector<vector<int> > mas1;
	mas1 = {{3, 4, 7}, {9, 10, 5}};
	wvl::Math_Matrix<int> mat1(mas1);

	vector<vector<int> > mas2;
	mas2 = {{3, 4}, {9, 10}, {9, 10}};
	wvl::Math_Matrix<int> mat2(mas2);

	vector<vector<int> > mas3;
	mas3 = {{108, 122}, {162, 186}};
	wvl::Math_Matrix<int> mat3(mas3);

	EXPECT_EQ(mat1.dot(mat2).get(), mas3);
}

TEST(MatrixOperations, det0){
	vector<vector<double> > mas1;
	mas1 = {{4, 2, 5}, {7, 4, 2}, {8, 5, 3}};
	wvl::Math_Matrix<double> mat1(mas1);

	EXPECT_EQ(mat1.det0(), 13);
	EXPECT_THROW({wvl::Math_Matrix<int>(4, 5).det0();}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixOperations, det1){
	vector<vector<int> > mas1;
	mas1 = {{4, 2, 5}, {7, 4, 2}, {8, 5, 3}};
	wvl::Math_Matrix<int> mat1(mas1);

	EXPECT_EQ(mat1.det1(), 13);
	EXPECT_THROW({wvl::Math_Matrix<int>(4, 5).det1();}, wvl::MatrixDifferentDimensionException);
}

TEST(MatrixOperations, stream){
	vector<vector<int> > mas1;
	mas1 = {{4, 2, 5}, {7, 4, 2}, {8, 5, 3}, {7, 4, 2}};
	wvl::Math_Matrix<int> mat1(mas1);
	wvl::Math_Matrix<int> mat2;

	fstream file;
	file.open("test.txt", ios::out);
	file << mat1;
	file.close();

	file.open("test.txt", ios::in);
	file >> mat2;
	file.close();

	EXPECT_EQ(mat1.get(), mat2.get());
}