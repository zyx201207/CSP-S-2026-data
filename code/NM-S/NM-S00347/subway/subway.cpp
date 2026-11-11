#include<bits/stdc++.h>
using namespace std;
int c,n,m,k,d,qq,w[500005],a,timm,x,y;
priority queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > > q;
struct node{
	int lu,t;
};
vector<node> bc[500005];
void dsyt(int s)
{
	for(int i=0;i<=n;i++)
	 d[i]=0x3f3f3f;
	d[s]=0;
	q.push({0,s});
	while(!q.empty())
	 {
	 	pair<int,int> t=q.top();
	 	q.pop();
	 	int u=t.second;
	 	if(vis[u]!=0) continue;
	 	vis[u]=1;
	 	for(int k=0;k<bc[u].size();k++)
	 	 {
	 	 	int v=bc[u][k].lu,w=bc[u][k].t;
	 	 	if(d[v]>d[u]+t) d[v]=d[u]+t;
	 	 	                q.push({d[v],v});
		  }
	 }
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n>>m>>d>>qq;
	while(qq--)
	 {
	 	for(int i=1;i<=m;i++)
	 	 cin>>w[i];
	 	for(int i=1;i<=n;i++)
	 	 {
	 	 	cin>>k;
	 	 	for(int j=1;j<=k;j++)
	 	 	 {
	 	 	 	cin>>a>>timm;
	 	 	 	bc[a].push_back({i,timm});
			   }
		  }
		cin>>x>>y;
		for(int i=0;i<bc[x].size();i++)
		 for(int j=0;j<bc[y].size();j++)
		  if(bc[x][i].lu==bc[y][j].lu) {cout<<bc[x][i].t+bc[y][j].t+w[x]+w[y]<<endl;return 0;}
		           else {dsyt(x);cout<<d[y];}
	 }
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
