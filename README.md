# `sint` Class Documentation

## Overview

The `sint` class is designed to handle large integers. It supports basic arithmetic operations (addition, subtraction, multiplication, division), bitwise operations (AND, OR, left shift, right shift), and comparison operations. Additionally, two new methods, `to_n_HEX` and `HEX_in`, have been added to convert the large integer to a string in a specified base and vice versa.

## Class Definition

```cpp
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

class sint {
    string num;
    int size;
public:
    sint(string n = "0");  // Constructor with a default value of "0"

    int get_length() const;  // Returns the length of the large integer
    string get_value() const;  // Returns the string representation of the large integer

    void addition(string x);  // Adds x to the current large integer
    void addition(int x);  // Adds integer x to the current large integer
    void addition(sint x);  // Adds sint object x to the current large integer

    void subtract(string x);  // Subtracts x from the current large integer
    void subtract(int x);  // Subtracts integer x from the current large integer
    void subtract(sint x);  // Subtracts sint object x from the current large integer

    void multiplication(string x);  // Multiplies the current large integer by x
    void multiplication(int x);  // Multiplies the current large integer by integer x
    void multiplication(sint x);  // Multiplies the current large integer by sint object x

    void division(string divisor);  // Divides the current large integer by divisor
    void division(int divisor);  // Divides the current large integer by integer divisor
    void division(sint divisor);  // Divides the current large integer by sint object divisor

    sint& operator++();  // Pre-increment
    sint operator++(int);  // Post-increment
    sint& operator--();  // Pre-decrement
    sint operator--(int);  // Post-decrement

    sint operator+(const sint& other) const;  // Addition
    sint operator+(int other) const;  // Addition
    sint operator+(const string& other) const;  // Addition

    sint operator-(const sint& other) const;  // Subtraction
    sint operator-(int other) const;  // Subtraction
    sint operator-(const string& other) const;  // Subtraction

    sint operator*(const sint& other) const;  // Multiplication
    sint operator*(int other) const;  // Multiplication
    sint operator*(const string& other) const;  // Multiplication

    sint operator/(const sint& other) const;  // Division
    sint operator/(int other) const;  // Division
    sint operator/(const string& other) const;  // Division

    sint& operator+=(const sint& other);  // Addition assignment
    sint& operator+=(int other);  // Addition assignment
    sint& operator+=(const string& other);  // Addition assignment

    sint& operator-=(const sint& other);  // Subtraction assignment
    sint& operator-=(int other);  // Subtraction assignment
    sint& operator-=(const string& other);  // Subtraction assignment

    sint& operator*=(const sint& other);  // Multiplication assignment
    sint& operator*=(int other);  // Multiplication assignment
    sint& operator*=(const string& other);  // Multiplication assignment

    sint& operator/=(const sint& other);  // Division assignment
    sint& operator/=(int other);  // Division assignment
    sint& operator/=(const string& other);  // Division assignment

    sint operator&(const sint& other) const;  // Bitwise AND
    sint operator&(int other) const;  // Bitwise AND
    sint operator&(const string& other) const;  // Bitwise AND

    sint operator|(const sint& other) const;  // Bitwise OR
    sint operator|(int other) const;  // Bitwise OR
    sint operator|(const string& other) const;  // Bitwise OR

    sint operator%(const sint& other) const;  // Modulo
    sint operator%(int other) const;  // Modulo
    sint operator%(const string& other) const;  // Modulo

    sint operator<<(int shift) const;  // Left shift
    sint operator>>(int shift) const;  // Right shift

    bool operator==(const sint& other) const;  // Equality
    bool operator==(int other) const;  // Equality
    bool operator==(const string& other) const;  // Equality

    bool operator!=(const sint& other) const;  // Inequality
    bool operator!=(int other) const;  // Inequality
    bool operator!=(const string& other) const;  // Inequality

    bool operator<=(const sint& other) const;  // Less than or equal
    bool operator<=(int other) const;  // Less than or equal
    bool operator<=(const string& other) const;  // Less than or equal

    bool operator>=(const sint& other) const;  // Greater than or equal
    bool operator>=(int other) const;  // Greater than or equal
    bool operator>=(const string& other) const;  // Greater than or equal

    string to_n_HEX(int n) const;  // Converts the large integer to a string in the specified base
    void HEX_in(const string& n, int base);  // Converts a string in the specified base to a large integer
};
```
## Member Functions
### Constructor
- `sint(string n = "0")`: Constructor with a default value of "0".
### Get Length and Value
- `int get_length() const`: Returns the length of the large integer.
- `string get_value() const`: Returns the string representation of the large integer.
### Arithmetic Operations
- `void addition(string x)`: Adds x to the current large integer.
- `void addition(int x)`: Adds integer x to the current large integer.
- `void addition(sint x)`: Adds sint object x to the current large integer.
- `void subtract(string x)`: Subtracts x from the current large integer.
- `void subtract(int x)`: Subtracts integer x from the current large integer.
- `void subtract(sint x)`: Subtracts sint object x from the current large integer.
- `void multiplication(string x)`: Multiplies the current large integer by x.
- `void multiplication(int x)`: Multiplies the current large integer by integer x.
- `void multiplication(sint x)`: Multiplies the current large integer by sint object x.
- `void division(string divisor)`: Divides the current large integer by divisor.
- `void division(int divisor)`: Divides the current large integer by integer divisor.
- `void division(sint divisor)`: Divides the current large integer by sint object divisor.
### Increment and Decrement
- `sint& operator++()`: Pre-increment.
- `sint operator++(int)`: Post-increment.
- `sint& operator--()`: Pre-decrement.
- `sint operator--(int)`: Post-decrement.
### Arithmetic Operator Overloading
- `sint operator+(const sint& other) const`: Addition.
- `sint operator+(int other) const`: Addition.
- `sint operator+(const string& other) const`: Addition.
- `sint operator-(const sint& other) const`: Subtraction.
- `sint operator-(int other) const`: Subtraction.
- `sint operator-(const string& other) const`: Subtraction.
- `sint operator*(const sint& other) const`: Multiplication.
- `sint operator*(int other) const`: Multiplication.
- `sint operator*(const string& other) const`: Multiplication.
- `sint operator/(const sint& other) const`: Division.
- `sint operator/(int other) const`: Division.
- `sint operator/(const string& other) const`: Division.
### Arithmetic Assignment Operator Overloading
- `sint& operator+=(const sint& other)`: Addition assignment.
- `sint& operator+=(int other)`: Addition assignment.
- `sint& operator+=(const string& other)`: Addition assignment.
- `sint& operator-=(const sint& other)`: Subtraction assignment.
- `sint& operator-=(int other)`: Subtraction assignment.
- `sint& operator-=(const string& other)`: Subtraction assignment.
- `sint& operator*=(const sint& other)`: Multiplication assignment.
- `sint& operator*=(int other)`: Multiplication assignment.
- `sint& operator*=(const string& other)`: Multiplication assignment.
- `sint& operator/=(const sint& other)`: Division assignment.
- `sint& operator/=(int other)`: Division assignment.
- `sint& operator/=(const string& other)`: Division assignment.
### Bitwise Operations
- `sint operator&(const sint& other) const`: Bitwise AND.
- `sint operator&(int other) const`: Bitwise AND.
- `sint operator&(const string& other) const`: Bitwise AND.
- `sint operator|(const sint& other) const`: Bitwise OR.
- `sint operator|(int other) const`: Bitwise OR.
- `sint operator|(const string& other) const`: Bitwise OR.
- `sint operator%(const sint& other) const`: Modulo.
- `sint operator%(int other) const`: Modulo.
- `sint operator%(const string& other) const`: Modulo.
### Bit Shift Operations
- `sint operator<<(int shift) const`: Left shift.
- `sint operator>>(int shift) const`: Right shift.
### Comparison Operations
- `bool operator==(const sint& other) const`: Equality.
- `bool operator==(int other) const`: Equality.
- `bool operator==(const string& other) const`: Equality.
- `bool operator!=(const sint& other) const`: Inequality.
- `bool operator!=(int other) const`: Inequality.
- `bool operator!=(const string& other) const`: Inequality.
- `bool operator<=(const sint& other) const`: Less than or equal.
- `bool operator<=(int other) const`: Less than or equal.
- `bool operator<=(const string& other) const`: Less than or equal.
- `bool operator>=(const sint& other) const`: Greater than or equal.
- `bool operator>=(int other) const`: Greater than or equal.
- `bool operator>=(const string& other) const`: Greater than or equal.
### New Methods
`to_n_HEX(int n) const`
- #### Function: 
    - Converts the large integer to a string in the specified base.
