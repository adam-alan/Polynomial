#include "Polynomial.h"
#include <iostream>


void bubblesort(int array[], int n);
void swap(int &a, int &b);
void solution(int a[],int n,int & max1,int & max2);

int main(int argc, char** argv)
{
	int a[10] = {10,1,2,3,4,5,6,7,8,9,};
	int max1,max2 = 0;
	solution(a,10,max1,max2);

	std::cout <<"数组中的最大值为："<< max1 << std::endl;
    std::cout <<"数组中的次最大值为："<< max2 << std::endl;

	return 0;
}
int findK(int a[],int n,int k)
{
    for(int i = 1;i < n;i++)
    {
        if(a[i] == k)
        {
            return i;
        }
    }
    return 0;
}

void solution(int a[],int n,int & max1,int & max2)
{
    int mark = 0;
    int themin = a[0];
    //找数组中的最小值
    for(int i = 0;i < n;i++)
    {
        if(themin > a[i])
        {
            themin = a[i];
        }
    }
    //将最小值赋值给max1,max2

    max1 = max2 = themin;

    //找出最大值并标记最大值的位置
    for(int i = 0;i < n;i++)
    {
        if(max1 < a[i])
        {
            max1 = a[i];
            mark = i;
        }
    }
    //在区间[0,mark),[mark+1,n)里找最大值
    for(int i = 0;i < mark ;i++)
    {
        if(max2 < a[i])
        {
            max2 = a[i];
        }
    }

    for(int i = mark + 1;i < n;i++)
    {
        if(max2 < a[i])
        {
            max2 = a[i];
        }
    }
    return;
}

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
    return;
}

void bubblesort(int array[], int n)
{
	for (bool sorted = false; sorted = !sorted; n--)
	{
		for (int i = 1; i < n; i++)
		{
			if (array[i - 1] < array[i])
			{
				swap(array[i - 1], array[i]);
				sorted = false;
			}
		}
	}
    return;
}

