#include<bits/stdc++.h>
using namespace std;
struct node{
	long long now,cnt;
};
long long c,t;
long long n,d;
long long isl[200005];
long long dis[7005][7005];
long long ans[7005][7005];
long long g[7005][7005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(ans,0,sizeof(ans));
		memset(g,-1,sizeof(g));
		cin>>n>>d;
		for(long long i = 1;i<=n;i++)
		{
			cin>>isl[i];
		}
		for(long long i = 1;i<=n;i++)
		for(long long j = i+1;j<=n;j++)
		{
			if(abs(isl[j]-isl[i])<=d)
			{
				g[i][j] = 1;
			}else
			break;
		}
		memset(dis,0x3f,sizeof(dis));
		for(long long k = 1;k<=n;k++)
		for(long long i = 1;i<=n;i++)
		for(long long j = 1;j<=n;j++)
		{
			if((!(i<k&&k<j))||g[i][k]==-1||g[k][j]==-1)
			continue;
			if(g[i][j]==-1)
			{
				ans[i][j]++;
				g[i][j] = g[i][k]+g[k][j];
			}
			else
			{
				if(g[i][j]<g[i][k]+g[k][j])
				continue;
				if(g[i][j]==g[i][k]+g[k][j])
				ans[i][j]++;
				if(g[i][j]>g[i][k]+g[k][j])
				g[i][j] = g[i][k]+g[k][j],ans[i][j] = 1;
			}
		}
		for(int i = 1;i<=n;i++)
		{
			for(int j = 1;j<=n;j++)
			{
				cout<<g[i][j]<<" ";
			}
			cout<<endl;
		}
		long long cnt = 0;
		for(long long i = 1;i<=n;i++)
		for(long long j = 1;j<=n;j++)
		if(ans[i][j]==2)
		cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
