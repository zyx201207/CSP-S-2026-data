#include<bits/stdc++.h>
using namespace std;
long long a[500010];
map<long long,int>mp;
map<long long,int>mp2;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	long long mi=2e18,mx=-2e18;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mp[a[i]]++;
		mi=min(mi,a[i]);
		mx=max(mx,a[i]);
	}
	int ans=0;
	if(n>5000)
	{
		for(long long i=mi;i<=mx;i++)
		{
			mp2.clear();
			long long ma=-2e18,mn=2e18;
			for(long long j=mi;j<=mx;j++)
			{
				if(mp[j]==0)continue;
				mp2[abs(j-i)]+=mp[j];
				ma=max(ma,abs(j-i));
				mn=min(mn,abs(j-i));
			}
			long long sum=0;
			int cnt=0;
			for(int j=mn;j<=ma;j++)
			{
				if(sum+mp2[j]*j<=m)cnt+=mp2[j],sum+=mp2[j]*j;
				else
				{
					int yzh=m-sum;
					int hd=yzh/j;
					cnt+=hd;
					break;
				}
			}
			ans=max(ans,cnt);
		}
	}
	else
	{
		for(long long i=mi;i<=mx;i++)
		{
			mp2.clear();
			long long ma=-2e18,mn=2e18;
			for(int j=1;j<=n;j++)
			{
				mp2[abs(a[j]-i)]++;
				ma=max(ma,abs(a[j]-i));
				mn=min(mn,abs(a[j]-i));
			}
			long long sum=0;
			int cnt=0;
			for(int j=mn;j<=ma;j++)
			{
				if(sum+mp2[j]*j<=m)cnt+=mp2[j],sum+=mp2[j]*j;
				else
				{
					int yzh=m-sum;
					int hd=yzh/j;
					cnt+=hd;
					break;
				}
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
