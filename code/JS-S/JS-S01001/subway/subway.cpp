#include<bits/stdc++.h>
typedef long long ll;
//Frina De Fentan
//Anastasya Fioudrofna Shenazyana
//luogu 985701
//UID 280695312
//Privet
using namespace std;
struct Edge{
	int v,w,nxt;
}e[5000005];
int h[1000005],tot;
inline void add(int u,int v,int w)
{
	e[++tot]={v,w,h[u]};
	h[u]=tot;
	return;
}
int w[500005],k[505];
struct Query{
	int x,y,id;
}ques[100005];
bool cmp(Query x,Query y)
{
	if(x.x==y.x) return x.y<y.y;
	return x.x<y.x;
}

struct inque{
	int u,d;
	bool operator< (const inque& o) const{
		return d>o.d;
	}
};
int dis[500005];
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof dis);
	priority_queue<inque> q;
	inque t={s,0};
	q.push(t);
	
	while(q.size())
	{
		t=q.top();
		q.pop();
		int u=t.u,d=t.d;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v;
			if(d+e[i].w<dis[v])
			{
				dis[v]=d+e[i].w;
				q.push({v,dis[v]});
			}
		}
	}
	return;
}
vector<int> a[505],t[505];
int c,n,m,d,q;
int ans[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		a[i].resize(k[i]+1);
		t[i].resize(k[i]+1);
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
		}
		for(int j=1;j<=k[i];j++)
		{
			add(i+m,a[i][j],t[i][j]);
			add(a[i][j],i+m,t[i][j]);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>ques[i].x>>ques[i].y;
		ques[i].id=i;
	}
	sort(ques+1,ques+q+1,cmp);
	for(int i=1;i<=q;i++)
	{
		int x=ques[i].x,y=ques[i].y;
		if(x!=ques[i-1].x) dijkstra(x);
		ans[ques[i].id]=w[x]+dis[y]+w[y];
	}
	for(int i=1;i<=q;i++)
	{
		cout<<ans[i]<<"\n";
	}
	return 0;
}
