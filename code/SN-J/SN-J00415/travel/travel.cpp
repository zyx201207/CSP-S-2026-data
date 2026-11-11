#include <iostream>
#include <string>
using namespace std;
char c1,s1,c2,s2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2)
    {
    	cout << 0000;
    	return 0;
	}
	if(s1.length(1) != s2.length(1))
	{
		cout << 1000;
		return 0;
	}
	if(c1.length(2)=="A"||c1.length(2)=="B"||c1.length(2)=="C")
	{
		if(c2.length(2)=="D"||c2.length(2)=="E")
		{
			cout<<1100;
			return 0;
		}
	}
	else if(c2.length(2)=="A"||c2.length(2)=="B"||c2.length(2)=="C")
	{
		if(c1.length(2)=="D"||c1.length(2)=="E")
		{
			cout << 1100;
			return 0;
		}
	}
	if(c1.length(2)=="A"&&c2.length(2)=="B")
	{
		cout << 1111;
		return 0;
	}
	else if(c1.length(2)=="B"&&c2.length(2)=="C")
	{
		cout << 1111;
		return 0;
	}
	else if(c1.length(2)=="D"&&c2.length(2)=="F")
	{
		cout << 1111;
		return 0;
	}
	else if(c2.length(2)=="A"&&c1.length(2)=="B")
	{
		cout << 1111;
		return 0;
	}
	else if(c2.length(2)=="B"&&c1.length(2)=="C")
	{
		cout << 1111;
		return 0;
	}
	else if(c2.length(2)=="D"&&c1.length(2)=="F")
	{
		cout << 1111;
		return 0;
	}
	cout << 1110;
    return 0;
}
