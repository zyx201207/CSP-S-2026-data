#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,a[N],m,maxn,sum,an,maxx=-100000;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(i==1) an=a[i];
		else an&=a[i];
		maxx=max(maxx,a[i]);
	}
	if(m==1)
	{
		cout<<maxx;
		return 0;
	}
	if(m==n)
	{
		cout<<an;
		return 0;
	}
	if(m==2)
	{
		for(long long i=1;i<=n-1;i++)
		{
			sum=a[i];
			for(long long j=i+1;j<=n;j++)
			{
				sum&=a[j];
			}
			maxn=max(sum,maxn);
		}
		cout<<maxn;
	}
	return 0;
}
