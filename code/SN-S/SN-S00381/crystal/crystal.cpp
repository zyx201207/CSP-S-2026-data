#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],sum[500005];
void solve1()//baoli
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=1,cost=m;
		for(int j=i-1;j>=0;j--)
		{
			int cha=a[i]-a[j];
			if(cost-cha<0)break;
			cost-=cha;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
}
void solve2()
{
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			int x;
			if(mid==1)x=a[i]*(i-mid)-(sum[i-1]-sum[i-mid]);
			else x=a[i]*(i-mid)-(sum[i-1]-sum[i-mid-1]);
			
			if(x<m)
			{
				r=mid-1;
			}
			else 
			{
				l=mid+1;
				
			}
			ans=mid;
			
		}
		maxn=max(maxn,i-ans+1);
	}
	cout<<maxn;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	if(n<=5000)solve1();
	else solve2();
	return 0;
}
