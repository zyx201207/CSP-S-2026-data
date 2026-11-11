#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const long N=510000;
long c,n,m,d,q,w[N],k[N],a[600][70000],t[600][70000],x[N],y[N],p[N];
bool s1[600][70000],s2[600][70000],flag[N];
long dfs(long zhan,long tail,long time,long xian,bool map[N])
{
	if(zhan==tail)
	{
		cout<<"find"<<endl;
		return time;
	}
	long ans=1e9;
	for(long j=1;j<=p[zhan];j++)//枚举站到线 
	{
		for(long i=1;i<=k[i];i++)//枚举线到站 
		{
			long mux=s1[zhan][j];
			long mu=s2[mux][i];
			
			if(map[mu]==1)continue;
			if(xian!=mux&&xian!=0)
			{
				map[mu]=1;
				ans=min(ans,dfs(mu,tail,time+t[zhan][mux]+t[mux][mu],mux,map));
			}
			if(xian==0)
			{
				map[mu]=1;
				ans=min(ans,dfs(mu,tail,time+t[zhan][mux],mux,map));
			}
			else
			{
				map[mu]=1;
				ans=min(ans,dfs(mu,tail,time,mux,map));
			}
		}
	}
	return ans;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long i=1;i<=m;i++)
	{
		scanf("%ld",&w[i]);
		
	}
	for(long i=1;i<=n;i++)
	{
		scanf("%ld",&k[i]);//路线过多少站点 
		for(long j=1;j<=k[i];j++)
		{
			scanf("%ld%ld",&a[i][j],&t[i][j]);
			t[j][i]=t[i][j];
			p[a[i][j]]++;//站点有多少路线
			s1[j][p[a[i][j]]]=i;//可从j站到i线
			s2[i][j]=a[i][j];//可从i线到j站 
			 
		} 
	}
	for(long i=1;i<=q;i++)
	{
		scanf("%ld%ld",&x[i],&y[i]);
		flag[x[i]]=1;
		printf("%ld",dfs(x[i],y[i],0,0,flag)+w[x[i]]+w[y[i]]);
	}
	
	return 0;
} 
