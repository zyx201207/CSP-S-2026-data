#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000005],b[10000005],q[10000005],d;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		while(a[i]>0)
		{
			b[i]=(b[i]+a[i]%2)*10;
			a[i]%=2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			q[i]=b[i]&b[j]; 
		} 
	}
	for(int i=1;i<=n;i++)
	{
		d=max(d,q[i]); 
	}
	cout << d; 
	return 0;
}

 
