#include<bits/stdc++.h>
using namespace std;
long a[600001]={};
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n, m, max=0, b=0,  d=0, e=1,f,ta,tb,tc=0;
	long long c;
	//b算加起来，c是列最大
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==a[i-1])
		{
			tc++;
		}
		if(tc>=n-1)
		{
			cout<<n;
			return 0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		b=0,c=a[i],f=0,ta=0,tb=0,tc=0;
		for(int j=i;j<=n;j++)
		{
			//b+=a[j];
			if(c<a[j])
			{
				d=ta*(a[j]-c)+tb;
				c=a[j];
			}else
			{
				d=tb+(c-a[j]);
			}
			ta=(j-i+1);
			tb=d;
			//d=c*(j-i+1);
			//cout<<"debug:"<<(j-i+1)<<' '<<c<<' '<<d<<' '<<i<<' '<<j<<' ';
			if(d<=m)
			{
				if(e<(j-i+1))
				{
					e=(j-i+1);
				}
			}
			if(d>m)
			{
				j=n;
			}
		}
	}
	cout<<e;
	return 0;
}
