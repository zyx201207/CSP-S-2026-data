#include<bits/stdc++.h>
using namespace std;
int b[100000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long o=0;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		if(b[i]>o)
		{
			o=b[i];
		}
	}
	if(m==1)
	{
		cout<<o;
	}
	else if (m==n)
	{
		for(int i=1;i<=m;i++)
		{
			o=o & b[i];
		}
		cout<<o;
	}
	else if(m==2)
	{
		o=0;
		for(int i=1;i<=m;i++)
		{
			for(int j=i+1;j<=m;j++)
			{
				if(o<b[i] & b[j])
				{
					o=b[i] & b[j];
				}
			}
		}
		cout<<o;
	}
	return 0;
}
