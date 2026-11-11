#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500000+10;
int n,m,a[N],sum[N];
void solve_problems()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i];
	}
	int maxx=1,last=1,v=0;
	for(int i=2;i<=n;i++)
	{
		v=v+((i-last)*(a[i]-a[i-1]));
		while(v>m)
		{
			v=v-a[i]+a[last]-a[i]+a[i+1];
			last++;
		}
		int ans=i-last+1;
		maxx=max(ans,maxx);
	}
	cout<<maxx;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	for(int t=1;t<=T;t++)
	{
		solve_problems();
	}
	return 0;
}
