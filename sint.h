#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class sint {
    string num;
    int size;
public:
    sint(string n = "0") : num(n), size(n.size()) {}

    int get_length() const {
        return size;
    }

    string get_value() const {
        return num;
    }

    void addition(string x) {
        string temp = num;
        string xStr = x;
        reverse(temp.begin(), temp.end());
        reverse(xStr.begin(), xStr.end());
        int carry = 0;
        string result;
        for (size_t i = 0; i < temp.size() || i < xStr.size(); ++i) {
            int n1 = i < temp.size() ? temp[i] - '0' : 0;
            int n2 = i < xStr.size() ? xStr[i] - '0' : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            result.push_back(sum % 10 + '0');
        }
        if (carry > 0) {
            result.push_back(carry + '0');
        }
        reverse(result.begin(), result.end());
        num = result;
    }

    void addition(int x) {
        addition(to_string(x));
    }

    void addition(sint x) {
        addition(x.get_value());
    }

    void subtract(string x) {
        string temp = num;
        string xStr = x;
        reverse(temp.begin(), temp.end());
        reverse(xStr.begin(), xStr.end());
        string result;
        int borrow = 0;
        for (size_t i = 0; i < temp.size() || i < xStr.size(); ++i) {
            int n1 = i < temp.size() ? temp[i] - '0' : 0;
            int n2 = i < xStr.size() ? xStr[i] - '0' : 0;
            int diff = n1 - n2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.push_back(diff + '0');
        }
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }
        if (result.empty()) {
            result = "0";
        }
        reverse(result.begin(), result.end());
        num = result;
    }

    void subtract(int x) {
        subtract(to_string(x));
    }

    void subtract(sint x) {
        subtract(x.get_value());
    }

    void multiplication(string x) {
        string temp = num;
        string xStr = x;
        reverse(temp.begin(), temp.end());
        reverse(xStr.begin(), xStr.end());
        string result(temp.size() + xStr.size(), '0');

        for (size_t i = 0; i < temp.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < xStr.size() || carry > 0; ++j) {
                int n1 = i < temp.size() ? temp[i] - '0' : 0;
                int n2 = j < xStr.size() ? xStr[j] - '0' : 0;
                int product = n1 * n2 + carry + (result[i + j] - '0');
                carry = product / 10;
                result[i + j] = product % 10 + '0';
            }
        }

        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }

        if (result.empty()) {
            result = "0";
        }

        reverse(result.begin(), result.end());
        num = result;
    }

    void multiplication(int x) {
        multiplication(to_string(x));
    }

    void multiplication(sint x) {
        multiplication(x.get_value());
    }

    void division(string divisor) {
        string dividend = num;
        string quotient;
        string remainder = "0";

        while (dividend >= divisor) {
            int index = 0;
            while (index < dividend.size() && dividend.substr(0, index + 1) < divisor) {
                ++index;
            }
            string subDividend = dividend.substr(0, index + 1);
            int count = 0;
            while (subDividend >= divisor) {
                subDividend = to_string(stoi(subDividend) - stoi(divisor));
                ++count;
            }
            quotient += to_string(count);
            dividend = subDividend + dividend.substr(index + 1);
        }

        while (!dividend.empty() && dividend.back() == '0') {
            dividend.pop_back();
        }

        if (dividend.empty()) {
            dividend = "0";
        }

        num = quotient;
    }

    void division(int divisor) {
        division(to_string(divisor));
    }

    void division(sint divisor) {
        division(divisor.get_value());
    }

    sint& operator++() {
        addition("1");
        return *this;
    }

    sint operator++(int) {
        sint temp(*this);
        addition("1");
        return temp;
    }

    sint& operator--() {
        subtract("1");
        return *this;
    }

    sint operator--(int) {
        sint temp(*this);
        subtract("1");
        return temp;
    }
