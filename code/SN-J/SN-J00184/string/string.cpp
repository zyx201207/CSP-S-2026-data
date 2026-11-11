#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	
	int n,number;
	string a[100005];
	string c[100005];
	string b[100005];
	
	for (int i=0;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		for (int j=n;j>=0;j--)
		{
			b[j] = c[i];
		}
	}
	
	for (int i=0;i<=n;i++)
	{
		if (b[i] == c[i])
		{
			number = 0;
		}
	}
	for (int i=0;i<=n;i++)
	{
		if (c[i] != b[i])
		{
			c[i] = b[i];
			number += 1;
		}
	}
	cout << number ;
	
	return 0;
}
