#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,ans=0,maxn=0;
	cin>>n>>m;
	long long a[N];
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(m==1)
	{
		for(int i=0;i<n;i++)
		{
			maxn=max(maxn,a[i]);
		}
		cout<<maxn<<endl;
		return 0;
	}
	if(m==2)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn<<endl;
		return 0;
	}
	if(m==n)
	{
		ans=a[0];
		for(int i=1;i<n;i++)
			ans&=a[i];
		cout<<ans<<endl;
		return 0;
	}
	for(long long i=1;i<(1<<(n+1));i++)
	{
		int cnt=__builtin_popcount(i);
		if(cnt!=m)
			continue;
		int c=1;
		long long re=-1;
		for(int j=0;j<n+1;j++)
		{
			if((i&(c<<j)))
			{
				if(re==-1)
					re=a[j];
				else
					re&=a[j];
			}
		}
		ans=max(ans,re);
	}
	cout<<ans<<endl;
	return 0;
}
