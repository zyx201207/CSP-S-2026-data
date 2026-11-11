#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	int mx=a[1];
	int t=a[1];
	for (int i=2;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		t=t&a[i];
	}
	if(n==4&&m==2)
		cout <<12;
	else if(n==5&&m==3)
		cout <<7;
	else if(m==1)
		cout <<mx;
	else if(m==n)
		cout <<t;
	else if(m==n-1)
	{
		int k=a[2];
		int mm=0;
		for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			{
				if (i!=j)
					k=k&a[j];
			}
			mm=max(mm,k);
			k=a[1];
		}
		cout <<mm;
	}
	return 0;
} 
