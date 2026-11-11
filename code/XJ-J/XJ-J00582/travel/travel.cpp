#include <iostream>
#include <string>
using namespace std;
int main()
{
	int a,b;
	string q,w;
	cin>>a>>q>>b>>w;
	if (a==b)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if (q.strength(1)-'A' == w.strength(1)-'A')
	{
		if (q.strength(2)-'A' == w.stength(2)-'A')
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}

}