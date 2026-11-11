# include <bits/stdc++.h>
# define ll long long
using namespace std;
struct node{
	int v;
	ll w;
};
struct node2{
	int pot;
	ll val;
	bool operator < (const node2 &b) const&{
		if(val==b.val) return pot<b.pot;
		return val<b.val;
	}
};
const int n_max=5e5+505;
const int ns=5e5;
int c,n,m,d,q;
vector<node> mp[n_max];
int w[n_max]={0};
ll dis[505][505]={0};
priority_queue<node2> que;
ll dm[505];
void dij(int start)
{
	memset(dm,0,sizeof(dm));
	while(!que.empty()) que.pop();
	que.push({start,0});
	while(!que.empty())
	{
		node2 s=que.top();
		que.pop();
		dm[s.pot]=s.val;
		for(int i=1;i<=n;i++)
		{
			if(!dis[s.pot][i] || i==s.pot || dm[i]!=0 ||i==start) continue;
			node2 u;
			u.pot=i;
			u.val=dm[s.pot]+dis[s.pot][i];
			que.push(u);
		}
	}
	return;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			mp[a].push_back({ns+j,t});
			mp[ns+j].push_back({a,t});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<mp[ns+i].size();j++)
		{
			int st=mp[ns+i][j].v;
			for(int h=0;h<mp[st].size();h++)
			{
				if(i==mp[st][h].v-ns) continue;
				dis[i][mp[st][h].v-ns]=1e12;
				dis[i][mp[st][h].v-ns]=min(dis[i][mp[st][h].v-ns],mp[ns+i][j].w+mp[st][h].w);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ll anss=1e12;
		for(int j=0;j<mp[x].size();j++)
		{
			dij(mp[x][j].v-ns);
			for(int h=0;h<mp[y].size();h++)
			{
				anss=min(anss,mp[x][j].w+dm[mp[y][h].v-ns]+mp[y][h].w);
			}
		}
		anss+=(w[x]+w[y]);
		cout<<anss<<endl;
	}
	return 0;
}
