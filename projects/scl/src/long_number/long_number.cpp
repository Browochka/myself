#include "long_number.hpp"

namespace IBusko {
	LongNumber::LongNumber() {
		length = 0;
		sign = POSITIVE;
		numbers = nullptr;
	}

	LongNumber::LongNumber(const char* const str) {
		length = get_length(str);
		int* alt = new int[length];
		int x = 0;
		sign = POSITIVE;
		if (*(str) == '-') {
			x = 1;
			sign = NEGATIVE;
			length -= 1;
		};
		for (x; x < length; x++) {
			*(alt + x) = *(str + x) - '0';
		};
		numbers = alt;
	}

	LongNumber::LongNumber(const LongNumber& x) {
		numbers = x.numbers;
		length = x.length;
		sign = x.sign;
	}

	LongNumber::LongNumber(LongNumber&& x) :
		numbers(x.numbers),
		length(x.length),
		sign(x.sign)
	{
		x.numbers = new int[1];
		x.numbers[0] = 0;
		x.length = 1;
		x.sign = POSITIVE;
	}

	LongNumber::~LongNumber() {
		sign = POSITIVE;
		length = 0;
		if (numbers != nullptr) {
			delete[] numbers;
		}
	}

	LongNumber& LongNumber::operator = (const char* const str) {
	    LongNumber x(str);
		this->numbers = x.numbers;
		this->sign = x.sign;
		this->length = x.length;
		return *this;
	}

	LongNumber& LongNumber::operator = (const LongNumber& x) {
		this->numbers = x.numbers;
		this->sign = x.sign;
		this->length = x.length;
		return *this;
	}

	LongNumber& LongNumber::operator = (LongNumber&& x) {
		sign = x.sign;
		length = x.length;
		if (numbers != nullptr) {
			delete[] numbers;
		}
		numbers = x.numbers;
		x.numbers = nullptr;
		return *this;
	}

	bool LongNumber::operator == (const LongNumber& x) {
		if (this->length != x.length) {
			return false;
		}
		if (this->sign > x.sign) {
			return false;
		}
		for (int i = 0; i < this->length; i++) {
			if (*(x.numbers + i) != *(this->numbers + i)) {
				return false;
			}
		}
		return true;
	}

	bool LongNumber::operator > (const LongNumber& x) {
		if (this->sign > x.sign) {
			return true;
		}
		if (this->length < x.length) {
			return false;
		}
		else if (this->length > x.length) {
			return true;
		}
		for (int i = 0; i < this->length; i++) {
			if (*(this->numbers + i) < *(x.numbers + i)) {
				return false;
			}
		}
		return true;
	}

	bool LongNumber::operator < (const LongNumber& x) {
		if (this->sign > x.sign) {
			return false;
		}
		if (this->length > x.length) {
			return false;
		}
		else if (this->length < x.length) {
			return true;
		}
		for (int i = 0; i < this->length; i++) {
			if (*(this->numbers + i) > *(x.numbers + i)) {
				return false;
			}
		}
		return true;
	
	}

	LongNumber LongNumber::operator + (const LongNumber& x) {
		int maxlen;
		LongNumber result;

		if (this->sign != x.sign) {
			if (x.sign == NEGATIVE) {
				result = (*this - x);
				return result;
			}
			else {
				LongNumber temp = x;
				result = temp - *this;
				return (result);
			}
		}
		int temp_length = std::max(length, x.length) + 1;
		int* temp = new int[temp_length];
		bool x_is_longest = (x.length > length);
		int carry = 0; 
		int min = std::min(length, x.length) - 1;
		for (int i = std::max(length, x.length); i > 0; --i) { 
			if (min >= 0) {
				if (x_is_longest) {
					temp[i] = (numbers[min] + carry + x.numbers[i - 1]) % 10;
					carry = (carry + numbers[min] + x.numbers[i - 1] >= 10);
				}
				else {
					temp[i] = (x.numbers[min] + carry + numbers[i - 1]) % 10;
					carry = (carry + x.numbers[min] + numbers[i - 1] >= 10);
				}
				min--;
			}
			else {
				if (x_is_longest) {
					temp[i] = (carry + x.numbers[i - 1]) % 10;
					carry = (carry + x.numbers[i - 1] >= 10);
				}
				else {
					temp[i] = (carry + numbers[i - 1]) % 10;
					carry = ((carry + numbers[i - 1]) >= 10);
				}
			}
		}
		temp[0] = carry;
		bool first_digit_is_zero = (temp[0] == 0);
		result.length = (first_digit_is_zero) ? (temp_length - 1) : temp_length;
		result.numbers = new int[result.length];
		result.sign = x.sign;
		for (int i = 0; i < result.length; i++) {
			result.numbers[i] = temp[i + first_digit_is_zero];
		}
		delete[] temp;
		return result;
	}

