#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int w[505];
int k[505];
int a[1005][1005];
int t[1005][1005];
long long ddis[2505][2505];
int newdian;
const int N=500505;
struct Point
{
	int p;
	long long val;
	bool operator<(const Point &a)const
	{
		return val>a.val;
	}
};
long long dis[N];
int vis[N];
vector<pair<int,long long> > v[N];
priority_queue<Point> q;
void dij(int s)
{
	memset(vis,0,sizeof vis);
	memset(dis,0x3f3f3f3f,sizeof dis);
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		Point a=q.top();
		q.pop();
		if(vis[a.p])continue;
		vis[a.p]=1;
		for(int i=0;i<v[a.p].size();i++)
		{
			int  fi=v[a.p][i].first;
			long long se=v[a.p][i].second;
			if(dis[fi]>dis[a.p]+se)
			{
				dis[fi]=dis[a.p]+se;
				q.push({fi,dis[fi]});
			}
		}
	}
 } 
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	newdian=m+1;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	int bianshu=0;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]].push_back({newdian++,t[i][j]});
			v[newdian-1].push_back({a[i][j],t[i][j]});
			bianshu++;
			if(j!=1)
			{
				v[newdian-1].push_back({newdian-2,0});
				v[newdian-2].push_back({newdian-1,0});
				bianshu++;
			}
			
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(ddis[x][y]!=0)
		{
			cout<<w[x]+ddis[x][y]+w[y]<<"\n";
			
		}
		else
		{
			dij(x);
			for(int i=1;i<=newdian-1;i++)
			{
				ddis[x][i]=dis[i];
			}
			cout<<w[x]+ddis[x][y]+w[y]<<"\n";
		}
	}
	return 0;
}
