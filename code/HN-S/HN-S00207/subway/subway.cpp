#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll c,n,m,d,q,tx,ans,w[505],t[505][25];
//t[i][j][k]表示第i个站点
//在j号线上走到中庭之时间 
bool vis[505];
vector<ll>a[505];
void dfs(ll now,ll ex)
{
	if(now==ex) return ;
	ll len=a[now].size();
	for(int i=0;i<len;i++)
	{
		ll v=a[now][i];
		if(!vis[v])
		{
			vis[v]=1;
			ans+=2*tx;
			dfs(v,ex);
			vis[v]=0;
		}
	}
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		ll k,last; cin>>k;
		for(int j=1;j<=k;j++)
		{
			ll ai,ti;
			cin>>ai>>ti;
			a[last].push_back(ai);
			t[ai][k]=ti;
			tx=ti; last=ai;
		}
	}
	while(q--)
	{
		ll sx,ex;
		cin>>sx>>ex;
		ll ans=w[sx]+w[ex];
		ans=0;
		dfs(sx,ex);
		cout<<ans;
	}
	
	return 0;
}
