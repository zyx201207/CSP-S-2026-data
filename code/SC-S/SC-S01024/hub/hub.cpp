#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct EDGE
{
	int next;
	int to;
}ls[N*4];
int num=-1,head[N]; 
void add(int a,int b)
{
	num++;
	ls[num].to=b;
	ls[num].next=head[a];
	head[a]=num;
	return ;
}
int mark[N];
int c,t;
int n,k;
int dis[N];
bitset<N> vis;
queue<int> q;
void bfs1(int x)
{
	vis[x]=1;
	q.push(x);
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=head[now];~i;i=ls[i].next)
		{
			int v=ls[i].to;
			if(vis[v] || !mark[v]) continue;
			vis[v]=1;
			q.push(v);
		}
	}
	return ;
}
int bfs()
{
	vis.reset();
	for(int i=1;i<=n;i++) dis[i]=INT_MAX/3;
	for(int i=1;i<=n;i++)
		if(mark[i])
		{
			q.push(i);
			vis[i]=1;
			dis[i]=0;
		}
	while(!q.empty())
	{
		int now=q.front();
		q.pop();
		for(int i=head[now];~i;i=ls[i].next)
		{
			int v=ls[i].to;
			if(dis[v]>dis[now]+1)
			{
				vis[v]=1;
				q.push(v);
				dis[v]=dis[now]+1;
			}
		}
	}
	int maxx=-1;
	for(int i=1;i<=n;i++) maxx=max(maxx,dis[i]);
	return maxx;
} 
bool check()
{
	vis.reset();
	int cnt=0;
	for(int i=1;i<=n;i++)
	if(!vis[i] && mark[i]) bfs1(i),cnt++;
	return cnt<=2; 
}
void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) head[i]=-1,mark[i]=0;
	num=-1;
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=k;i++) mark[i]=1;
	int minn=INT_MAX;
	for(int i=1;i<=1e4;i++)
	{
		random_shuffle(mark+1,mark+1+n);
		if(check()) minn=min(minn,bfs());
	}
	printf("%d\n",minn);
	return ;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) solve();
	return 0;
}
/*
0 3
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8
6 5
1 2
2 5
4 5
5 3
3 6
9 3
1 2
2 8
4 7
6 5
7 9
8 5
5 3
3 9


*/