- #### Parameters:
    - `int n`: The target base (2 to 36).
- #### Return Value: 
    - The converted string.
- #### Example:
```cpp
sint x;
x.HEX_in("1F", 16);
cout << "x from hex (16) '1F': " << x.get_value() << endl;  // Output: 31

x.HEX_in("77", 8);
cout << "x from octal (8) '77': " << x.get_value() << endl; // Output: 63

x.HEX_in("101010", 2);
cout << "x from binary (2) '101010': " << x.get_value() << endl; // Output: 42
```
## Example Code
```cpp
int main() {
    sint a("123456789");
    sint b("987654321");

    sint c = a + b;
    cout << "a + b = " << c.get_value() << endl;

    sint d = a - b;
    cout << "a - b = " << d.get_value() << endl;

    sint e = a * b;
    cout << "a * b = " << e.get_value() << endl;

    sint f = a / b;
    cout << "a / b = " << f.get_value() << endl;

    sint g = a % b;
    cout << "a % b = " << g.get_value() << endl;

    sint h = a << 2;
    cout << "a << 2 = " << h.get_value() << endl;

    sint i = a >> 2;
    cout << "a >> 2 = " << i.get_value() << endl;

    cout << "a == b: " << boolalpha << (a == b) << endl;
    cout << "a != b: " << boolalpha << (a != b) << endl;
    cout << "a <= b: " << boolalpha << (a <= b) << endl;
    cout << "a >= b: " << boolalpha << (a >= b) << endl;

    a += 5;
    cout << "a += 5: " << a.get_value() << endl;

    a -= 3;
    cout << "a -= 3: " << a.get_value() << endl;

    a *= 2;
    cout << "a *= 2: " << a.get_value() << endl;

    a /= 2;
    cout << "a /= 2: " << a.get_value() << endl;

    a &= 100;
    cout << "a &= 100: " << a.get_value() << endl;

    a |= 200;
    cout << "a |= 200: " << a.get_value() << endl;

    a <<= 2;
    cout << "a <<= 2: " << a.get_value() << endl;

    a >>= 2;
    cout << "a >>= 2: " << a.get_value() << endl;

    // Test to_n_HEX
    cout << "a to hex (16): " << a.to_n_HEX(16) << endl;
    cout << "a to octal (8): " << a.to_n_HEX(8) << endl;
    cout << "a to binary (2): " << a.to_n_HEX(2) << endl;

    // Test HEX_in
    sint x;
    x.HEX_in("1F", 16);
    cout << "x from hex (16) '1F': " << x.get_value() << endl;

    x.HEX_in("77", 8);
    cout << "x from octal (8) '77': " << x.get_value() << endl;

    x.HEX_in("101010", 2);
    cout << "x from binary (2) '101010': " << x.get_value() << endl;

    return 0;
}
```
