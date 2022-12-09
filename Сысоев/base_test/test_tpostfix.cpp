#include "postfix.h"
#include <gtest.h>

TEST(ArithmeticExpression, can_create_postfix)
{
  ASSERT_NO_THROW(ArithmeticExpression A("1+2/3"));
}
TEST(ArithmeticExpression, can_convert_to_postfix)
{
	ArithmeticExpression A("1+2/3-12+(3*5)/(15*1)");
	ASSERT_NO_THROW( A.GetPostfix());
}
TEST(ArithmeticExpression, works_currently)
{
	ArithmeticExpression A("1+(3*5)/(15*1)");
	ASSERT_EQ(A.calc(), 2);
}
TEST(ArithmeticExpression, can_get_infix_form)
{

	ArithmeticExpression A("1+(3*5)/(15*1)");
	ASSERT_EQ("1+(3*5)/(15*1)", A.GetInfix());
}
TEST(ArithmeticExpression, can_get_postfix_form)
{
	ArithmeticExpression A("1+2/3-12+(3*5)/(15*1)");
	ASSERT_EQ("1 2 3 /+12 -3 5 *15 1 */+", A.GetPostfix());

}
TEST(ArithmeticExpression, can_parse_digits)
{

	ArithmeticExpression A("1241     ");
	ASSERT_EQ(A.calc(), 1241);
}
TEST(ArithmeticExpression, can_parse_with_brackets)
{
	ArithmeticExpression A("12+(1+4)/5");
	ASSERT_EQ(A.GetInfix(), "12+(1+4)/5");

}
TEST(ArithmeticExpression, can_add)
{
	ArithmeticExpression A("2+8");
	ASSERT_EQ(10.0, A.calc());

}
TEST(ArithmeticExpression, can_div)
{
	ArithmeticExpression A("20/2");
	ASSERT_EQ(10.0, A.calc());

}
TEST(ArithmeticExpression, can_mult)
{
	ArithmeticExpression A("5*2");
	ASSERT_EQ(10.0, A.calc());

}
TEST(ArithmeticExpression, can_sub)
{
	ArithmeticExpression A("12-2");
	ASSERT_EQ(10.0, A.calc());

}
TEST(ArithmeticExpression, can_make_number_from_str)
{
	string s("ahb 123jf");
	ArithmeticExpression A(s);
	ASSERT_EQ(A.calc(), 123);

}
TEST(ArithmeticExpression, can_get_postfix_different_priority)
{
	ArithmeticExpression A("10-(3*5)/(20-5)+(3-22/11)");
	ASSERT_EQ(10.0, A.calc());

}
TEST(ArithmeticExpression, throws_with_troubles_with_brackets)
{
	ASSERT_ANY_THROW(ArithmeticExpression A("((1+34"));

}

TEST(ArithmeticExpression, checking_of_constructor)
{
	ASSERT_NO_THROW(ArithmeticExpression A("12+1238-(228-135)/12"));

}