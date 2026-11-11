#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int maxn=505;
const int maxm=5e5+100;
const ll maxt=1e13;
int C;
int n,m,d,q;
int cnt=0;
int W[maxm];
int mp[maxn][maxn];
ll dis[maxn][maxn];
vector<pair<int,int> > sta[maxm];//pair <trainnum,transfertime>
int t[maxm][maxn];
int val[maxm],to[maxm],nxt[maxm],hed[maxn];
void addedge(int u,int v,int w)
{
	cnt++;
	val[cnt]=w;
	to[cnt]=v;
	nxt[cnt]=hed[u];
	hed[u]=cnt;
}
void dijkstra(int st)
{
	priority_queue<pair<ll,int>> pq;
	pq.push({maxt,st});
	while(!pq.empty())
	{
		pair<ll,int> u=pq.top();
		pq.pop();
		int ver=u.second;
		ll actv=maxt-u.first;
		if(dis[st][ver]<actv)
		    continue;
		for(int i=hed[ver];i;i=nxt[i])
		{		
			if(dis[st][to[i]]>actv+val[i])
			{
				dis[st][to[i]]=actv+val[i];
				pq.push({(maxt-actv-val[i]),to[i]});
			}
		}
	}
}
inline int read()
{
	int r=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9')
	{
		if(ch=='-')
		    w=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		r=r*10+(ch-48);
		ch=getchar();
	}
	return r*w;
}
signed main()
{
//	ios::sync_with_stdio(false);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	C=read();
	n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)
			    mp[i][j]=0,dis[i][j]=0;
			else
			    mp[i][j]=2147483647,dis[i][j]=maxt;
		}
	}
	for(int i=1;i<=m;i++)
	{
		W[i]=read();
	}
	for(int i=1;i<=n;i++)
	{
		int k=read();
		while(k--)
		{
			int u=read(),v=read();
			t[u][i]=v;
			pair<int,int> pp;
			pp.first=i,pp.second=v;
			sta[u].push_back(pp);
		}
	}
	for(int k=1;k<=m;k++)
	{
		for(int i=0;i<sta[k].size();i++)
		{
			for(int j=0;j<i;j++)
			{
				int trai=sta[k][i].first,traj=sta[k][j].first;
				mp[trai][traj]=min(mp[trai][traj],sta[k][i].second+sta[k][j].second);
				mp[traj][trai]=mp[trai][traj];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
//			cout<<mp[i][j]<<" ";
			if(mp[i][j]<=2e9 && i!=j)
			    addedge(i,j,mp[i][j]),addedge(j,i,mp[i][j]);
		}
//		cout<<endl;
	}
	
	for(int i=1;i<=n;i++)
	{
		dijkstra(i);
	}
	
	while(q--)
	{
		int X=read(),Y=read();
		ll ans=maxt;
		for(pair<ll,int> i:sta[X])
		{
			for(pair<ll,int> j:sta[Y])
			{
				int xx=i.first,yy=j.first;//xx,yy->trainnum
				ans=min(ans,dis[xx][yy]+t[X][xx]+t[Y][yy]);
			}
		}
		cout<<ans+W[X]+W[Y]<<endl;
	}
	return 0; 
}
