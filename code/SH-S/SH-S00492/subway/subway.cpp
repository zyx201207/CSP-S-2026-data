#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
#include<utility>
#include<cstring>
using namespace std;
const int max_n=505,max_k=500005;
int land_to_floor[max_k];
struct Trans
{
	int id,len;
	Trans(){}
	Trans(int a,int b)
	{
		id=a,len=b;
	}
};
vector<Trans> floors[max_k];//first:id , second:len
int road_g[max_n][max_n];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(road_g,0x3f,sizeof(road_g));
	for(int i=0;i<max_n;i++)
		road_g[i][i]=0;
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&land_to_floor[i]);
	for(int i=1;i<=n;i++)
	{
		int temp;
		scanf("%d",&temp);
		for(int j=1;j<=temp;j++)
		{
			Trans cur;
			int pass_floor,time ;
			scanf("%d%d",&pass_floor,&time);
			cur=Trans(i,time);
			floors[pass_floor].push_back(cur);
		}
	}
	for(int i=1;i<=m;i++)
		for(vector<Trans>::iterator it=floors[i].begin();it != floors[i].end();it++)
			for(vector<Trans>::iterator it2=floors[i].begin();it2 != floors[i].end();it2++)
				road_g[it->id][it2->id]=min(road_g[it->id][it2->id], it->len + it2->len ),road_g[it2->id][it->id]=min(road_g[it2->id][it->id], it->len + it2->len );
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				road_g[i][j]=min(road_g[i][j],road_g[i][k] + road_g[k][j]);
	
	for(int i=1;i<=q;i++)
	{
		long long ans=0x3f3f3f3f,ans_from,ans_to;
		int from,to;
		scanf("%d%d",&from,&to);
		for(Trans stat:floors[from])
			for(Trans end:floors[to])
			{
				if (ans > road_g[stat.id][end.id])
					ans = road_g[stat.id][end.id],ans_from=stat.len,ans_to=end.len;
			}
		printf("%lld\n",ans + ans_from + ans_to + land_to_floor[from] + land_to_floor[to]);
	}
	return 0;
}
