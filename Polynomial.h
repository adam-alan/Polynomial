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
	Polynomial();//无参构造函数
	Polynomial(const Polynomial & poly);//拷贝构造函数
	Polynomial(int n);//构造函数
	bool isEmpty()const;//判空
	void setPolynomial();//建立多项式
	void print()const;//遍历输出
	Polynomial operator + (Polynomial & poly);//重载“+”
	Polynomial operator - (Polynomial & poly);//重载“-”
	Polynomial operator * (Polynomial & poly);//重载“*”
	//Polynomial operator  (Polynomial & poly);//重载“*”
	virtual ~Polynomial();
protected:
	Polyn * addPolynomial(const Polyn* p1, const Polyn* p2);
	Polyn * subPolynomial(const Polyn* p1, Polyn* p2);
	Polyn * multPolynomial(const Polyn* p1, const Polyn* p2);
private:
	Polyn * head, *r;
};

