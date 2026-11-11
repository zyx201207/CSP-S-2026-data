#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,mx,mx1;
ll a[N];
void dfs(int st,int ed,int then,int stp)
{
	if(then==ed)
	{
		if(mx==stp) mx1++;
		else if(mx>stp) mx=stp,mx1=1;
	}
	for(int i=then+1;i<=ed;i++)
	{
		if(a[i]-a[then]>d) break;
		dfs(st,ed,i,stp+1);
	}
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(c==11||c==12)
	{
		ll ans=(ll)n*(n-1)/2;
		for(int i=1;i<=n;i++) ans-=i/d;
		cout<<ans<<"\n";
	}
	else
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
			{
				mx=1e9;mx1=0;
				dfs(i,j,i,0);
				if(mx1==2) ans++;
			}
		cout<<ans<<"\n";
	}
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
0 1
5 3
-2 -1 0 1 2
*/