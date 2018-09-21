#include "Polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial()
{
	this->head = new Polyn();
	r = head;
	head->next = nullptr;
}

Polynomial::Polynomial(const Polynomial & poly)
{
	this->head = poly.head;
	this->r = poly.r;
}

Polynomial::Polynomial(int n)
{
	Polyn * pTemp = nullptr;
	while (n--)
	{
		pTemp = new Polyn();
		r->next = pTemp;
		r = pTemp;
	}
	r->next = nullptr;
}

bool Polynomial::isEmpty()const
{
	if (this->head->next)
	{
		return false;
	}
	return true;
}

void Polynomial::setPolynomial()
{
	Polyn *pTemp = nullptr;
	while (true)
	{
		pTemp = new Polyn();
		cin >> pTemp->coef;
		cin >> pTemp->expn;
		if (pTemp->coef == 0 &&
				pTemp->expn == 0)
		{
			this->r->next = nullptr;
			delete pTemp;
			break;
		}
		else
		{
			this->r->next = pTemp;
			this->r = pTemp;
		}
	}
}

void Polynomial::print()const
{
	Polyn * pTemp = head->next;
	int flag = 1;
	if (isEmpty())
	{
		cout << left << "0" << endl;
	}
	while (pTemp)
	{
		if (pTemp->coef > 0 && flag++ != 1)
		{
			cout << left << "+";
		}

		if (pTemp->coef != 1 && pTemp->coef != -1)
		{
			cout << left << pTemp->coef;

			if (pTemp->expn == 1)
			{
				cout << left << "X";
			}
			else if(pTemp->expn > 1)
			{
				cout << left << "X^" << pTemp->expn;
			}
		}
		else
		{
			if (pTemp->coef== 1)
			{
				if (pTemp->expn == 0)
				{
					cout << pTemp->coef;
				}
				if (pTemp->expn == 1)
				{
					cout << left << "X";
				}
				else if(pTemp->expn > 1)
				{
					cout << left << "X^" <<pTemp->expn;
				}
			}
			if (pTemp->coef == -1)
			{
				if (pTemp->expn == 0)
				{
					cout << pTemp->coef;
				}
				if (pTemp->expn == 1)
				{
					cout << left << "-X";
				}
				else if(pTemp->expn > 1)
				{
					cout << left << "-X^" << pTemp->expn;
				}
			}
		}
		pTemp = pTemp->next;
	}
    cout << endl;
}

Polynomial Polynomial::operator+(Polynomial & poly)
{
	Polynomial Temp;
	Temp.head = addPolynomial(this->head, poly.head);
	return Temp;
}

Polynomial Polynomial::operator-(Polynomial & poly)
{
    Polynomial Temp;
    Temp.head = subPolynomial(this->head, poly.head);
	return Temp;
}

Polynomial Polynomial::operator*(Polynomial & poly)
{
    Polynomial Temp;
    Temp.head = multPolynomial(this->head, poly.head);
	return Temp;
}

Polynomial::~Polynomial()
{
	Polyn *qTemp ,*pTemp= nullptr;
	pTemp = head->next;
	while (pTemp)
	{
		qTemp = pTemp->next;
		delete pTemp;
		pTemp = qTemp;
	}
	delete this->head;
}

Polyn * Polynomial::addPolynomial(const Polyn * p1, const Polyn * p2)
{

	Polyn *pa = p1->next;
	Polyn *pb = p2->next;

	Polyn *newHead, *newRail = nullptr;
	newHead = newRail = new Polyn();
	newHead->next = nullptr;

	Polyn *pTemp = nullptr;

	while (pa && pb)
	{
		pTemp = new Polyn();
		if (pa->expn < pb->expn)
		{
			pTemp->coef = pa->coef;
			pTemp->expn = pa->expn;
			pa = pa->next;
		}
		else if (pa->expn > pb->expn)
		{
			pTemp->coef = pb->coef;
			pTemp->expn = pb->expn;
			pb = pb->next;
		}
		else
		{
			pTemp->coef = pa->coef + pb->coef;
			pTemp->expn = pa->expn;
			pa = pa->next;
			pb = pb->next;
		}

		if (pTemp->coef)
		{
			pTemp->next = newRail->next;
			newRail->next = pTemp;
			newRail = pTemp;
		}
		else
		{
			delete pTemp;
		}
	}
	//pa中有剩余项
	while (pa)
	{
		pTemp = new Polyn();
		pTemp->coef = pa->coef;
		pTemp->expn = pa->expn;
		pa = pa->next;

		pTemp->next = newRail->next;
		newRail->next = pTemp;
		newRail = pTemp;
	}
	//pb中有剩余项
	while (pb)
	{
		pTemp = new Polyn();
		pTemp->coef = pb->coef;
		pTemp->expn = pb->expn;
		pb = pb->next;

		pTemp->next = newRail->next;
		newRail->next = pTemp;
		newRail = pTemp;
	}
	return newHead;
}

Polyn * Polynomial::subPolynomial(const Polyn * p1, Polyn * p2)
{
    Polyn * pTemp = p2->next;
    Polyn * newHead = nullptr;
    while(pTemp)
    {
        pTemp->coef *= -1;
        pTemp = pTemp->next;
    }
    newHead = addPolynomial(p1,p2);

    pTemp = p2->next;
    while(pTemp)
    {
        pTemp->coef *= -1;
        pTemp = pTemp->next;
    }
	return newHead;
}

Polyn * Polynomial::multPolynomial(const Polyn * p1, const Polyn * p2)
{
    Polyn *pa = p1->next;
    Polyn *pb = p2->next;

    Polyn *tempHead,*tempRail,*tempNew = nullptr;
    tempHead = tempRail = new Polyn();
    tempHead->next = nullptr;

    Polyn *newHead = nullptr;
    newHead = new Polyn();
    newHead->next = nullptr;
    while(pb)
    {
        pa = p1->next;
        tempHead->next = nullptr;
        tempHead = tempRail;

        while(pa)
        {
            tempNew = new Polyn();
            tempNew->coef = pa->coef * pb->coef;
            tempNew->expn = pa->expn + pb->expn;

            tempNew->next = nullptr;
            tempRail->next = tempNew;
            tempRail = tempNew;

            pa = pa->next;
        }


        newHead = addPolynomial(tempHead,newHead);
        pb = pb->next;
    }

    //delete tempHead;
	return newHead;
}

