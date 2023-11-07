#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m1(10);
	for (int i = 0; i < m1.size(); i++)
		for (int j = 0; j < m1.size(); j++)
			m1[i][j] = i + j;
	TDynamicMatrix<int> m2(m1);
	EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(m1);
	EXPECT_NE(&m1, &m2);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m1(10);
	EXPECT_EQ(m1.size(), 10);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m1(10);
	m1[0][0] = 1;
	EXPECT_EQ(m1[0][0], 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m1(10);
	EXPECT_ANY_THROW(m1[-1][-1] = 1);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m1(10);
	EXPECT_ANY_THROW(m1[11][11] = 1);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m1(10);
	EXPECT_NO_THROW(m1 = m1);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(10);
	EXPECT_NO_THROW(m2 = m1);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(20);
	m2 = m1;
	EXPECT_EQ(m2.size(), 10);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(20);
	EXPECT_NO_THROW(m2 = m1);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(10);
	EXPECT_EQ(true, m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m1(10);
	EXPECT_EQ(true, m1 == m1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(20);
	EXPECT_EQ(false, m1 == m2);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(10);
	for (int i = 0; i < m1.size(); i++)
		for (int j = 0; j < m1.size(); j++)
			m1[i][j] = i;
	TDynamicMatrix<int> m2(10);
	for (int i = 0; i < m2.size(); i++)
		for (int j = 0; j < m2.size(); j++)
			m2[i][j] = j;
	TDynamicMatrix<int> m3(10);
	for (int i = 0; i < m3.size(); i++)
		for (int j = 0; j < m3.size(); j++)
			m3[i][j] = i + j;
	EXPECT_EQ(m1 + m2, m3);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(20);
	EXPECT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2);
	for (int i = 0; i < m1.size(); i++)
		for (int j = 0; j < m1.size(); j++)
			m1[i][j] = 1;
	TDynamicMatrix<int> m2(2);
	for (int i = 0; i < m2.size(); i++)
		for (int j = 0; j < m2.size(); j++)
			m2[i][j] = 2;
	TDynamicMatrix<int> m3(2);
	for (int i = 0; i < m3.size(); i++)
		for (int j = 0; j < m3.size(); j++)
			m3[i][j] = 4;
	EXPECT_EQ(m1 * m2, m3);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(10);
	TDynamicMatrix<int> m2(20);
	EXPECT_ANY_THROW(m1 * m2);
}

