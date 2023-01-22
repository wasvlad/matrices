#include <bits/stdc++.h>
#include "vector.h"

using namespace std;

TEST(VectorConstructor, ConstructorTest1)
{
	std::vector<int> mas;
	wvl::Math_Vector<int> vec = wvl::Math_Vector<int>();
	EXPECT_EQ(vec.get(), mas);
}

TEST(VectorConstructor, ConstructorTest2)
{
	std::vector<int> mas;
	mas.resize(4);
	wvl::Math_Vector<int> vec = wvl::Math_Vector<int>(4);
	EXPECT_EQ(vec.get(), mas);
	EXPECT_THROW({vec = wvl::Math_Vector<int>(-2);}, wvl::VectorConstructorException);
}

TEST(VectorConstructor, ConstructorTest3)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec = wvl::Math_Vector<int>(mas);
	EXPECT_EQ(vec.get(), mas);
}

TEST(VectorModificating, OperatorAssigment1)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec = mas;
	EXPECT_EQ(vec.get(), mas);
}

TEST(VectorModificating, OperatorAssigment2)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec = mas;
	wvl::Math_Vector<int> vec2 = vec;
	EXPECT_EQ(vec.get(), vec2.get());
}

TEST(VectorModificating, push_back)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec = wvl::Math_Vector<int>();
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	EXPECT_EQ(vec.get(), mas);
}

TEST(VectorModificating, pop_backTest1)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec = wvl::Math_Vector<int>();
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.pop_back();
	mas.pop_back();
	EXPECT_EQ(vec.get(), mas);
}

TEST(VectorModificating, pop_backTest2)
{
	EXPECT_THROW({
		wvl::Math_Vector<int> vec = wvl::Math_Vector<int>();
		vec.pop_back();
	},
	wvl::VectorOutOfRange
		);
}

TEST(VectorModificating, SubscriptingOperatorTest1)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	for(int i = 0; i < mas.size(); i++){
		EXPECT_EQ(vec[i], mas[i]);
	}
	mas[1] = 4;
	vec[1] = 4;
	for(int i = 0; i < mas.size(); i++){
		EXPECT_EQ(vec[i], mas[i]);
	}
}

TEST(VectorModificating, SubscriptingOperatorTest2)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	EXPECT_THROW({
		vec[mas.size()];
	}, wvl::VectorOutOfRange);
	EXPECT_THROW({
		vec[-1];
	}, wvl::VectorOutOfRange);
}

TEST(VectorModificating, concatenate1)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	wvl::Math_Vector<int> vec2;
	vec2 = mas;
	vec.concatenate(vec2);
	mas = {1, 2, 3, 1, 2, 3};
	EXPECT_EQ(vec.get(), mas);
}

TEST(VectorModificating, concatenate2)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	vec.concatenate(mas);
	mas = {1, 2, 3, 1, 2, 3};
	EXPECT_EQ(vec.get(), mas);
}

TEST(VectorModificating, erase1Test1)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {1, 3};
	vec.erase(1);
	EXPECT_EQ(mas, vec.get());
}

TEST(VectorModificating, erase1Test2)
{
	std::vector<int> mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	EXPECT_THROW({
		vec.erase(mas.size());
	}, wvl::VectorOutOfRange);
	EXPECT_THROW({
		vec.erase(-1);
	}, wvl::VectorOutOfRange);
}

/*
TEST(VectorModificating, erase2Test1)
{
	std::vector<int> mas = {1, 2, 3, 4};
	wvl::Math_Vector<int> vec;
	vec = mas;
	//mas = {1, 4};
	vec.erase(1, 2);
	EXPECT_EQ(mas, vec.get());
}

TEST(VectorModificating, erase2Test2)
{
	std::vector<int> mas = {1, 2, 3, 4};
	wvl::Math_Vector<int> vec;
	vec = mas;

	EXPECT_THROW({
		vec.erase(mas.size(), 4);
	}, wvl::VectorOutOfRange);

	EXPECT_THROW({
		vec.erase(-1, 2);
	}, wvl::VectorOutOfRange);

	EXPECT_THROW({
		vec.erase(3, 1);
	}, wvl::VectorException);
}
*/

TEST(ArithmeticOperators, plus1Test1)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	wvl::Math_Vector<int> vec3;
	vec3 = vec + vec2;
	mas = {4, 3, 7};
	EXPECT_EQ(vec3.get(), mas);
	vec3 = vec2 + vec;
	EXPECT_EQ(vec3.get(), mas);
}

