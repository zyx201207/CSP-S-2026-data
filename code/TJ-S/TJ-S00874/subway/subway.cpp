#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
struct tij
{
	int to,time;
};
int w[500005];
long long tz[505][505];
vector<tij>zhan[500005];
int main()
{/**/
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int nowin;
	memset(tz,0x3f,sizeof(tz));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&nowin);
		w[i]=nowin;
	}
	for(int i=1;i<=n;i++)
	{
		tz[i][i]=0;
	}
	vector<tij>lu[505];
	int k,to1,time1;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			scanf("%d %d",&to1,&time1);
			lu[i].push_back({to1,time1});
			zhan[to1].push_back({i,time1});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(tij j:zhan[i])
		{
			for(tij jj:zhan[i])
			{
				if(j.to<jj.to)
				{
					tz[jj.to][j.to]=tz[j.to][jj.to]=min(tz[j.to][jj.to],(long long)(j.time)+jj.time);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			for(int ij=1;ij<=n;ij++)
			{
				if(ij!=i&&ij!=j&&tz[i][ij]+tz[ij][j]<=1e14)
				{
					tz[j][i]=tz[i][j]=min(tz[i][j],tz[i][ij]+tz[ij][j]);
				}
			}
		}
	}
	int sta,en;/*
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<tz[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int i=1;i<=q;i++)
	{
		long long ans=1e18;
		scanf("%d %d",&sta,&en);
		for(tij i1:zhan[sta])
		{
			for(tij j1:zhan[en])
			{
				ans=min(ans,i1.time+j1.time+tz[i1.to][j1.to]);
			}
		}
		cout<<ans+w[sta]+w[en]<<endl;
	}/**/
	return 0;
}
