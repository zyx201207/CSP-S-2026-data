#include<bits/stdc++.h>
using namespace std;

struct nd{
	long long x;
	long long y;
};

long long ting[500005];
vector<nd>tai[505];
vector<int>che[500005];
int wz[505][20005];
bool use[500005],vis[105];
long long ans;

void dfs(int x,int y,long long step)
{
	int ch=0;
	//cout<<x<<' '<<y<<' '<<step<<' '<<ch<<endl;
	if (x==y)
	{
		ans=min(ans,step);
		return ;
	}
	if (use[x]) return ;
	use[x]=1;
	//vis[ch]=1;
	//step+=tai[ch][wz[ch][x]].y;
	int b=che[x].size();
	//cout<<b<<'*'<<endl;
	for (int i=0;i<b;i++)
	{
		if (!vis[che[x][i]])
		{
			ch=che[x][i];
			vis[ch]=1;
			step+=tai[ch][wz[ch][x]].y;
			int e=tai[ch].size();
			//cout<<ch<<endl;
			for (int j=0;j<e;j++)
			{
				if (!use[tai[ch][j].x])
				{
					//cout<<tai[ch][j].x<<endl;
					step+=tai[ch][j].y;
					use[x]=1;
					dfs(tai[ch][j].x,y,step);
					step-=tai[ch][j].y;
					use[x]=0;
				}
			}
			step-=tai[ch][wz[ch][x]].y;
		}
	}
	//step-=tai[ch][wz[ch][x]].y;
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(wz,-1,sizeof(wz));
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for (int i=1;i<=m;i++)
	{
		cin>>ting[i];
	}
	for (int i=1;i<=n;i++)//线路 
	{
		int k;
		cin>>k;
		for (int j=0;j<k;j++)//线路经过的站台 
		{
			nd w;
			cin>>w.x>>w.y;//站台，时间 
			//cout<<i<<' '<<w.x<<' '<<w.y<<endl;
			tai[i].push_back(w);
			che[w.x].push_back(i);
			wz[i][w.x]=j;
		}
	}
	while (q--)
	{
		long long u,v,mi=LONG_LONG_MAX;//站台 
		cin>>u>>v;
		ans=LONG_LONG_MAX;
		dfs(u,v,0);
		mi=min(mi,ans);
		cout<<mi+ting[u]+ting[v]<<endl;
		memset(vis,0,sizeof(vis));
		memset(use,0,sizeof(use));
	}
}