TEST(ArithmeticOperators, plus1Test2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4, 5};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec = vec + vec2;
	}, wvl::VectorDifferentDimensionsException);
}

TEST(ArithmeticOperators, plus2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec3;
	vec3 = vec + 2;
	mas = {3, 4, 5};
	EXPECT_EQ(vec3.get(), mas);
	vec3 = 2 + vec;
	EXPECT_EQ(vec3.get(), mas);
}

TEST(ArithmeticOperators, plusAssigment1Test1)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	vec += vec2;
	mas = {4, 3, 7};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, plusAssigment1Test2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4, 5};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec += vec2;
	}, wvl::VectorDifferentDimensionsException);
}

TEST(ArithmeticOperators, plusAssigment2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	vec += 2;
	mas = {3, 4, 5};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, minus1Test1)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	vec = vec - vec2;
	mas = {-2, 1, -1};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, minus1Test2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4, 5};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec = vec - vec2;
	}, wvl::VectorDifferentDimensionsException);
}

TEST(ArithmeticOperators, minus2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	vec = vec - 2;
	mas = {-1, 0, 1};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, minus3)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	vec = -vec;
	mas = {-1, -2, -3};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, minusAssigment1Test1)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	vec -= vec2;
	mas = {-2, 1, -1};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, minusAssigment1Test2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4, 5};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec -= vec2;
	}, wvl::VectorDifferentDimensionsException);
}

TEST(ArithmeticOperators, minusAssigment2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	vec -= 2;
	mas = {-1, 0, 1};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, postfixIncrement)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec2;
	vec2 = vec++;
	mas = {1, 2, 3};
	EXPECT_EQ(vec2.get(), mas);
	mas = {2, 3, 4};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, prefixIncrement)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec2;
	vec2 = ++vec;
	mas = {2, 3, 4};
	EXPECT_EQ(vec2.get(), mas);
	mas = {2, 3, 4};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, postfixDecrement)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec2;
	vec2 = vec--;
	mas = {1, 2, 3};
	EXPECT_EQ(vec2.get(), mas);
	mas = {0, 1, 2};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, prefixDecrement)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec2;
	vec2 = --vec;
	mas = {0, 1, 2};
	EXPECT_EQ(vec2.get(), mas);
	mas = {0, 1, 2};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, multiply1Test1)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	wvl::Math_Vector<int> vec3;
	vec3 = vec * vec2;
	mas = {3, 2, 12};
	EXPECT_EQ(vec3.get(), mas);
	vec3 = vec2 * vec;
	EXPECT_EQ(vec3.get(), mas);
}

TEST(ArithmeticOperators, multiply1Test2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4, 5};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec = vec * vec2;
	}, wvl::VectorDifferentDimensionsException);
}

TEST(ArithmeticOperators, multiply2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec3;
	vec3 = vec * 2;
	mas = {2, 4, 6};
	EXPECT_EQ(vec3.get(), mas);
	vec3 = 2 * vec;
	EXPECT_EQ(vec3.get(), mas);
}

TEST(ArithmeticOperators, multiplyAssigment1Test1)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	vec *= vec2;
	mas = {3, 2, 12};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, multiplyAssigment1Test2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4, 5};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec *= vec2;
	}, wvl::VectorDifferentDimensionsException);
}

TEST(ArithmeticOperators, multiplyAssigment2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	vec *= 2;
	mas = {2, 4, 6};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, divide1Test1)
{
	std::vector<int> mas;
	mas = {4, 12, 6};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {2, 3, 3};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	wvl::Math_Vector<int> vec3;
	vec3 = vec / vec2;
	mas = {2, 4, 2};
	EXPECT_EQ(vec3.get(), mas);
}

TEST(ArithmeticOperators, divide1Test2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4, 5};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec = vec / vec2;
	}, wvl::VectorDifferentDimensionsException);
}

TEST(ArithmeticOperators, divide2)
{
	std::vector<int> mas;
	mas = {4, 12, 6};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec3;
	vec3 = vec / 2;
	mas = {2, 6, 3};
	EXPECT_EQ(vec3.get(), mas);
}

TEST(ArithmeticOperators, divideAssigment1)
{
	std::vector<int> mas;
	mas = {4, 12, 6};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {2, 3, 3};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	wvl::Math_Vector<int> vec3;
	vec /= vec2;
	mas = {2, 4, 2};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, divideAssigment1Test2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4, 5};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec /= vec2;
	}, wvl::VectorDifferentDimensionsException);
}

