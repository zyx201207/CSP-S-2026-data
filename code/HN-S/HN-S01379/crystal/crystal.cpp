#include<bits/stdc++.h>
using namespace std;

const int N=5*1e5+5;

long long n;

long long m;

long long a[N];

long long f[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	
	for(long long i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	
	long long ans=0;
	
	long long cnt=m;
	
	for(long long i=1;i<=n;++i)
	{
		for(long long j=1;j<i;++j)
		{
			a[j]++;
			cnt--;
			if(cnt<0)
			{
				cout<<ans+1;
				return 0;
			}
			if(a[j]==a[i])
			{
				ans=max(ans,i);
			}
		}
	}
	
	cout<<n;
	return 0;
}
