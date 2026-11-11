#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=502;
int read()
{
	int t=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')t=t*10+c-'0',c=getchar();
	return t*f;
}
int TEST_NUM,n,m,x,y,z,val[N],lim,q;
long long dis[M][M],ans;
vector<pair<int,int>>vec[N],e[M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	TEST_NUM=read(),m=read(),n=read(),lim=read(),q=read();
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++)val[i]=read();
	for(int i=1;i<=m;i++)
	{
		z=read();
		for(int v=1;v<=z;v++)
		{
			x=read(),y=read();
			e[i].push_back({x,y});
			vec[x].push_back({i,y});
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		cout<<i<<": ";
//		for(pair<int,int>it:vec[i])cout<<it.first<<" ";
//		cout<<"\n";
//	}
	for(int i=1;i<=m;i++)
	{
		for(pair<int,int>it:e[i])
		{
			for(pair<int,int>v:vec[it.first])dis[i][v.first]=min(dis[i][v.first],1ll*(it.second+v.second)),dis[v.first][i]=min(dis[v.first][i],1ll*(it.second+v.second));
		}
	}
	for(int i=1;i<=m;i++)
		for(int v=1;v<=m;v++)
			for(int z=1;z<=m;z++)dis[v][z]=min(dis[v][z],dis[v][i]+dis[i][z]);
//	cout<<dis[1][2]<<"|n";
	while(q--)
	{
		x=read(),y=read();
		ans=1e18+1;
		for(pair<int,int>i:vec[x])
		{
			for(pair<int,int>v:vec[y])
			{
//				cout<<"*"<<i.first<<" "<<v.first<<": "<<i.second<<" "<<v.second<<"\n";
				ans=min(ans,dis[i.first][v.first]+1ll*i.second+1ll*v.second);
			}
		}
//		cout<<ans<<"\n";
		cout<<ans+1ll*val[x]+1ll*val[y]<<"\n";
	}
	return 0;
}