	LongNumber LongNumber::operator - (const LongNumber& x) {
		LongNumber result;
		if (*this == x) {
			result = LongNumber("0");
			return result;
		}
		if (sign != x.sign) {
			LongNumber temp = x;
			temp.sign = -temp.sign;
			result = temp + *this;
			return (result);
		}
		LongNumber minuend;
		bool abs_x_is_bigger;
		if (sign == POSITIVE) {
			if (*this > x) {
				result.sign = POSITIVE;
				minuend = *this;
				abs_x_is_bigger = false;
			}
			else {
				result.sign == NEGATIVE;
				minuend = x;
				abs_x_is_bigger = true;
			}
		}
		else {
			if (*this > x) {
				result.sign = POSITIVE;
				minuend = x;
				abs_x_is_bigger = true;
			}
			else {
				result.sign == NEGATIVE;
				minuend = *this;
				abs_x_is_bigger = false;
			}
		}
		result.sign = (abs_x_is_bigger) ? -x.sign : sign;
		int* subtrahend = new int[minuend.length];
		int shortest_length = (abs_x_is_bigger) ? (length) : x.length;
		for (int i = 0; i < minuend.length - shortest_length; i++) {
			subtrahend[i] = 0;
		}
		for (int i = minuend.length - shortest_length, k = 0; k < shortest_length; k++, i++) {
			subtrahend[i] = (abs_x_is_bigger) ? (*this).numbers[k] : x.numbers[k];
		}
		int carry = 0;
		for (int i = minuend.length - 1; i >= 0; i--) {
			bool next_carry = (subtrahend[i] + carry) > minuend.numbers[i];
			if (next_carry == 1) {
				minuend.numbers[i] += 10;
			}
			minuend.numbers[i] -= subtrahend[i] + carry;
			carry = next_carry;
		}
		int i = 0;
		while (minuend.numbers[i] == 0) { i++; };
		result.length = minuend.length - i;
		int* temp = new int[result.length];

		int j = 0;
		while (i < minuend.length) {
			temp[j] = minuend.numbers[i];
			j++;
			i++;
		};
		delete[] subtrahend;
		result.numbers = temp;
		temp = nullptr;
		return (result);
	}

	LongNumber LongNumber::operator * (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}

	LongNumber LongNumber::operator / (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}

	LongNumber LongNumber::operator % (const LongNumber& x) {
		// TODO
		LongNumber result;
		return result;
	}

	int LongNumber::get_digits_number() const {
		return length;
	}

	bool LongNumber::is_positive() const {
		return sign == POSITIVE;
	}
	void LongNumber::print() const {
		if (this->sign ==NEGATIVE)
			std::cout << MINUS;

		for (int i = 0; i < length; ++i)
			std::cout << numbers[i];
	}

	// ----------------------------------------------------------
	// PRIVATE
	// ----------------------------------------------------------
	int LongNumber::get_length(const char* const str) const { 
		
		const char* s = str;
		while (*s) {
			++s;
		}

		return (s - str);
		
	}

	// ----------------------------------------------------------
	// FRIENDLY
	// ----------------------------------------------------------
	std::ostream& operator << (std::ostream& os, const LongNumber& x) {
		// TODO
		return os;
	}
}
