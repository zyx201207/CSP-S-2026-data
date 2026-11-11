#include<bits/stdc++.h>
#define Fopen(FNAME) freopen(FNAME".in","r",stdin);freopen(FNAME".out","w",stdout);
using namespace std;
using ll=long long;
using PII=pair<int,int>;
using PLI=pair<ll,int>;
using PLL=pair<ll,ll>;
using ve=vector<int>;
const int N=2e6+9,mod=1e9+7;

int Case,n,d,m,p,k,T=1;
int x[N];
int plans=0,j,plan_cnt;
void dfs(int now,int cnt)
{
	if(now==j)
	{
		if(cnt==plan_cnt)plans++;
		return;
	}
	if(plans>2)return;
	for(int i=now+1;i<=j;i++)
	{
		if(x[i]-x[now]<=d)dfs(i,cnt+1);
	}
}
void solve(int tcase)
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			plan_cnt=0;
			int now=i;
			while(now<j)
			{
				int new_pos=lower_bound(x+1,x+n+1,x[now]+d)-x;
				if(new_pos==now)break;
				now=new_pos;
				plan_cnt++;
			}
//			cout<<i<<' '<<j<<' '<<plan_cnt<<'\n';
			
			plans=0;
			dfs(i,0);
			if(plans==2)
			{
				ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(	)
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	Fopen("migrate");
	cin>>Case>>T;
	for(int i=1;i<=T;i++)
	{
		solve(i);
	}
	return 0;
}
/*
也许只有一个点是可分的
换言之 在两点中找满足两点间距离小于d最少的点
除了这些点 两点间只允许存在一个点。
*/