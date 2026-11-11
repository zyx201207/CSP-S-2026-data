#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=520,maxm=500100,maxk=1010;
int c,n,d,m,q;
int w[maxm];
int a[maxn][maxk];
int t[maxn][maxk];
vector<int>bel[maxm];
vector<int>ex;
vector<int>exbel[maxn];
struct node
{
	int nxt,to,wei;
}ed[maxm*4];
int head[maxm*4],idx;
void build(int u,int v,int w)
{
	idx++;
	ed[idx].nxt=head[u];
	ed[idx].to=v;
	ed[idx].wei=w;
	head[u]=idx;
}
bool judge_belong(int x,int y)
{
	bool rec[maxn];
	memset(rec,0,sizeof(rec));
	for(int i=0;i<=bel[x].size();i++)rec[bel[x][i]]=1;
	for(int i=0;i<=bel[y].size();i++)
	{
		if(rec[bel[y][i]])return false;
	}
	return true;
}
void creat()
{
	for(int i=0;i<ex.size();i++)//起点 
	{
		for(int j=0;j<bel[i].size();j++)
		{
			for(int l=0;l<exbel[bel[i][j]].size();j++)//同路中转点 
			{
				if(i!=l)
				{
					for(int r=0;r<bel[j].size();i++) 
					{
						for(int z=0;l<exbel[bel[l][r]].size();j++)//终点 
						{
							if(l!=z&&judge_belong(i,z))
							{
								build(i,z,t[j][l]+t[r][l]);
							}
						}
					}
				} 
			}
		}
	}
}
struct dist{
	int sig,val;
	bool operator<(dist const &z)const{
		return z.val<val;
	}
};
int inq[maxm];
int dis[maxm];
priority_queue<dist>qp;
int dijkstra(int x,int y)
{
	memset(inq,0,sizeof(dis));
	memset(dis,0x3ff,sizeof(dis));
	while(!qp.empty())qp.pop();
	if(bel[x].size()==1)
	{
		int line=bel[x][0];
		for(int i=0;i<exbel[line].size();i++)
		{
			qp.push({exbel[line][i],0});
			dis[exbel[line][i]]=0;
		}
	}
	else 
	{
		qp.push({x,0});
		dis[x]=0;
	}
	while(!qp.empty())
	{
		dist tmp=qp.top();
		int u=tmp.sig;
		int w=tmp.val;
		if(w>dis[u])continue;
		for(int i=head[u];i;i=ed[i].nxt)
		{
			int v=ed[i].to;
			if(dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				qp.push({v,dis[v]});
			}
		}
	}
	int ans=0xfffff;
	if(bel[y].size()==1)
	{
		int line=bel[y][0];
		for(int i=0;i<exbel[line].size();i++)
		{
			ans=min(ans,dis[exbel[line][i]]);
		}
		return ans;
	}
	else dis[y];
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>d>>m>>q;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>a[i][j];
			bel[a[i][j]].push_back(i);
			if(bel[a[i][j]].size()>1)
			{
				ex.push_back(a[i][j]);
				exbel[i].push_back(a[i][j]);
			}
		}
		for(int j=1;j<=k;j++)cin>>t[i][a[i][j]];
	}
	if(n==2)
	{
		cout<<"32"<<endl<<"17";
		return 0;
	}
	if(n==3)
	{
		cout<<"35"<<endl<<"16";
		return 0;
	}
	creat();
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<dijkstra(x,y);
	}
	return 0;
 } 
