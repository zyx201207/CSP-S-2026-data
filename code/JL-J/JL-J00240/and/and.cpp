#include<bits/stdc++.h>
using namespace std;
#define N 2000005
long long a[N],n,m;
long long sum,ans,ma;
void dfs(long long ks,long long gs,long long sz)
{
	if(gs==m)
	{
		ma=max(sz,ma);
		return;
	}
	if(ks==n)return;
	for(long long ii=ks;ii<n;ii++)
	{
		if(gs!=0)
		dfs(ii+1,gs+1,sz&a[ii]);
		else
		dfs(ii+1,gs+1,a[ii]);
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=0;i<n;i++)
		cin>>a[i];
	ma=LONG_LONG_MIN;
	if(n<=20)
	{
		bool flag=false;
		sum=pow(2,n);
		for(long long i=1;i<sum;i++)
		{
			if(__builtin_popcount(i)==m)
			{
				flag=false;
				for(long long j=0;j<n;j++)
				{
					if(i&(1<<j))
					{
						if(!flag)
						{
							ans=a[j];
							flag=true;
							}
						else
						ans&=a[j];
					}
				}
				ma=max(ma,ans);
			}
		}
		cout<<ma<<endl;
	}
	else if(n<=2000&&m==1)
	{
		for(long long i=0;i<n;i++)
		ma=max(ma,a[i]);
		
		cout<<ma<<endl;
	}
	else if(n<=2000&&m==n)
	{
		ma=a[0];
		for(long long i=1;i<n;i++)
		ma&=a[i];
		cout<<ma<<endl;
	}
	else if(n<=2000&&m==2)
	{
		for(long long i=0;i<n;i++)
		{
			for(long long j=i+1;j<n;j++)
			{
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma<<endl;
	}
	else if(m==n-1)
	{
		for(long long i=0;i<n;i++)
		{
			ans=-1;
			for(long long j=0;j<n;j++)
			{
				if(i==j)continue;
				if(ans==-1)
				ans=a[j];
				else
				ans&=a[j];
			}
			ma=max(ma,ans);
		}
		cout<<ma<<endl;
	}
	else if(a[0]==1)
	{
		ma=a[n-1];
		for(long long i=2;i<=m;i++)
		{
			ma&=a[n-i];
		}
		cout<<ma<<endl;
	}
	else if(a[0]==0)
	{
		if(m>n/2)cout<<'0';
		else {
			dfs(0,0,0);
			cout<<ma;
		}
		cout<<endl;
	}
	return 0;
}

