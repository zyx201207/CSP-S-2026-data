//SN-S00468 钟林希 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500050],la,k,sum[505][50050],st,se,ans;
struct dian
{
	int id,op;
};
struct Edge
{
	dian ai;
	int vi;	
};
struct Node
{
	dian b;
	int diss;
	bool operator<(const Node &b)const
	{
		return diss>b.diss;
	}
};
vector<int>a[50050];
vector<Edge>G[505][50050];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			a[x].push_back(i);
			sum[x][i]=y;
			if(j!=1)
			{
				G[x][i].push_back({{la,i},0});
				G[la][i].push_back({{x,i},0});
			}
			la=x;
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			for(int z=1;z<=n;z++)
				G[i][j].push_back({{i,z},sum[i][j]+sum[i][z]});
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&st,&se);
		priority_queue<Node>pri;
		int e[505][500050],dis[505][500050];
		memset(e,0,sizeof e);
		memset(dis,0x3f,sizeof dis);
		for(auto &it:a[st])pri.push({{st,it},sum[st][it]});
		while(!pri.empty())
		{
			Node Z=pri.top();
			pri.pop();
			if(e[Z.b.id][Z.b.op])continue;
			else e[Z.b.id][Z.b.op]=1;
			for(auto &it:G[Z.b.id][Z.b.op])
			{
				if(dis[it.ai.id][it.ai.op]>Z.diss+it.vi)
				{
					dis[it.ai.id][it.ai.op]=Z.diss+it.vi;
					pri.push({{it.ai.id,it.ai.op},dis[it.ai.id][it.ai.op]});
				}
			}
		}	
		ans=-1e9;
		for(auto &it:a[se])ans=min(ans,dis[se][it]);
		cout<<w[st]+w[se]+ans;
	}
	return 0;
}
