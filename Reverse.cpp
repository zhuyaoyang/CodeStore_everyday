//main.cpp
#include <iostream>
using namespace std;

int reverse(int x) {
	int a[10];
	int i = 0, k = 0;
	double j = 0;
	while (x / 10) {
		a[i++] = x % 10;
		x = x / 10;
	}
	a[i] = x;
	for (i; i >= 0; i--) {
		j += a[i] * pow(10, k++);
	}
	if (j >= pow(2, 31) || j < (-pow(2, 31))) return 0;
	else return j;
}

int main() {
	cout << reverse(-128289310);
	system("pause");
}
