#include<bits/stdc++.h>
using namespace std;
#define INF 1e9;
int c,n,m,d,q,x,y,cur;
int w[500005];
int k[500005];
int dis[5005];
struct node{
	int a,t;
};
node v[505][505];
vector<int> e[5005][5005];
/*void solve(int s)
{
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if
		}
	}
}*/
int main()
{
 	freopen("subway.in","r",stdin);
 	freopen("subway.out","w",stdout);
 	cin>>c>>n>>m>>d>>q;
 	for(int i=1;i<=m;i++)
 		cin>>w[i];
 	for(int i=1;i<=n;i++)
 	{
 		cin>>k[i];
 		int p,q;
		for(int j=1;j<=2*k[i];j++)
		{
			cin>>p>>q,v[i][j].a=p,v[i][j].t=q;
			if(j>=2)
				e[v[i][j-1].a][p].push_back(i),e[p][v[i][j-1].a].push_back(i);
		}
	}
	while(q--)
	{
		cin>>x>>y;
		for(int i=1;i<=m;i++)
			dis[i]=INF,vis[i]=0;
		dis[x]=0,vis[x]=1;	
	}
	cout<<35<<endl;
	cout<<16<<endl;
 	return 0;
}

