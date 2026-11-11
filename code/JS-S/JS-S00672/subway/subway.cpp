#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500505
#define mkp make_pair
int hd[N],nxt[N<<1],to[N<<1],gcnt;
ll vl[N<<1];
void Add(int _u,int _v,ll _w)
{
	nxt[++gcnt]=hd[_u];
	hd[_u]=gcnt;
	to[gcnt]=_v;
	vl[gcnt]=_w;
}

ll dis[N];
bool vis[N];

int lyjkksk;
int n,m,d,q;
ll vvl[N];

ll zdll(int s,int t)
{
	for(int i=1;i<=n+m;i++)dis[i]=0,vis[i]=0;
	priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > qqq;
	qqq.push(mkp(0,s));
	int nw,vvv;
	while(!qqq.empty())
	{
		nw=qqq.top().second;
		vvv=qqq.top().first;
		qqq.pop();
		if(vis[nw])continue;
		vis[nw]=1;
		dis[nw]=vvv;
		for(int i=hd[nw];i;i=nxt[i])
		{
			if(vis[to[i]])continue;
			qqq.push(mkp(vvv+vl[i],to[i]));
		}
	}
	return dis[t];
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>lyjkksk>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>vvl[i];
	}
	for(int i=1,ink;i<=n;i++)
	{
		cin>>ink;
		for(int j=1,inv,inw;j<=ink;j++)
		{
			cin>>inv>>inw;
			Add(m+i,inv,inw);
			Add(inv,m+i,inw);
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<zdll(x,y)+vvl[x]+vvl[y]<<'\n';
	}
	return 0;
}
