#include<bits/stdc++.h>
using namespace std;
bool a , b , c , xs , ns;
string ca , sa , cb , sb;
int main()
{
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	cin >> ca >> sa >> cb >> sb;
	if(ca == cb)
	{
		cout << 1;
		a = true;
    }
	else
	{
		cout << 0;
		a = false;
	}
	if(sa[0] + sa[1]==sb[0] + sb[1] && a)
	{
		cout << 1;
		b = true;
	}
	else
	{
		cout << 0;
		b = false;
	}
	if(((sa[2] <= 'C' && sb[2] <= 'C') || (sa[2] >= 'D' && sb[2] >= 'D'))
	&& b)
	{
		cout << 1;
		c = true;
	}
	else
	{
		cout << 0;
		c = false;
	}
	xs = max(sa[2] - 'A' , sb[2] - 'A');
	ns = min(sa[2] - 'A' , sb[2] - 'A');
	if(xs - ns == 1 && c)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}