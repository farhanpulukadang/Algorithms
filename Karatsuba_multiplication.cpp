//Karatsuba Multiplication
//Farhan U. Pulukadang
#include <iostream>
#include <cstdint>
#include <cmath>
#include <string>
#include <algorithm>
#include <deque>
#define integer deque<uint32_t>
using namespace std;
uint32_t B = 10;
integer to_vect(uint32_t input) {
	integer result;
	int n = to_string(input).size();
	for (int i = 0; i != n; i++) {
		uint32_t in = input / pow(B, n - i - 1);
		result.emplace_back(in);
		input -= in * pow(B, n - i - 1);
	}
	return result;
}
void eq(integer& a, integer& b) {
	while (a.size() != b.size()) {
		if (a.size() > b.size()) {
			b.insert(b.begin(), 0);
		}
		else {
			a.insert(a.begin(), 0);
		}
	}
	if (a.size() % 2 != 0) {
		a.insert(a.begin(), 0);
		b.insert(b.begin(), 0);
	}
}
integer add(integer a, integer b) {
	eq(a, b);
	integer result(a.size() + 1);
	for (int i = 0; i != a.size(); i++) {
		uint32_t c = (a[i] + b[i])/B, s = a[i] + b[i] - B*c;
		result[i + 1] += s;
		result[i] += c;
	}
	return result;
}
integer multip(integer a, integer b) {
	integer result(a.size() + b.size());
	for (int i = a.size() - 1; i != -1; i--) {
		for (int j = b.size() - 1; j != -1; j--) {
			uint32_t c = (a[i] * b[j]) / B, s = (a[i] * b[j]) - B * c;
			result[i + j + 1] += s;
			result[i + j] += c + result[i + j + 1]/B;
			result[i + j + 1] = result[i + j + 1] % B;
		}
	}
	for (int i : result) {
		cout << i;
	}
	cout << endl;
	return result;
}
integer Karatsuba(integer a, integer b) {
	eq(a, b);
	if (a.size() < 4) {
		return multip(a, b);
	}
	else {
		uint32_t n = a.size();
		integer a0(a.begin(), a.begin() + n / 2), a1(a.begin() + n / 2, a.end()),
			b0(b.begin(), b.begin() + n / 2), b1(b.begin() + n / 2, b.end()),
			p0 = Karatsuba(a0, b0), p2 = Karatsuba(a1, b1), A = add(Karatsuba(a0, b1), Karatsuba(a1, b0));
		integer result(2 * n);
		for (int i = 0; i != n; i++) {
			p0.emplace_back(0);
		}
		for (int i = 0; i != n/2; i++) {
			A.emplace_back(0);
		}
		return add(p2, add(A, p0));
	}
}
int main() {
	integer a = to_vect(1234567), b = to_vect(1234567), res = Karatsuba(a, b);
	for (auto i : res) {
		cout << i;
	}
	cout << endl;
	cout << (long long)pow(1234567, 2) << endl;
	return 0;
}