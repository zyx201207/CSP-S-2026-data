#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005],c[100005];
int s[1000005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i] >> c[i];
		for (int j=1;j<=a[i];j++)
		{
			s[i]=c[i];
		}
	}
	if(n==1)
	{
		cout << "0";
		return 0;
	}
	int md=n/2;
	if((n-md)>(md-1))
	{
		cout << n-md;
	}
	else
	{
		cout << md-1;
	}
	
	return 0;
}

