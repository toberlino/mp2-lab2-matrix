#include <gtest.h>
#include "utmatrix.h"


TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> a(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> a(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> a(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> a(5);

  ASSERT_NO_THROW(TMatrix<int> a1(a));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix <int> a1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			a1[i][j]=1;
	TMatrix <int> a2(a1);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			EXPECT_EQ(1,a2[i][j]);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix <int> a1(2);
	TMatrix <int> a2(a1);
	EXPECT_NE(&a2,&a1);
}

TEST(TMatrix, can_get_size)
{
	TMatrix <int> a(4);
	EXPECT_EQ(4, a.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix <int> a(4);
	a[0][0] = 4;
	EXPECT_EQ(4, a[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix <int> a(2);
	ASSERT_ANY_THROW(a[-1][0]=1);	
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> a(2);
	ASSERT_ANY_THROW(a[3][0]=1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> a(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			a[i][j]=1;
	a=a;
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			EXPECT_EQ(1,a[i][j]);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> a1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			a1[i][j]=i;
	TMatrix<int> a2(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			a2[i][j]=i+1;
 	a1=a2;
 	EXPECT_EQ(1,a1[0][0]);
 	EXPECT_EQ(1,a1[0][1]);
 	EXPECT_EQ(2,a1[1][0]);
 }
 
 TEST(TMatrix, assign_operator_change_matrix_size)
 {
 	TMatrix<int> a1(3);
 	TMatrix<int> a2(2);
 	a1=a2;
 	EXPECT_EQ(2,a1.GetSize());
 }
 
 TEST(TMatrix, can_assign_matrices_of_different_size)
 {
 	TMatrix<int> a1(3);
 	for (int i=0;i<3;i++)
 		for (int j=0;j<3-i;j++)
 			a1[i][j]=i;
 	TMatrix<int> a2(2);
 	for (int i=0;i<2;i++)
 		for (int j=0;j<2-i;j++)
 			a2[i][j]=i;
 	a1=a2;
 	EXPECT_EQ(0,a1[0][0]);
 	EXPECT_EQ(0,a1[0][1]);
 	EXPECT_EQ(1,a1[1][0]);
 }
 
 TEST(TMatrix, compare_equal_matrices_return_true)
 {
 	TMatrix<int> a1(3);
	for (int i=0;i<3;i++)
		for (int j=0;j<3-i;j++)
			a1[i][j]=i;
	TMatrix<int> a2(3);
	for (int i=0;i<3;i++)
		for (int j=0;j<3-i;j++)
			a2[i][j]=i;
	EXPECT_TRUE(a1==a2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> a1(3);
	for (int i=0;i<3;i++)
		for (int j=0;j<3-i;j++)
			a1[i][j]=i;
	EXPECT_TRUE(a1==a1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> a1(2);
	TMatrix<int> a2(3);
	EXPECT_TRUE(a1!=a2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> a1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			a1[i][j]=i;
	TMatrix<int> a2(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			a2[i][j]=i+1;
	TMatrix<int> a3(2);
	a3=a1+a2;
	EXPECT_EQ(1,a3[0][0]);
	EXPECT_EQ(1,a3[0][1]);
	EXPECT_EQ(3,a3[1][0]);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> a1(2);
	TMatrix<int> a2(3);
	ASSERT_ANY_THROW(a1+a2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> a1(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			a1[i][j]=i;
	TMatrix<int> a2(2);
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			a2[i][j]=i+1;
	TMatrix<int> a3(2);
	a3=a2-a1;
	for (int i=0;i<2;i++)
		for (int j=0;j<2-i;j++)
			EXPECT_EQ(1,a3[i][j]);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> a1(2);
	TMatrix<int> a2(3);
	ASSERT_ANY_THROW(a1-a2);
}
