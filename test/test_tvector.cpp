#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector<int> v(10);
  v[1]=2;
  v[4]=5;
  TVector<int> v_1(v);
  EXPECT_EQ(v,v_1);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(10);
  TVector<int> v_1(v);
  v_1[5]=4;
  EXPECT_NE(v[5],v_1[5]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
  TVector<int> v(4);
  ASSERT_ANY_THROW(v[-3]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
  TVector<int> v(4);
  ASSERT_ANY_THROW(v[10]);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> v(4);
  ASSERT_NO_THROW(v=v);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
  TVector<int> v(4);
  TVector<int> v_1(4);
  for (int i=0;i<4;i++)
	  v[i]=2*i;
  v_1=v;
  EXPECT_EQ(v_1,v);
}

TEST(TVector, assign_operator_change_vector_size)
{
  TVector<int> v(4);
  TVector<int> v_1(8);
  v=v_1;
  EXPECT_EQ(8,v.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
  TVector<int> v(4);
  TVector<int> v_1(2);
  for (int i=0;i<4;i++)
	  v[i]=2*i;
  v_1=v;
  EXPECT_EQ(v_1,v);
}

TEST(TVector, compare_equal_vectors_return_true)
{
  TVector<int> v(4);
  TVector<int> v_1(4);
  v[0]=0;
  v[1]=2;
  v[2]=4;

  v_1[0]=0;
  v_1[1]=2;
  v_1[2]=4;

  EXPECT_EQ(1,v==v_1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<int> v(4);
  EXPECT_EQ(1,v==v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
  TVector<int> v(4);
  TVector<int> v_1(5);

  EXPECT_EQ(1,v!=v_1);
}

TEST(TVector, can_add_scalar_to_vector)
{
  TVector<int> v(4);
  TVector<int> sum(4);
  TVector<int> exp(4);
  v[0]=1;
  v[1]=3;

  sum=v+3;

  exp[0]=4;
  exp[1]=6;
  exp[2]=exp[3]=3;

  EXPECT_EQ(exp,sum);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> v(4);
  TVector<int> sub(4);
  TVector<int> exp(4);
  v[0]=1;
  v[1]=3;

  sub=v-3;

  exp[0]=-2;
  exp[1]=0;
  exp[2]=exp[3]=-3;

  EXPECT_EQ(exp,sub);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
  TVector<int> v(4);
  TVector<int> mul(4);
  TVector<int> exp(4);
  v[0]=1;
  v[1]=3;

  mul=v*3;

  exp[0]=3;
  exp[1]=9;
  exp[2]=exp[3]=0;

  EXPECT_EQ(exp,mul);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
  TVector<int> v(4);
  TVector<int> v_1(4);
  TVector<int> sum(4);
  TVector<int> exp(4);
  v[0]=1;
  v[1]=3;

  v_1[1]=3;
  v_1[2]=5;

  sum=v+v_1;

  exp[0]=1;
  exp[1]=6;
  exp[2]=5;
  exp[3]=0;

  EXPECT_EQ(exp,sum);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
  TVector<int> v(4);
  TVector<int> v_1(5);
  ASSERT_ANY_THROW(v+v_1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
  TVector<int> v(4);
  TVector<int> v_1(4);
  TVector<int> sub(4);
  TVector<int> exp(4);
  v[0]=1;
  v[1]=3;

  v_1[1]=3;
  v_1[2]=5;

  sub=v-v_1;

  exp[0]=1;
  exp[1]=0;
  exp[2]=-5;
  exp[3]=0;

  EXPECT_EQ(exp,sub);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
  TVector<int> v(4);
  TVector<int> v_1(5);
  ASSERT_ANY_THROW(v-v_1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
  TVector<int> v(4);
  TVector<int> v_1(4);
  int mul;
  int exp=19;
  v[0]=1;
  v[1]=3;
  v[2]=2;

  v_1[1]=3;
  v_1[2]=5;

  mul=v*v_1;

  EXPECT_EQ(exp,mul);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
  TVector<int> v(4);
  TVector<int> v_1(5);
  ASSERT_ANY_THROW(v*v_1);
}

