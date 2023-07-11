#include <iostream>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction operator + (Fraction other)
	{
		int finnumerator=numerator_*other.denominator_+other.numerator_*denominator_;
		int findenominator=denominator_*other.denominator_;
		Fraction fin(finnumerator, findenominator);
		fin.reduce();

		return fin;
	}

	Fraction operator - (Fraction other)
	{
		int finnumerator = numerator_ * other.denominator_ - other.numerator_ * denominator_;
		int findenominator = denominator_ * other.denominator_;
		Fraction fin(finnumerator, findenominator);
		fin.reduce();

		return fin;
	}

	Fraction operator * (Fraction other)
	{
		int finnumerator = numerator_ * other.numerator_;
		int findenominator = denominator_ * other.denominator_;

		Fraction fin(finnumerator, findenominator);
		fin.reduce();

		return fin;
	}


	Fraction operator / (Fraction other)
	{
		int finnumerator = numerator_ * other.denominator_;
		int findenominator = denominator_ * other.numerator_;

		Fraction fin(finnumerator, findenominator);
		fin.reduce();

		return fin;
	}

	Fraction operator ++ ()
	{
		numerator_ += denominator_;

		Fraction fin(numerator_, denominator_);
		fin.reduce();

		return fin;
	}

	Fraction operator -- ()
	{
		numerator_ -= denominator_;

		Fraction fin(numerator_, denominator_);
		fin.reduce();

		return fin;
	}

	Fraction operator ++ (int)
	{

		Fraction temp =*this;

		++(*this);

		temp.reduce();

		return temp;
	}

	Fraction operator -- (int)
	{

		Fraction temp = *this;

		--(*this);

		temp.reduce();

		return temp;
	}

	Fraction operator -() {

		return Fraction(-numerator_, denominator_);
	}

	void reduce()
	{
		int nod = CalcNOD(numerator_, denominator_);
		numerator_ /= nod;
		denominator_ /= nod;

	}

	int CalcNOD(int nume, int denom) {

		if (denom == 0) {
			return nume;
		}
		else
			return CalcNOD(denom, nume % denom);
	}

	void print() const
	{
		std::cout << numerator_ << "/" << denominator_ << '\n';
	}
	
	void demonstrate(Fraction f1, Fraction f2) {

		std::cout << std::endl;

		std::cout << "��������: ";
		Fraction f3 = f1 + f2;
		f3.print();
		std::cout << "���������: ";
		f3 = f1 - f2;
		f3.print();
		std::cout << "���������: ";
		f3 = f1 * f2;
		f3.print();
		std::cout << "�������: ";
		f3 = f1 / f2;
		f3.print();
		std::cout << "����������� ���������: ";
		f3 = f1++ * f2;
		f3.print();
		std::cout << " �������� ����� 1: " << f1.numerator_ << "/" << f1.denominator_ << std::endl;
		std::cout << "���������� ���������: ";
		f3 = ++f1 * f2;
		f3.print();
		std::cout << " �������� ����� 1: " << f1.numerator_ << "/" << f1.denominator_ << std::endl;
		std::cout << "����������� ���������: ";
		f3 = f1-- * f2;
		f3.print();
		std::cout << " �������� ����� 1: " << f1.numerator_ << "/" << f1.denominator_ << std::endl;
		std::cout << "���������� ���������: ";
		f3 = --f1 * f2;
		f3.print();
		std::cout << " �������� ����� 1: " << f1.numerator_ << "/" << f1.denominator_ << std::endl;
		std::cout << "������� �����: ";
		f3=-f1;
		f3.print();
		
		std::cout << std::endl;
	}
};

int main() {

setlocale(LC_ALL, "Russian");

	int a;
	int b;
	int c;
	int d;
	std::string end;

	Fraction f3(0,0);

	for (; ; ) {

		std::cout << "������� ��������� ����� 1: ";
		std::cin >> a;
		std::cout << "������� ����������� ����� 1: ";
		std::cin >> b;
		std::cout << "������� ��������� ����� 2: ";
		std::cin >> c;
		std::cout << "������� ����������� ����� 2: ";
		std::cin >> d;

		Fraction f1(a, b);
		Fraction f2(c, d);

		f3.demonstrate(f1, f2);

		std::cout << "���� ������ ���������, ������� r, ����� ��������� ������ ����� �����: ";
		std::cin >> end;

		if (end != "r") {
			break;
		}
		std::cout << std::endl;
	}

	return 0;
}