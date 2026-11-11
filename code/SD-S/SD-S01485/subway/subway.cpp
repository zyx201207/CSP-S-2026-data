#include<bits/stdc++.h>
#define int long long
#define pa pair<int,int>
using namespace std;
const int N=500005,M=505,INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,A[N];
//vector<int>G[N];
int DP[M][M];
vector<pair<int,int> >R[N];
int read()
{
	int x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<1)+(x<<3)+c-'0',c=getchar();
	return x;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)
		A[i]=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++)
		{
			int a=read(),t=read();
			R[a].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				DP[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		for(pa pa1:R[i])
		{
			int spa1=pa1.first,tpa1=pa1.second;
			for(pa pa2:R[i])
			{
				int spa2=pa2.first,tpa2=pa2.second;
				DP[spa1][spa2]=min(DP[spa1][spa2],tpa1+tpa2);
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int z=1;z<=n;z++)
				DP[j][z]=min(DP[j][z],DP[j][i]+DP[i][z]);
	while(q--)
	{
		int x=read(),y=read();
		int ans=INF;
		for(pa pa1:R[x])
		{
			int spa1=pa1.first,tpa1=pa1.second;
			for(pa pa2:R[y])
			{
				int spa2=pa2.first,tpa2=pa2.second;
				ans=min(ans,tpa1+tpa2+DP[spa1][spa2]);
			}
		}
		printf("%lld\n",ans+A[x]+A[y]);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4  5 7
1 3
32
1 2
17

byebye int merge!!!
*/
