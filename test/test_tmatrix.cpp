#include "utmatrix.h"

#include <gtest.h>

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
  TMatrix <int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
  TMatrix <int> m(3);
  m[1][1]=5;
  TMatrix <int> m_1(m);
  EXPECT_EQ(m,m_1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
  TMatrix <int> m(3);
  TMatrix <int> m_1(m);
  m[1][1]=5;
  EXPECT_NE(m[1][1],m_1[1][1]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix <int> m(3);
  EXPECT_EQ(3,m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix <int> m(3);
	m[1][1]=5;
  EXPECT_EQ(5,m[1][1]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
  TMatrix <int> m(3);
  ASSERT_ANY_THROW (m[-1][-2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
  TMatrix <int> m(3);
  ASSERT_ANY_THROW (m[5][4]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
  TMatrix <int> m(3);
  ASSERT_NO_THROW (m=m);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
  TMatrix <int> m(4);
  TMatrix <int> m_1(4);
  for (int i=0;i<4;i++)
	  m[i][i]=i+2;
  m_1=m;
  EXPECT_EQ(m_1,m);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
  TMatrix <int> m(5);
  TMatrix <int> m_1(3);
  m=m_1;
  EXPECT_EQ(3,m.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
  TMatrix <int> m(5);
  TMatrix <int> m_1(3);
  for (int i=0;i<5;i++)
	  m[i][i]=i+2;
  m_1=m;
  EXPECT_EQ(m_1,m);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
  TMatrix <int> m(5);
  TMatrix <int> m_1(5);
  EXPECT_EQ(true, m == m_1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
  TMatrix <int> m(5);
  EXPECT_EQ(true, m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
  TMatrix <int> m(5);
  TMatrix <int> m_1(3);
  EXPECT_EQ(true, m != m_1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
  TMatrix <int> m(3);
  TMatrix <int> m_1(3);
  TMatrix <int> sum(2);
  TMatrix <int> exp(3);
  m[0][0]=4; 
  m[1][1]=1;
  m[1][2]=3;
  m[2][2]=5;

  m_1[0][0]=1;
  m_1[0][1]=2;
  m_1[1][1]=2;

  sum=m+m_1;

  exp[0][0]=5;
  exp[0][1]=2;
  exp[0][2]=0;
  exp[1][1]=3;
  exp[1][2]=3;
  exp[2][2]=5;
  EXPECT_EQ(exp, sum);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
  TMatrix <int> m(3);
  TMatrix <int> m_1(5);
  ASSERT_ANY_THROW(m+m_1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
  TMatrix <int> m(3);
  TMatrix <int> m_1(3);
  TMatrix <int> sub(2);
  TMatrix <int> exp(3);
  m[0][0]=4; 
  m[1][1]=1;
  m[1][2]=3;
  m[2][2]=5;

  m_1[0][0]=1;
  m_1[0][1]=2;
  m_1[1][1]=2;

  sub=m-m_1;

  exp[0][0]=3;
  exp[0][1]=-2;
  exp[0][2]=0;
  exp[1][1]=-1;
  exp[1][2]=3;
  exp[2][2]=5;
  EXPECT_EQ(exp, sub);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
  TMatrix <int> m(3);
  TMatrix <int> m_1(5);
  ASSERT_ANY_THROW(m-m_1);
}

