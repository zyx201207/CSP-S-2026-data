#include<bits/stdc++.h>
#define int long long
#define F(a) for(int i=1;i<=a;i++)
#define Fi(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const int N=2e6+10;

int x[N],sum[N];
int minx,sj;

void dfs1(int now,int goal,int d,int cnt)
{
	if(cnt>=minx) return;
	if(now==goal)
	{
		minx=min(minx,cnt);
		return;
	}
	Fi(i,now+1,goal) if(sum[i]-sum[now]<=d) dfs1(i,goal,d,cnt+1);
	else break;
}

void dfs2(int now,int goal,int d,int cnt)
{
	if(cnt>minx) return;
	if(now==goal)
	{
		if(cnt==minx) sj++;
		return;
	}
	Fi(i,now+1,goal) if(sum[i]-sum[now]<=d) dfs2(i,goal,d,cnt+1);
	else break;
}

void solve()
{
	int n,d;
	cin>>n>>d;
	F(n) cin>>x[i];
	F(n) sum[i]=sum[i-1]+x[i]-x[i-1];
	int ans=0;
	F(n) Fi(j,i+1,n)
	{
		minx=INT_MAX,sj=0;
		dfs1(i,j,d,0);
		if(minx==(int)INT_MAX) continue;
		dfs2(i,j,d,0);
		if(sj==2) ans++;
	}
	cout<<ans<<'\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