TEST(ArithmeticOperators, divideAssigment2)
{
	std::vector<int> mas;
	mas = {4, 12, 6};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec3;
	vec /= 2;
	mas = {2, 6, 3};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, modulo1Test1)
{
	std::vector<int> mas;
	mas = {5, 13, 8};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {2, 3, 3};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	wvl::Math_Vector<int> vec3;
	vec3 = vec % vec2;
	mas = {1, 1, 2};
	EXPECT_EQ(vec3.get(), mas);
}

TEST(ArithmeticOperators, modulo1Test2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4, 5};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec = vec % vec2;
	}, wvl::VectorDifferentDimensionsException);
}

TEST(ArithmeticOperators, modulo2)
{
	std::vector<int> mas;
	mas = {5, 13, 8};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec3;
	vec3 = vec % 2;
	mas = {1, 1, 0};
	EXPECT_EQ(vec3.get(), mas);
}

TEST(ArithmeticOperators, moduloAssigment1)
{
	std::vector<int> mas;
	mas = {5, 13, 8};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {2, 3, 3};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	wvl::Math_Vector<int> vec3;
	vec %= vec2;
	mas = {1, 1, 2};
	EXPECT_EQ(vec.get(), mas);
}

TEST(ArithmeticOperators, moduloAssigment1Test2)
{
	std::vector<int> mas;
	mas = {1, 2, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	mas = {3, 1, 4, 5};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec %= vec2;
	}, wvl::VectorDifferentDimensionsException);
}

TEST(ArithmeticOperators, moduloAssigment2)
{
	std::vector<int> mas;
	mas = {5, 12, 9};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec3;
	vec %= 2;
	mas = {1, 0, 1};
	EXPECT_EQ(vec.get(), mas);
}

TEST(BoolOperators, equal)
{
	std::vector<int> mas;
	mas = {5, 12, 9};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_TRUE(vec == vec2);
	EXPECT_FALSE(vec == wvl::Math_Vector<int>(5));
}

TEST(BoolOperators, notEqual)
{
	std::vector<int> mas;
	mas = {5, 12, 9};
	wvl::Math_Vector<int> vec;
	vec = mas;

	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_FALSE(vec != vec2);
	EXPECT_TRUE(vec != wvl::Math_Vector<int>(5));
}

TEST(Methods, length)
{
	std::vector<int> mas;
	mas = {4, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	EXPECT_EQ(vec.length(), 5);
	vec *= 2;
	EXPECT_EQ(vec.length(), 10);
}

TEST(Methods, get_dimensions)
{
	std::vector<int> mas;
	mas = {4, 3, 1};
	wvl::Math_Vector<int> vec;
	vec = mas;

	EXPECT_EQ(vec.get_dimensions(), 3);
	vec.pop_back();
	EXPECT_EQ(vec.get_dimensions(), 2);
}

TEST(Methods, size)
{
	std::vector<int> mas;
	mas = {4, 3, 1};
	wvl::Math_Vector<int> vec;
	vec = mas;

	EXPECT_EQ(vec.size(), 3);
	vec.pop_back();
	EXPECT_EQ(vec.size(), 2);
}

TEST(Methods, sum)
{
	std::vector<int> mas;
	mas = {4, 3, 1};
	wvl::Math_Vector<int> vec;
	vec = mas;

	EXPECT_EQ(vec.sum(), 8);
	vec.pop_back();
	EXPECT_EQ(vec.sum(), 7);
}

TEST(Methods, dotTest1)
{
	std::vector<int> mas;
	mas = {4, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	mas = {2, 1};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_EQ(vec.dot(vec2), 11);
}

TEST(Methods, dotTest2)
{
	std::vector<int> mas;
	mas = {4, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;

	mas = {2, 1, 4};
	wvl::Math_Vector<int> vec2;
	vec2 = mas;

	EXPECT_THROW({
		vec.dot(vec2);
	}, wvl::VectorDifferentDimensionsException);
}

TEST(Methods, stream)
{
	std::vector<int> mas;
	mas = {4, 3};
	wvl::Math_Vector<int> vec;
	vec = mas;
	fstream file;
	file.open("test.txt", ios::out);
	file << vec;
	file.close();

	wvl::Math_Vector<int> vec2;
	file.open("test.txt", ios::in);
	file >> vec2;
	file.close();
	EXPECT_EQ(vec.get(), vec2.get());
}
