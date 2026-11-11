#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,Q;
int w[500003];
int k[503];
vector<int>a[503];
vector<int>t[503];
struct edge
{
	int to,dis,next;
}e[200003];
int head[18003],dis[18003],s,cnt;
bool vis[18003];
inline void add(int u,int v,int w)
{
	++cnt;
	e[cnt].dis=w;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
struct node
{
	int dis,pos;
	inline bool operator < (const node &x)const
	{
		return x.dis<dis;
	}
};
priority_queue<node>q;
inline void dijkstra(void)
{
	for(int i=1;i<=m+d*m+m;++i)
	{
		dis[i]=0x7fffffff;
		vis[i]=0;
	}
	dis[s]=0;
	q.push((node){0,s});
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		int x=tmp.pos;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=e[i].next)
		{
			int y=e[i].to;
//			cout << x << ' ' << y << '\n';
			if(dis[y]>dis[x]+e[i].dis)
			{
				dis[y]=dis[x]+e[i].dis;
				if(!vis[y])
				{
					q.push((node){dis[y],y});
				}
			}
		}
	}
}
queue<node>_q;
inline void dijkstra1(void)
{
	for(int i=1;i<=m+d*m+n+3;++i)
	{
		dis[i]=0x7fffffff;
		vis[i]=0;
	}
	dis[s]=0;
	_q.push((node){0,s});
//	cout << "-----\n";
	while(!_q.empty())
	{
		node tmp=_q.front();
		_q.pop();
		int x=tmp.pos;
//		cout << "-----\n";
		if(vis[x])continue;
		vis[x]=1;
//		cout << "-----\n";
		for(int i=head[x];i;i=e[i].next)
		{
			int y=e[i].to;
//			cout << x << ' ' << y << '\n';
			if(dis[y]>dis[x]+e[i].dis)
			{
				dis[y]=dis[x]+e[i].dis;
				if(!vis[y])
				{
					_q.push((node){dis[y],y});
				}
			}
		}
	}
}
int x,y;
signed main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> Q;
	for(int i=1;i<=m;++i)cin >> w[i];
	for(int i=1;i<=n;++i)
	{
		cin >> k[i];
		for(int j=1;j<=k[i];++j)
		{
			cin >> x >> y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	if(c<=8||c>11)
	{
		for(int i=1;i<=n;++i)
		{
			add(a[i][0],m+d*(a[i][0]-1)+i,t[i][0]);
//			cout << a[i][0] << ' ' << m+n*(a[i][0]-1)+i << ' ' << t[i][0] << '\n';
			add(m+d*(a[i][0]-1)+i,a[i][0],t[i][0]);
			for(int j=1;j<k[i];++j)
			{
				add(a[i][j],m+d*(a[i][j]-1)+i,t[i][j]);
//				cout << a[i][j] << ' ' << m+n*(a[i][j]-1)+i << ' ' << t[i][j] << '\n';
				add(m+d*(a[i][j]-1)+i,a[i][j],t[i][j]);
				add(m+d*(a[i][j]-1)+i,m+d*(a[i][j-1]-1)+i,0);
//				cout << m+n*(a[i][j]-1)+i << ' ' << m+n*(a[i][j-1]-1)+i << ' ' << 0 << '\n';
				add(m+d*(a[i][j-1]-1)+i,m+d*(a[i][j]-1)+i,0);
			}
		}
		while(Q--)
		{
			cin >> x >> y;
			s=x;
			dijkstra();
//			cout << dis[y] << '\n';
			cout << dis[y]+w[x]+w[y] << '\n';
		}
	}
	else if(c<=11)
	{
		for(int i=1;i<=n;++i)
		{
			add(a[i][0],m+d*(a[i][0]-1)+i,t[i][0]);
//			cout << a[i][0] << ' ' << m+n*(a[i][0]-1)+i << ' ' << t[i][0] << '\n';
			add(m+d*(a[i][0]-1)+i,a[i][0],t[i][0]);
			for(int j=1;j<k[i];++j)
			{
				add(a[i][j],m+d*(a[i][j]-1)+i,t[i][j]);
//				cout << a[i][j] << ' ' << m+n*(a[i][j]-1)+i << ' ' << t[i][j] << '\n';
				add(m+d*(a[i][j]-1)+i,a[i][j],t[i][j]);
				add(m+d*(a[i][j]-1)+i,m+d*(a[i][j-1]-1)+i,0);
//				cout << m+n*(a[i][j]-1)+i << ' ' << m+n*(a[i][j-1]-1)+i << ' ' << 0 << '\n';
				add(m+d*(a[i][j-1]-1)+i,m+d*(a[i][j]-1)+i,0);
			}
		}
		while(Q--)
		{
			cin >> x >> y;
			s=x;
			dijkstra1();
//			cout << dis[y] << '\n';
			cout << dis[y]+w[x]+w[y] << '\n';
		}
	}
	return 0;
}