#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*f;
}
int n,k,mark[15],dis[15],vis[15];
vector<int> vec[15];
void dfs(int u)
{
	vis[u]=1;
	for(int i=0;i<vec[u].size();i++)
		if(mark[vec[u][i]]&&!vis[vec[u][i]])dfs(vec[u][i]);
}
void dfs2(int u)
{
	for(int i=0;i<vec[u].size();i++)
		if(dis[vec[u][i]]>dis[u]+1)
		{
			dis[vec[u][i]]=dis[u]+1;
			dfs2(vec[u][i]);
		}
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c=read(),t=read();
	while(t--)
	{
		n=read(),k=read();
		for(int i=1;i<=n;i++)vec[i].clear();
		for(int i=1;i<n;i++)
		{
			int u=read(),v=read();
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		int ans=INT_MAX;
		for(int i=0;i<(1<<n);i++)
		{
			int tmp=0;
			memset(mark,0,sizeof(mark));
			memset(dis,0x3f,sizeof(dis));
			memset(vis,0,sizeof(vis));
			for(int j=0;j<n;j++)mark[j+1]=(i>>j)&1;
			int sum=0;
			for(int j=1;j<=n;j++)sum+=mark[j];
			if(sum>k)continue;
			int cnt=0;
			for(int j=1;j<=n;j++)
				if(mark[j]&&!vis[j])
				{
					dfs(j);
					cnt++;
				}
			if(cnt>2)continue;
			for(int j=1;j<=n;j++)
				if(mark[j])
				{
					dis[j]=0;
					dfs2(j);
				}
			for(int j=1;j<=n;j++)tmp=max(tmp,dis[j]);
			ans=min(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}
//yi jiu shi pian ai zhen jing hong er zi ru meng de shi jie
//zhu huo xing song que ke yu ta man liao che ye
//zao chun mu chun,jiu nuan hua shen
//yi ren xin shi zhi de you yi ren lai jie
//sui sui hua zao yan xia gong jiang tang li jian xue
//zong you mou ri ni wo gong zhi hai jiao tian bian
//tian qing mu qing,su yu zhan jin
