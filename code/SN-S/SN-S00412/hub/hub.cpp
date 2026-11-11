//SN-S00412 YangRuibin TYZ
#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int type,T,n,k,ds[N];
vector<int>edge[N];
void add(int x,int y)
{
	edge[x].push_back(y);
}
void solve_bf()
{
	int ds[15][15];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)ds[i][j]=100;
	for(int i=1;i<=n;i++)
	{
		ds[i][i]=0;
		for(int j:edge[i])
			ds[i][j]=min(ds[i][j],1);
	}
	for(int p=1;p<=n;p++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				ds[i][j]=min(ds[i][j],ds[i][p]+ds[p][j]);
	int ans=10000;
	for(int s=0;s<(1<<n);s++)
	{
		int ppc=__builtin_popcount(s);
		if(ppc!=k)continue;
		int v[15]={0};
		int bcc=0;
		for(int i=1;i<=n;i++)
		{
			if(v[i]||((s>>(i-1))&1)==0)continue;
			++bcc;
			queue<int>q;
			q.push(i),v[i]=1;
			while(!q.empty())
			{
				int x=q.front();q.pop();
				for(int to=1;to<=n;to++)
				{
					if(ds[x][to]!=1||v[to])continue;
					if(((s>>(to-1))&1)==0)continue;
					v[to]=1,q.push(to);
				}
			}
		}
		if(bcc>2)continue;
		int now=0;
		for(int i=1;i<=n;i++)
		{
			int d=100;
			for(int j=1;j<=n;j++)
			{
				if(((s>>(j-1))&1)==0)continue;
				d=min(d,ds[i][j]);
			}
			now=max(now,d);
		}
		ans=min(ans,now);
	}
	printf("%d\n",ans);
}
int bfs(int s1,int s2)
{
	memset(ds,-1,sizeof(int)*(n+1));
	queue<int>q;
	if(s1!=-1)q.push(s1),ds[s1]=0;
	if(s2!=-1)q.push(s2),ds[s2]=0;
	int ret=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		ret=max(ret,ds[x]);
		for(int to:edge[x])
		{
			if(ds[to]!=-1)continue;
			ds[to]=ds[x]+1;
			q.push(to);
		}
	}
	return ret;
}
void solve_k_2()
{
	if(k==1)
	{
		int ans=1e9;
		for(int i=1;i<=n;i++)
			ans=min(ans,bfs(i,-1));
		printf("%d\n",ans);
		return;
	}
}
void solve_1314()
{
	
}
void solve()
{
	scanf("%d%d",&n,&k);
	for(int i=1,x,y;i<n;i++)
		scanf("%d%d",&x,&y),add(x,y),add(y,x);
	if(type<=3)return solve_bf(),void();
	if(type==13||type==14)
		return solve_1314(),void();
	if(type==7||type==11||type==12)
		return solve_k_2(),void();
}
void clear()
{
	for(int i=1;i<=n;i++)edge[i].clear();
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&type,&T);
	while(T--)solve(),clear();
	return 0;
}

