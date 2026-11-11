#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n,m,b;
	cin >> n >> m;
	string a[1000005];
	string number[1000005];
	string c[1000005];
	
	for (int i=0;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=0;i<=n;i++)
	{
		c[i] = a[i]%10*1+a[i]/10%
	for (int i=0;i<=n;i++)10*2;
	}
	{
		number[i] = c[i] & c[i+1];
	}
	for (int i=0;i<=n;i++)
	{
		if (number[i] < number[i+1])
		{
			b = number[i+1];
		}
		else
		{
			b = number[i];
		} 
	}
	
	cout << b;
	
	return 0;
}
