#include <iostream>
#include <string>
#include <stdlib.h>

#define N 10

using namespace std;

class largeInt {
private:
	int a[N];
	int size;
public:
	void inValue(string str);
	string getValue();
};

void largeInt::inValue(string str)
{
	int l = str.length();
	char a;
	int p = 0;
	string tmp="";

	for (int i = l - 1; i >= 0; i--)
	{
		tmp.push_back(str[i]);
		str.pop_back();

		if (tmp.length() == 5)
		{
			(*this).a[p] = stoi(tmp);
			p++;
			tmp.clear();
		}
	}

	if (!tmp.empty())
	{
		(*this).a[p] = stoi(tmp);
		tmp.clear();
		p++;
	}
	
	(*this).size = p;
}

string largeInt::getValue()
{
	string tmp;
	char *arr[10];
	
	for(int i = (*this).size;i>=0;i--)
	{
		itoa((*this).a[i],arr,10);
		tmp.push_back(arr);
	}
	
	return tmp;
}

int main()
{
	string a;
	largeInt A;

	cin >> a;
	A.inValue(a);
	cout << A.getValue();

	return 0;
}