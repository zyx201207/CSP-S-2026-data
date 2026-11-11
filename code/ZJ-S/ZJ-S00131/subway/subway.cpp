#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int w[500010]; 
struct node{
	int k;//有多少站 
	vector <int> a; //有哪些站 
	map <int,int> t;//每站到站台的时间 
}dt[510];//一个路线的信息
vector <int> zt[500010]; //一个站台有哪些路线停靠 
bool vis[510];
int l,r;
long long mins=0xfffffffffffffff;
void dfs(int cnt,long long sum)//cnt:路线，sum：步行时间 
{
	if(sum>=mins) return;//剪枝 
	for(int i=0;i<dt[cnt].k;i++)//判断r是否在线路上 
	{
		if(dt[cnt].a[i]==r)
		{
			mins=min(mins,sum+dt[cnt].t[r]);
			return;
		}
	}
	for(int i=0;i<dt[cnt].k;i++)
	{
		int ztm=dt[cnt].a[i];//可换乘站台 
		if(zt[ztm].size()!=1)
		{
			for(int j=0;j<zt[ztm].size();j++)
			{
				int xl=zt[ztm][j];//换乘的新线路 
				if(xl!=cnt&&vis[xl]==0)
				{
					vis[xl]=1;
					dfs(xl,sum+dt[xl].t[ztm]+dt[cnt].t[ztm]);
					vis[xl]=0;
				}
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&p);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&dt[i].k);
		for(int j=1;j<=dt[i].k;j++)
		{
			int a1,t1;
			scanf("%d %d",&a1,&t1);
			dt[i].a.push_back(a1);
			dt[i].t[a1]=t1;
			zt[a1].push_back(i);
		}
	}
	for(int i=1;i<=p;i++)
	{
		scanf("%d %d",&l,&r);
		memset(vis,0,sizeof(vis));
		mins=0xfffffffffffffff;
		for(int j=0;j<zt[l].size();j++)
		{
			vis[zt[l][j]]=1;
			dfs(zt[l][j],dt[zt[l][j]].t[l]);
			vis[zt[l][j]]=0;
		}
		printf("%lld\n",mins+w[l]+w[r]);
	}
	return 0;
}

