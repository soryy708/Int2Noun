#include "i2n.h"
#include <array>

const std::array<std::string, 10> digits =
{
	"zero",
	"one",
	"two",
	"three",
	"four",
	"five",
	"six",
	"seven",
	"eight",
	"nine"
};

const std::array<std::string, 9> from11to19 =
{
	"eleven",
	"twelve",
	"thirteen",
	"fourteen",
	"fifteen",
	"sixteen",
	"seventeen",
	"eighteen",
	"nineteen",
};

enum DecimalsIndex
{
	TEN,
	TWENTY,
	THIRTY,
	FORTY,
	FIFTY,
	SIXTY,
	SEVENTY,
	EIGHTY,
	NINETY,
	HUNDRED,
	THOUSAND,
	MILLION,
	COUNT
};
const std::array<std::string, DecimalsIndex::COUNT> decimals =
{
	"ten",
	"twenty",
	"thirty",
	"forty",
	"fifty",
	"sixty",
	"seventy",
	"eighty",
	"ninety",
	"hundred",
	"thousand",
	"million"
};

std::string i2n(int num)
{
	std::string noun = "";
	
	if (num < 0)
	{
		noun = "minus ";
		num *= -1;
	}

	if (num < 10)
		return noun + digits[num];
	const int tens = num / 10;
	if (tens > 0 && tens < 10 && (num  % 10 == 0))
		return noun + decimals[tens - 1];
	if (num < 20)
		return noun + from11to19[num - 11];
	if (num < 100)
		return i2n((num / 10) * 10) + " " + i2n(num % 10);

	const int millions = num / 1000000;
	if (millions > 0)
	{
		noun += i2n(millions) + " " + decimals[DecimalsIndex::MILLION] + " ";
	}
	num -= millions * 1000000;
	const int thousands = num / 1000;
	if (thousands > 0)
	{
		noun += i2n(thousands) + " " + decimals[DecimalsIndex::THOUSAND] + " ";
	}
	num -= thousands * 1000;
	const int hundreds = num / 100;
	if (hundreds > 0)
	{
		noun += i2n(hundreds) + " " + decimals[DecimalsIndex::HUNDRED] + " ";
	}
	num -= hundreds * 100;
	if (num > 0)
	{
		noun += "and " + i2n(num);
	}
	return noun;
}
