#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair 
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e3+10;
vector<pii> g[N];
int d[N][N];
int c,n,m,D,q;
struct to
{
	int a;
	int t;
};
vector<to> p[N];
int k[N];
struct node
{
	int dis;
	int pos;
};
bool operator < (node qq,node w)
{
	return qq.dis>w.dis;
}
bool vis[N];

void dij(int s)
{
	for(int i=0;i<=m;i++)
	{
		vis[i]=0;
		d[s][i]=INT_MAX;
	}
	priority_queue<node> q;
	node ww;ww.dis=0;ww.pos=s;
	q.push( ww );
	d[s][s]=0;
	while(!q.empty())
	{
		node w=q.top();
		q.pop();
		
		int u=w.pos;
		if(vis[u]) continue;
		vis[u]=1;
		for(pii t : g[u])
		{
			int y=t.fi;
			
				if(d[s][y]>d[s][u]+t.se)
				{
					
					d[s][y]=d[s][u]+t.se;
					//if(d[s][y]==0 ) cout<<"cha "<<d[s][u]+t.se<<endl;
					if(!vis[y])
					{
						node rr;
						rr.dis=d[s][y];
						rr.pos=y;
						q.push(rr);
					}
				}
			
		}
	}
	return;
}
int w[N];

int t[N][N];

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	system("fc subway4.ans a.out"); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int sti=clock();
	
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}	
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			to qqq;
			cin>>qqq.a;
			cin>>qqq.t;
			p[i].push_back(qqq);
			
		}

	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<k[i];j++)
		{
			for(int l=j+1;l<k[i];l++)
			{
				int x=p[i][j].a;
				int y=p[i][l].a;
			//	cout<<x<<" "<<y<<endl;
				g[x].push_back(mp(y,p[i][j].t+p[i][l].t));
				g[y].push_back(mp(x,p[i][j].t+p[i][l].t));
			}
		}
	}
	
//	for(int i=1;i<=m;i++)
//	{
//		for(pii y : g[i])
//		{
//			cout<<y.fi<<" ";
//		}
//		cout<<endl;
//	}
//	return 1;
	for(int i=1;i<=m;i++)
	{
		dij(i);
//		for(int j=1;j<=m;j++)
//		{
//			cout<<d[i][j]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		cout<<d[x][y]+w[x]+w[y]<<"\n";
	}
//	cerr<<1.0*(clock()-sti)/CLOCKS_PER_SEC<<'\n';
	return 0;
 } 
 /*
 
 0 2 5 20 2
 4 1 9 2 5
 3 1 5 2 7 4 6
 3 2 3 3 4 5 7
 1 3
 1 2
 
  0 3 7 20 2
 8 3 6 1 7 2 9
 3 1 4 2 5 5 100
 3 2 6 3 1 7 2
 4 3 2 5 100 4 6 6 7
 1 6
 2 3
 */
