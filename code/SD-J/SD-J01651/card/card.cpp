#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio;
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,x,maxn=-1e18;
	cin>>n>>m;
	long long a[500005],c[500005];
	long long b[500005]={0};
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			b[i]=0;
		}
		b[a[i]]++;
		if(b[i]>1)
		{
			for(int s=1;s<i;s++)
			{
				if(a[i]==a[s])
				{
					x=s;
				}
			}
			for(int s=x;s<i;s++)
			{
				b[a[s]]--;
			}
			a[x]=a[i];
		}
		for(int j=1;j<m;j++)
		{
			c[j]+=b[j];
		}
	}
	for(int j=1;j<m;j++)
	{
		cout<<c[j];
	}
	return 0;
 } 
