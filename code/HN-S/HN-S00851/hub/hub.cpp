#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,INF=1e9;
struct node{
	int id,w;
	bool operator<(const node &other)const
	{
		return w>other.w;
	}
}; 
int c,T,n,k,min1=1e9;
int dis[N],ans[N],fa[N];
bool vis[N],vis1[N],gt[N];
vector<node> nbr[N];
void dijkstra(int s)
{
	for(int i=1;i<=n;i++)
	{
		dis[i]=INF;
		vis[i]=false;
	}
	priority_queue<node> pq;
	dis[s]=0;
	pq.push(node{s,dis[s]});
	while(pq.empty()==false)
	{
		int cur=pq.top().id;
		pq.pop();
		if(vis[cur]==true)
		{
			continue;
		}
		vis[cur]=true;
		for(int i=0;i<nbr[cur].size();i++)
		{
			int nxt=nbr[cur][i].id;
			int w=nbr[cur][i].w;
			if(dis[nxt]>dis[cur]+w)
			{
				dis[nxt]=dis[cur]+w;
				pq.push(node{nxt,dis[nxt]});
			}
		}
	}
	return ;
}
void work(int s)
{
	queue<int> q;
	q.push(s);
	while(q.empty()==false)
	{
		int cur=q.front();
		q.pop();
		if(vis1[cur]==true)
		{
			continue;
		}
		vis1[cur]=true;
		for(int i=0;i<nbr[cur].size();i++)
		{
			int nxt=nbr[cur][i].id;
			if(gt[nxt]==false)
			{
				continue;
			}
			else
			{
				q.push(nxt);
			}
		}
	}
	return ;
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		vis1[i]=false;
		gt[i]=false;
	}
	for(int i=1;i<=k;i++)
	{
		gt[ans[i]]=true;
	}
	int cnt=0;
	for(int i=1;i<=k;i++)
	{
		if(vis1[ans[i]]==false)
		{
			work(ans[i]);
			cnt++;
		}
	}
	if(cnt<=2)
	{
		return true;
	}
	return false;
}
void get_ans()
{
	int max1=-1e9;
	for(int i=1;i<=k;i++)
	{
		dijkstra(ans[i]);
		for(int j=i+1;j<=k;j++)
		{
			max1=max(max1,dis[ans[j]]);
		}
	}
	min1=min(min1,max1);
	return ;
}
void dfs(int cur,int sum)
{
	if(sum>k)
	{
		return ;
	}
	if(cur==n)
	{
		if(sum==k) 
		{
			if(check()==true)
			{
				get_ans();
			}
		}
		return ;
	}
	for(int i=cur+1;i<=n;i++)
	{
		sum+=1;
		ans[sum]=i;
		dfs(i,sum);
		ans[sum]=0;
		sum-=1;
	}
	return ;
} 
void solve()
{
	cin>>n>>k;
	min1=1e9;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		nbr[u].push_back(node{v,1});
		nbr[v].push_back(node{u,1});
	}
	dfs(1,0);
	cout<<min1<<"\n";
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		solve();
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
