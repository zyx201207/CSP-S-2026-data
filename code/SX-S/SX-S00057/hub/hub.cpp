#include<bits/stdc++.h>
#define ll long long
using namespace std;const int N=1e6+5;
ll c,t,n,k,vis[N],ans=1e18;
vector<ll> vt[N];;
void dfs(ll step,ll tq,ll lt)
{
	if(step==k)
	{
		ans=min(tq,ans);
		return ;	
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			ll ababa=1;
			vis[i]=1;
			ll opop=0;
			for(int j=0;j<vt[i].size();j++)
			{
				opop+=vis[vt[i][j]];
			}
			if(opop==1)
			dfs(step+1,tq+1,lt);
			else if(opop>1)
			dfs(step+1,(max(tq,ababa)),lt);
			else if(opop==0&&lt!=2)
			dfs(step+1,(max(tq,ababa)),lt++);
		}
	}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c<=6)
	while(t--)
	{
		cin>>n>>k;
		if(k>=n) {
			cout<<n<<'\n';
		}
		for(int i=1;i<n;i++)
		{	ll u,v;
			cin>>u>>v;
			vt[u].push_back(v);
			vt[v].push_back(u);
		}
		dfs(1,0,0);
		cout<<ans<<'\n';
	}
	else
	{
		while(t--)
		{
			cin>>n>>k;
			for(int i=1;i<n;i++)
			{
				ll u,v;
				vt[u].push_back(v);
				vt[v].push_back(u);
			}
			ll op=1;
			for(int i=1;i<=n;i++)
			{
				if(vt[i].size()==n-1)
					op=0;
				else
					op=1;
			}
			cout<<op<<'\n';
		}
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
