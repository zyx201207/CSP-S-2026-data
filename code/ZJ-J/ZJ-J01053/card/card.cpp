#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],f[300001],cnt,flag,v[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	cin>>a[i];
	if(m==1&&n>10000) 
	{
		cout<<n;
		return 0;
	}
	if(m==2&&n>10000)
	{
		long long cnt=0;
		if(a[n]==1) 
		{
			for(long long i=1;i<=n;i++)
			if(a[i]==2) cnt++;
			cout<<n<<" "<<cnt;
		}
		else
		{
			for(long long i=1;i<=n;i++)
			if(a[i]==1) cnt++;
			cout<<cnt<<" "<<n;
		}
		return 0;
	}
	for(long long i=1;i<=n;i++)
	{
		cnt=0;
		for(long long j=i;j<=n;j++)
		{
			flag=1;
			for(long long k=1;k<=cnt;k++)
			{
				if(v[k]==a[j]) 
				{
					cnt=k;
					flag=0;
					break;
				}
			}
			if(flag) v[++cnt]=a[j];
		}
		for(long long j=1;j<=cnt;j++)
		f[v[j]]++;
	}
	for(long long i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0;
}
