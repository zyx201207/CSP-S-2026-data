#include<bits/stdc++.h>
using namespace std;
int c1,c2;
int s1,s2;
int a[15];
int main()
{
	freopen("travel.in","w",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1>>s1>>c2>>s2;
	if (c2 == 1||c1 == 1)
	{
		a[0] = 0;
		for (int i = 0;i < 5;i++)
		{
			a[i] = 0;
			cout<<a[i];
		}
	}
	if (c1 == c2 && c1!=1&&c2!=16)
	{
		a[0]=1;
	}
	if (c1== c2&&s1 == s2)
	{
		a[1] = 1;
	}
	else
	{
		a[1] = 0;
	}
	if (c1!=c2)
	{
		a[2] = 0;
	}
	else
	{
		a[2] = 1;
	}
	
	if (c1==c2&&s1 - s2 == 1)
	{
		a[3] = 1;
	}
	else
	{
		a[3] = 0;
	}
	cout << a[0] << a[1] <<a[2] <<a[3];
	return 0;
}
