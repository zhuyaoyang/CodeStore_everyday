#include<iostream>
using namespace std;

class Complex {
private:
	double real;
	double image;
public:
	Complex();
	Complex(double i);
	Complex(double i, double j);

	Complex operator + (double &i);
	Complex operator + (Complex &f);
	friend Complex operator + (double &i, Complex &f);
	Complex operator * (double &i);
	Complex operator * (Complex &f);
	friend Complex operator * (double &i, Complex &f);
	Complex operator / (double &i);
	Complex operator / (Complex &f);
	friend Complex operator / (double &i, Complex &f);
	friend istream& operator >> (istream& input, Complex &f);
	friend ostream& operator << (ostream& output, Complex &f);
};

Complex::Complex() {
	real = 0;
	image = 0;
}
Complex::Complex(double i) {
	real = i;
	image = 0;
}
Complex::Complex(double i, double j) {
	real = i;
	image = j;
}
Complex Complex::operator+(double &i) {
	return Complex(real + i, image);
}
Complex Complex::operator+(Complex &f) {
	return Complex(real + f.real, image+f.image);
}
Complex operator + (double &i, Complex &f) {
	return Complex(i+ f.real, f.image);
}
Complex Complex::operator * (double &i) {
	return Complex(real*i,image*i);
}
Complex Complex::operator * (Complex &f) {
	return Complex(real*f.real-image*f.image,real*f.image+image*f.real);
}
Complex operator * (double &i, Complex &f) {
	return Complex(i*f.real,i*f.image);
}
Complex Complex::operator / (double &i) {
	return Complex(real/i, image/i);
}
Complex Complex::operator / (Complex &f) {
	Complex C;
	C.real = (real * f.real + image * f.image) / (f.real*f.real + f.image*f.image);
	C.image = (image * f.real-real * f.image )/ (f.real*f.real + f.image*f.image);
	return C;
}
Complex operator / (double &i, Complex &f) {
	Complex C;
	C.real= i*f.real / (f.real*f.real + f.image*f.image);
	C.image = -i * f.image / (f.real*f.real + f.image*f.image);
	return C;
}
istream& operator >> (istream& input, Complex &f) {
	cout << "�����븴����ʵ�����鲿:";
	input >> f.real >> f.image;
	return input;
}
ostream& operator << (ostream& output, Complex &f) {
	if(f.image>0) output <<"("<< f.real << "+" << f.image << "i" <<")";
	else if (f.image == 0) output << "(" << f.real << ")";
	else output << "(" << f.real << f.image << "i" << ")";
	return output;
}

int main() {
	double d=3;
	Complex a,b(6),c(1,2),e;
	cout << "������������";
	cout << a <<","<< b << "," << c<<endl;
	cout << "����a��ֵ��";
	cin >> a;
	cout <<"a="<<a<<endl;
	cout << "�������������������" << endl;
	e = c + a;
	cout << c << "+" << a << "=" << e << endl;
	e = c * a;
	cout << c << "*" << a << "=" << e << endl;
	e = c / a;
	cout << c << "/" << a << "=" << e << endl;
	cout << "������ʵ�������������" << endl;
	e = c + d;
	cout << c << "+" << d << "=" << e << endl;
	e = c * d;
	cout << c << "*" << d << "=" << e << endl;
	e = c / d;
	cout << c << "/" << d << "=" << e << endl;
	cout << "��ʵ���Ҹ��������������" << endl;
	e = d + c;
	cout << d << "+" << c << "=" << e << endl;
	e = d * c;
	cout << d << "*" << c << "=" << e << endl;
	e = d / c;
	cout << d << "/" << c << "=" << e << endl;
	system("pause");
}