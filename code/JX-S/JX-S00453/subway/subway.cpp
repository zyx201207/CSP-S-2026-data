#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<long long> w;
vector<int> fa[500010];
int s,e;
long long dist[510][510];
struct node
{
int v;
long long c;	
};
vector<node> dot[500010];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
for(int i=1;i<=505;i++)
memset(dist[i],0x3f,sizeof(dist[i]));
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=n+5;i++)
dist[i][i]=0;
for(int i=1;i<=m;i++)
{
	long long x;
	cin>>x;
	w.push_back(x);
}
for(int i=1;i<=n;i++)
{
	int k;
	cin>>k;
	int v;
	long long c;
	for(int j=1;j<=k;j++)
	{
	cin>>v>>c;
	dot[v].push_back({i,c});
	}
}

for(int i=1;i<=m;i++)// edge clarification
{
	if(dot[i].size()>=2)
	{
		for(int x=0;x<dot[i].size();x++) // from x road to y road
		{
			for(int y=0;y<dot[i].size();y++)
			{
				int tx=dot[i][x].v;
				int ty=dot[i][y].v;
				dist[tx][ty]=min(dist[tx][ty],dot[i][x].c+dot[i][y].c); 
				dist[ty][tx]=min(dist[ty][tx],dot[i][x].c+dot[i][y].c); 
			}
		}
	}
}
for(int k=1;k<=n;k++)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}
}	
for(int i=1;i<=q;i++)
{
 cin>>s>>e;
 long long minn=100000000000000000;
 for(int i=0;i<dot[s].size();i++)
 {
	 for(int j=0;j<dot[e].size();j++)
 {
	 minn=min(minn,dist[dot[s][i].v][dot[e][j].v]+dot[s][i].c+dot[e][j].c);
 }
 }
 cout<<w[s-1]+w[e-1]+minn<<endl;
}

return 0;
}
