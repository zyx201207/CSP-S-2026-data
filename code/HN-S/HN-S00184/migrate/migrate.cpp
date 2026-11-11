#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define pil pair<int,ll>
#define fi first
#define se second
using namespace std;
const int M=2e6+5;
const ll inf=2e18+5;
int n;
ll m,ans,a[M],sum1[M],sum2[M];
pii p[M],dl[M],dr[M];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dl[i]={i+1,0};
		dr[i]={n+1,i-1};
	}
	for(int i=1,now=1;i<=n;i++)
	{
		for(;now<=i&&a[i]-a[now]>m;now++){}
		p[i].fi=now;
		dr[now].fi=min(dr[now].fi,i);
		dr[now].se=max(dr[now].se,i);
	}
	for(int i=n,now=n;i>=1;i--)
	{
		for(;now>=i&&a[now]-a[i]>m;now--){}
		p[i].se=now;
		dl[now].fi=min(dl[now].fi,i);
		dl[now].se=max(dl[now].se,i);
	}
	for(int i=1;i<=n;i++)
	{
		sum1[i]=0;
		if(dl[i].fi>dl[i].se||dl[i].fi>=i)
			continue;
		sum1[i]=dl[i].se-dl[i].fi+(dl[i].se<i)+sum1[p[i].fi];
	}
	for(int i=n;i>=1;i--)
	{
		sum2[i]=0;
		if(dr[i].fi>dr[i].se||dr[i].se<=i)
			continue;
		sum2[i]=dr[i].se-dr[i].fi+(dr[i].fi>i)+sum2[p[i].se];
	}
//	for(int i=1;i<=n;i++)
//		cout<<i<<' '<<p[i].fi<<' '<<p[i].se<<' '<<dl[i].fi<<' '<<dl[i].se<<' '<<dr[i].fi<<' '<<dr[i].se<<'\n';
	for(int i=2;i<n-1;i++)
	{
		if(dr[i].se<=i+1||dl[i+1].fi>=i||dr[i].fi>dr[i].se||dl[i+1].fi>dl[i+1].se)
			continue;
		ll res1=dr[i].se-max(dr[i].fi,i+2)+1,res2=min(i-1,dl[i+1].se)-dl[i+1].fi+1;
		if(p[i+1].se==dr[i].se)
		{
			res1+=sum2[p[i+1].se];
//			for(int j=p[i+1].se;j<=n&&dr[j].fi<=dr[j].se&&dr[j].se>j;j=p[j].se)
//				res1+=dr[j].se-dr[j].fi+(dr[j].fi>j);
		}
		if(p[i].fi==dl[i+1].fi)
		{
			res2+=sum1[p[i].fi];
//			for(int j=p[i].fi;j>=1&&dl[j].fi<=dl[j].se&&dl[j].fi<j;j=p[j].fi)
//				res2+=dl[j].se-dl[j].fi+(dl[j].se<j);
		}
		ans+=res1*res2;
	}
	cout<<ans<<'\n';
	ans=0;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1,C;
	cin>>C;
	cin>>T;
	while(T--)
		solve();
	return 0;
}
