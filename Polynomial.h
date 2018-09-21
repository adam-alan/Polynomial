#pragma once

typedef struct member
{
	int coef;
	int expn;
	struct member *next;
}Polyn;

class Polynomial
{
public:
	Polynomial();//�޲ι��캯��
	Polynomial(const Polynomial & poly);//�������캯��
	Polynomial(int n);//���캯��
	bool isEmpty()const;//�п�
	void setPolynomial();//��������ʽ
	void print()const;//�������
	Polynomial operator + (Polynomial & poly);//���ء�+��
	Polynomial operator - (Polynomial & poly);//���ء�-��
	Polynomial operator * (Polynomial & poly);//���ء�*��
	//Polynomial operator  (Polynomial & poly);//���ء�*��
	virtual ~Polynomial();
protected:
	Polyn * addPolynomial(const Polyn* p1, const Polyn* p2);
	Polyn * subPolynomial(const Polyn* p1, Polyn* p2);
	Polyn * multPolynomial(const Polyn* p1, const Polyn* p2);
private:
	Polyn * head, *r;
};

