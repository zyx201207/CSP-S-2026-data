#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a,b,m,n,u=0;
	int c[99999999];
	cin >>a>>b;
	if(b==0 || b==1)
	{
	cout<<1;
	return 0;
	}
	for(int i=1;i<=a;i++)
	{
		cin >>c[i];
	}
	for(int i=1;i<=a;i++)
	{
		m=0;
		n=0;
		for(int j=a;j>=i+1;j--)
		{
			if(c[j]-c[i]<b)
			{
				m=j;
				break;
			}
		}
		int p=m;
		for(int l=1;l<=m;l++)
		{
			for(int k=1;k<=p;k++)
			{
				n=n+c[p]-c[k];
				if(n>b)
				{
					p-=1;
					break;
				}
			}
			if(p>u)
			{
				u=p;
			}
		}
	}
	cout<<u;
	return 0; 
}