\
    sint operator+(const sint& other) const {
        sint result(*this);
        result.addition(other.get_value());
        return result;
    }

    sint operator+(int other) const {
        sint result(*this);
        result.addition(other);
        return result;
    }

    sint operator+(const string& other) const {
        sint result(*this);
        result.addition(other);
        return result;
    }

    sint operator-(const sint& other) const {
        sint result(*this);
        result.subtract(other.get_value());
        return result;
    }

    sint operator-(int other) const {
        sint result(*this);
        result.subtract(other);
        return result;
    }

    sint operator-(const string& other) const {
        sint result(*this);
        result.subtract(other);
        return result;
    }

    sint operator*(const sint& other) const {
        sint result(*this);
        result.multiplication(other.get_value());
        return result;
    }

    sint operator*(int other) const {
        sint result(*this);
        result.multiplication(other);
        return result;
    }

    sint operator*(const string& other) const {
        sint result(*this);
        result.multiplication(other);
        return result;
    }

    sint operator/(const sint& other) const {
        sint result(*this);
        result.division(other.get_value());
        return result;
    }

    sint operator/(int other) const {
        sint result(*this);
        result.division(other);
        return result;
    }

    sint operator/(const string& other) const {
        sint result(*this);
        result.division(other);
        return result;
    }

    sint& operator+=(const sint& other) {
        addition(other.get_value());
        return *this;
    }

    sint& operator+=(int other) {
        addition(other);
        return *this;
    }

    sint& operator+=(const string& other) {
        addition(other);
        return *this;
    }

    sint& operator-=(const sint& other) {
        subtract(other.get_value());
        return *this;
    }

    sint& operator-=(int other) {
        subtract(other);
        return *this;
    }

    sint& operator-=(const string& other) {
        subtract(other);
        return *this;
    }

    sint& operator*=(const sint& other) {
        multiplication(other.get_value());
        return *this;
    }

    sint& operator*=(int other) {
        multiplication(other);
        return *this;
    }

    sint& operator*=(const string& other) {
        multiplication(other);
        return *this;
    }

    sint& operator/=(const sint& other) {
        division(other.get_value());
        return *this;
    }

    sint& operator/=(int other) {
        division(other);
        return *this;
    }

    sint& operator/=(const string& other) {
        division(other);
        return *this;
    }

    sint operator&(const sint& other) const {
        sint result(min(num, other.num));
        return result;
    }

    sint operator&(int other) const {
        sint result(*this);
        result.num = min(num, to_string(other));
        return result;
    }

    sint operator&(const string& other) const {
        sint result(*this);
        result.num = min(num, other);
        return result;
    }

    sint operator|(const sint& other) const {
        sint result(max(num, other.num));
        return result;
    }

    sint operator|(int other) const {
        sint result(*this);
        result.num = max(num, to_string(other));
        return result;
    }

    sint operator|(const string& other) const {
        sint result(*this);
        result.num = max(num, other);
        return result;
    }

    sint operator%(const sint& other) const {
        sint result(*this);
        result.division(other.get_value());
        return result;
    }

    sint operator%(int other) const {
        sint result(*this);
        result.division(other);
        return result;
    }

    sint operator%(const string& other) const {
        sint result(*this);
        result.division(other);
        return result;
    }

    sint operator<<(int shift) const {
        string result = num + string(shift, '0');
        return sint(result);
    }

    sint operator>>(int shift) const {
        if (shift >= num.size()) {
            return sint("0");
        }
        string result = num.substr(0, num.size() - shift);
        return sint(result);
    }

    bool operator==(const sint& other) const {
        return num == other.num;
    }

    bool operator==(int other) const {
        return num == to_string(other);
    }

    bool operator==(const string& other) const {
        return num == other;
    }

    bool operator!=(const sint& other) const {
        return num != other.num;
    }

    bool operator!=(int other) const {
        return num != to_string(other);
    }

    bool operator!=(const string& other) const {
        return num != other;
    }

    bool operator<=(const sint& other) const {
        return num <= other.num;
    }

    bool operator<=(int other) const {
        return num <= to_string(other);
    }

    bool operator<=(const string& other) const {
        return num <= other;
    }

    bool operator>=(const sint& other) const {
        return num >= other.num;
    }

    bool operator>=(int other) const {
        return num >= to_string(other);
    }

    bool operator>=(const string& other) const {
        return num >= other;
    }

    string to_n_HEX(int n) const {
        if (n < 2 || n > 36) {
            throw invalid_argument("Base must be between 2 and 36");
        }
        string result;
        long long value = stoll(num);
        while (value > 0) {
            int digit = value % n;
            if (digit < 10) {
                result.push_back('0' + digit);
            } else {
                result.push_back('A' + (digit - 10));
            }
            value /= n;
        }
        if (result.empty()) {
            result = "0";
        }
        reverse(result.begin(), result.end());
        return result;
    }

    void HEX_in(const string& n, int base) {
        if (base < 2 || base > 36) {
            throw invalid_argument("Base must be between 2 and 36");
        }
        long long value = 0;
        for (char c : n) {
            int digit;
            if ('0' <= c && c <= '9') {
                digit = c - '0';
            } else if ('A' <= c && c <= 'Z') {
                digit = 10 + (c - 'A');
            } else if ('a' <= c && c <= 'z') {
                digit = 10 + (c - 'a');
            } else {
                throw invalid_argument("Invalid character in input string");
            }
            if (digit >= base) {
                throw invalid_argument("Digit exceeds base");
            }
            value = value * base + digit;
        }
        num = to_string(value);
    }
};
