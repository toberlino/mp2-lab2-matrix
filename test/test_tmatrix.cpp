#include <gtest.h>
#include "utmatrix.h"


TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix <int> m1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m1[i][j]=1;
	TMatrix <int> m2(m1);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			EXPECT_EQ(1,m2[i][j]);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix <int> m1(2);
	TMatrix <int> m2(m1);
	EXPECT_NE(&m2,&m1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix <int> m(4);
	EXPECT_EQ(4, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix <int> m(4);
	m[0][0] = 4;
	EXPECT_EQ(4, m[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix <int> m(2);
	ASSERT_ANY_THROW(m[-1][0]=1);	
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(2);
	ASSERT_ANY_THROW(m[3][0]=1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m[i][j]=1;
	m=m;
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			EXPECT_EQ(1,m[i][j]);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> m1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m1[i][j]=i;
	TMatrix<int> m2(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m2[i][j]=i+1;
 	m1=m2;
 	EXPECT_EQ(1,m1[0][0]);
 	EXPECT_EQ(1,m1[0][1]);
 	EXPECT_EQ(2,m1[1][0]);
 }
 
 TEST(TMatrix, assign_operator_change_matrix_size)
 {
 	TMatrix<int> m1(3);
 	TMatrix<int> m2(2);
 	m1=m2;
 	EXPECT_EQ(2,m1.GetSize());
 }
 
 TEST(TMatrix, can_assign_matrices_of_different_size)
 {
 	TMatrix<int> m1(3);
 	for (int i=0;i<3;i++)
 		for (int j=0;j<3-i;j++)
 			m1[i][j]=i;
 	TMatrix<int> m2(2);
 	for (int i=0;i<2;i++)
 		for (int j=0;j<2-i;j++)
 			m2[i][j]=i;
 	m1=m2;
 	EXPECT_EQ(0,m1[0][0]);
 	EXPECT_EQ(0,m1[0][1]);
 	EXPECT_EQ(1,m1[1][0]);
 }
 
 TEST(TMatrix, compare_equal_matrices_return_true)
 {
 	TMatrix<int> m1(3);
	for (int i=0;i<3;i++)
		for (int j=0;j<3-i;j++)
			m1[i][j]=i;
	TMatrix<int> m2(3);
	for (int i=0;i<3;i++)
		for (int j=0;j<3-i;j++)
			m2[i][j]=i;
	EXPECT_TRUE(m1==m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(3);
	for (int i=0;i<3;i++)
		for (int j=0;j<3-i;j++)
			m1[i][j]=i;
	EXPECT_TRUE(m1==m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(3);
	EXPECT_TRUE(m1!=m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m1[i][j]=i;
	TMatrix<int> m2(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m2[i][j]=i+1;
	TMatrix<int> m3(2);
	m3=m1+m2;
	EXPECT_EQ(1,m3[0][0]);
	EXPECT_EQ(1,m3[0][1]);
	EXPECT_EQ(3,m3[1][0]);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(3);
	ASSERT_ANY_THROW(m1+m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m1[i][j]=i;
	TMatrix<int> m2(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			m2[i][j]=i+1;
	TMatrix<int> m3(2);
	m3=m2-m1;
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			EXPECT_EQ(1,m3[i][j]);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(2);
	TMatrix<int> m2(3);
	ASSERT_ANY_THROW(m1-m2);
}
/*
TEST(TMatrix, can_multiplied_by_the_E) {
	TMatrix<int> a(2), result(2), b(2),e(2);
	// 1 0
	// 0 1
	e[0][0] = 1;
	e[1][1] = 1;
	// 1 2
	// 0 3
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 3;
	// 1 2
	// 0 3
	result[0][0] = 1;
	result[0][1] = 2;
	result[1][1] = 3;

	b = a*e;

	EXPECT_EQ(result, b);
}
TEST(TMatrix, can_not_multiplied_matrix_with_different_size) {
	TMatrix<int> a(2), b(3);

	ASSERT_ANY_THROW(a*b);
}
TEST(TMatrix, can_multiplied_matrix_with_equal_sizes) {
	TMatrix<int> a(2), result(2), b(2);

	// 1 2
	// 0 3
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 3;
	// 3 2
	// 0 1
	b[0][0] = 3;
	b[0][1] = 2;
	b[1][1] = 1;
	// 3 4
	// 0 3
	result[0][0] = 3;
	result[0][1] = 4;
	result[1][1] = 3;

	EXPECT_EQ(result, a*b);
}

TEST(TMatrix, can_multiplied__matrix_on_itself) {
	TMatrix<int> a(2), result(2);

	// 1 2
	// 0 3
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][1] = 3;

	// 3 4
	// 0 3
	result[0][0] = 1;
	result[0][1] = 8;
	result[1][1] = 9;

	EXPECT_EQ(result, a*a);
}*/