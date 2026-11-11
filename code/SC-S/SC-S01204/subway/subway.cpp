#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=505,M=5e5+5,Q=1e5+5;//记得改数据范围 
int c,n,m,d,q,w[M],cnt,dis[M*2+N],ok[2*M+N];;
struct node{
	int v,w;
};
struct hzb{
	int dis,pos;
	bool operator<(const hzb &x)const{
		return dis>x.dis;
	}
};
vector<node> mp[M*2+N];
void dij(int s)
{
	priority_queue<hzb> q;
	
	for(int i=1;i<=2*m+n;i++)
	{
		dis[i]=1e18;ok[i]=0;
	}
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().pos;q.pop();
		if(ok[u]) continue;
		ok[u]=1;
		for(node e:mp[u])
		{
			int v=e.v,W=e.w;
			if(dis[v]>dis[u]+W)
			{
				dis[v]=dis[u]+W;q.push({dis[v],v});
			}
		}
	}
}
struct query{
	int s,t,id;
}que[Q];
int ans[Q];
bool cmp(query a,query b)
{
	return a.s<b.s;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;cnt=2*m;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		mp[i].push_back({m+i,w[i]});
		mp[m+i].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,y;cin>>x>>y;
			mp[2*m+i].push_back({m+x,y});
			mp[m+x].push_back({2*m+i,y});
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>que[i].s>>que[i].t;que[i].id=i;
	}
	sort(que+1,que+q+1,cmp);int last=que[1].s;dij(last);
	for(int i=1;i<=q;i++)
	{
		if(que[i].s==last)
		{
			ans[que[i].id]=dis[que[i].t];
		}
		else
		{
			dij(que[i].s);last=que[i].s;
			ans[que[i].id]=dis[que[i].t];
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<endl;
	return 0;
}