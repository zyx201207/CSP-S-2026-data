#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int c,n,m,d,qe;
ll w[500005];
ll k[505];
bool vis[500005];
vector<ll>a[505];
vector<ll>t[505];
vector<int>rd[505];//编号为i的地铁站能进的路线 
ll dis[500005];
int pl[505][20005];
struct node
{
	int d;
	ll l;
	bool operator < (const node &a)const
	{
		return l>a.l;
	}
};
priority_queue<node>q;
ll solve(int st,int ed)
{
	for(int i=1;i<=m;i++)
	{
		vis[i]=0;
		dis[i]=0x3f3f3f3f3f3f3f3f;
	}
	dis[st]=0;
	ll ans=0;
	ans+=w[st];
	ans+=w[ed];
	dis[st]=0;
	q.push(node{st,0});
	while(!q.empty())
	{
		node tmp=q.top();
		int u=tmp.d;
		q.pop();
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		int sz=rd[u].size();
	//	cout<<u<<'\n';
		for(int i=0;i<sz;i++)
		{
			
			int r=rd[u][i];
			int plc=pl[r][u];
		//	cout<<r<<" "<<plc<<'\n';
			for(int j=plc-2;j>=0;j--)
			{
				int v=a[r][j];
			//	cout<<"v:"<<v<<'\n';
			//	cout<<"trp:"<<t[r][plc-1]<<'\n';
				if(dis[u]+t[r][j]+t[r][plc-1]<dis[v])
				{
					
					dis[v]=dis[u]+t[r][j]+t[r][plc-1];
					q.push(node{v,dis[v]});
				}
			}
			for(int j=plc;j<k[r];j++)
			{
				int v=a[r][j];
			//	cout<<"v:"<<v<<'\n';
			//	cout<<"trp:"<<t[r][plc-1]<<'\n';
				if(dis[u]+t[r][j]+t[r][plc-1]<dis[v])
				{
					dis[v]=dis[u]+t[r][j]+t[r][plc-1];
					q.push(node{v,dis[v]});
				}
			}
		}
	}
	ans+=dis[ed];
	return ans;
}
/*struct node
{
	int d;
	ll l;
	bool operator < (const node &a)const
	{
		return l>a.l;
	}
};
priority_queue<node>q;
struct edge
{
	int nxt;
	ll w;
	int to;
};
edge e[2000005];
bool vis[500005];
ll spbsolve(int st,int ed)
{
	for(int i=1;i<=m;i++)
	{
		vis[i]=0;
		dis[i]=0x3f3f3f3f3f3f3f3f;
	}
	
	
}
*/

struct edge
{
	int nxt;
	ll w;
	int to;
};
edge e[200005];
int head[500005];
int cnt=0;

void add(int u,int v,ll ww)
{
	cnt++;
	e[cnt].nxt=head[u];
	e[cnt].w=ww;
	e[cnt].to=v;
	head[u]=cnt;
	return;
}
void spapre()
{
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
	{
		if(k[i]==2)
		{
			add(a[i][0],a[i][1],t[i][1]+t[i][0]);
			add(a[i][1],a[i][0],t[i][0]+t[i][1]);
		}
	}
	return;
}
ll spasolve(int st,int ed)
{
	ll ans=w[st]+w[ed];
	for(int i=1;i<=m;i++)
	{
		dis[i]=0x3f3f3f3f3f3f3f3f;
		vis[i]=0;
	}
	dis[st]=0;
	q.push(node{st,0});
	while(!q.empty())
	{
		node tmp=q.top();
		q.pop();
		int u=tmp.d;
		if(vis[u])
		{
			continue;
		}
		vis[u]=1;
		for(int i=head[u];i!=-1;i=e[i].nxt)
		{
			int v=e[i].to;
			ll www=e[i].w;
			if(dis[u]+www<dis[v])
			{
				dis[v]=dis[u]+www;
				q.push(node{v,dis[u]+www});
			}
		}
	}
	ans+=dis[ed];
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	cin>>c>>n>>m>>d>>qe;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	ll cx,cy;
	bool spb=1;
	bool spa=1;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		if(k[i]>2)
		{
			spa=0;
		}
		for(int j=1;j<=k[i];j++)
		{
			cin>>cx>>cy;
			a[i].emplace_back(cx);
			t[i].emplace_back(cy);
			rd[cx].emplace_back(i); 
			pl[i][cx]=j;
		}
	}
/*	for(int i=1;i<=n;i++)
	{
		int sz=t[i].size();
		for(int j=0;j<sz-1;j++)
		{
			if(t[i][j]!=t[i][j+1])
			{
				spb=0;
				break;
			}
		}
		if(spb==0)
		{
			break;
		}
	}
	if(spb)
	{
		spbprepare();
	}
*/
	if(spa)
	{
		spapre();
	}

	int s,e;
	while(qe--)
	{
		cin>>s>>e;
	/*	if(spb)
		{
			cout<<spbsolve(s,e)<<'\n';
			continue;
		}
	*/
		if(spa)
		{
			cout<<spasolve(s,e)<<'\n';
			continue;
		}	
		cout<<solve(s,e)<<'\n';
	}
	return 0;
}
//What do you prepare to sacrifice,to win this war?
/*0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2
*/
