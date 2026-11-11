#include<bits/stdc++.h>
#define ll long long
#define pir pair<ll,ll>
using namespace std;
const int N=2000006;
ll d;
int n;
ll x[N];
ll dis[5005];
bool vis[5005];
int cnt[5005];
ll ans;
void solve()
{
	cin>>n>>d;
	ans=0;
	vector<int>v[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	for(int i=1;i<=n;i++)
	{
		int max_to=x[i]+d;
		int p=upper_bound(x+1,x+n+1,max_to)-x-1;
		for(int j=i+1;j<=p;j++)
		{
			v[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++)//meiju start
	{
		for(int j=1;j<=n;j++)
		{
			vis[j]=false;
			dis[j]=0x3f3f3f3f3f3f3f3f;
			cnt[j]=0;
		}
		priority_queue<pir,vector<pir>,greater<pir>>q;
		q.push({0,i});
		while(!q.empty())
		{
			int head=q.top().second;
			int w=q.top().first;
			q.pop();
			if(!vis[head])
			{
				vis[head]=true;
				for(auto to:v[head])
				{
					if(w+1<dis[to])
					{
						dis[to]=w+1;
						q.push({w+1,to});
						cnt[to]=1;
					}
					else if(w+1==dis[to])
					{
						cnt[to]++;
					}
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			if(j==i)continue;
			if(cnt[j]==2)
			ans++;
		}
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
