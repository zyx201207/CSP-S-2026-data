#include<iostream>
#include<cmath>
#include<map>
#include<set>
#include<tuple>
#include<deque>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1005;
vector<int> G[N];
bool inthecho[N],vis[N];
int c,T,n,k,cho[N]/*k座已选择城市*/,ind=0,dis[N][N],d[N],ans=0x3f3f3f3f;
void Calc_len()
{
	for(int i=1;i<=n;i++)
		d[i]=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		if(inthecho[i]) d[i]=0;
		else
		{
			for(int r=1;r<=k;r++)
				d[i]=min(d[i],dis[i][cho[r]]);
		}
	}
	return;
}
void Dfs_find(int u,int fa)
{
	vis[u]=true;
	for(int v:G[u])
	{
		if(!inthecho[v]||v==fa) continue;
		Dfs_find(v,u);
	}
	return;
}
bool Check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		vis[i]=false;
	for(int r=1;r<=k;r++)
		if(!vis[cho[r]]) cnt++,Dfs_find(cho[r],0);
	if(cnt<=2) return true;
	return false;
}
vector<int> per;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	IOS;
	cin>>c>>T;
	while(T--)
	{
		ans=0x3f3f3f3f;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=0x3f3f3f3f;
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
			dis[u][v]=dis[v][u]=1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);//通勤距离是min_dis_i
		while(!per.empty()) 
			per.pop_back();
		for(int i=1;i<=n-k;i++)
			per.push_back(0);
		for(int i=1;i<=k;i++)
			per.push_back(1);
		for(int i=1;i<=n;i++)
			inthecho[i]=false;
		int tmp1=0;
		for(int i=0;i<n;i++)
			if(per[i]) cho[++tmp1]=i+1,inthecho[i+1]=true;
		if(Check())
		{
			Calc_len();
			int maxx=0;
			for(int i=1;i<=n;i++)
				maxx=max(maxx,d[i]);
			ans=min(ans,maxx);
		}
		while(next_permutation(per.begin(),per.end()))
		{
			for(int i=1;i<=n;i++)
				inthecho[i]=false;
			int tmp=0;
			for(int i=0;i<n;i++)
				if(per[i]) cho[++tmp]=i+1,inthecho[i+1]=true;
			if(Check())
			{
				Calc_len();
				int maxx=0;
				for(int i=1;i<=n;i++)
					maxx=max(maxx,d[i]);
				ans=min(ans,maxx);
			}
		}
		for(int i=1;i<=n;i++)
			while(!G[i].empty()) 
				G[i].pop_back();//attention!
		cout<<ans<<'\n';
	}
	return 0;
}