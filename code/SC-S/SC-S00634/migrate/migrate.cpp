/*
T3就扔了吧，先打个暴力，反正T2分够了，估分213差不多了，七级勾应该有了吧 
暴力也要想怎么打，比如说建了边直接floyd，时间复杂度O(n^3)预期得分24?
*/
#include<bits/stdc++.h>
#define int long long
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
int c,t,n,d,x[1008617];
int dis[5005][5005],dis2[5005][5005]; //dis1存边数，dis2存储方案数量，dis2[i]=∑最短路的dis2[] 
namespace fastest_IO
{
	long long read()
	{
		int ans=0,res=1;
		char c=getchar();
		while(c<'0'||c>'9')
		{
			if(c=='-')res=-1;
			c=getchar();
		}
		while('0'<=c&&'9'>=c)
		{
			ans=ans*10+c-'0';
			c=getchar();
		}
		return ans*res;
	}
	void write(long long sum)
	{
		if(sum<10ll)putchar(sum+'0');
		else 
		{
			write(sum/10ll);
			putchar(sum%10ll+'0');
		}
	}
}
using namespace fastest_IO;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--)
	{
		n=read(),d=read();
		memset(dis,0x3f3f3f3fll,sizeof(dis));
		memset(dis2,0,sizeof(dis2));
		for(int i=1;i<=n;i++)x[i]=read();
		for(int i=1;i<=n;i++)dis[i][i]=0,dis2[i][i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(abs(x[i]-x[j])<=d)dis[i][j]=dis[j][i]=1,dis2[i][j]=dis2[j][i]=1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n;k++)
				{
					if(i==j)continue;
					if(k==i||k==j)continue;
					if(dis[i][k]+dis[j][k]==dis[i][j])dis2[i][j]+=dis2[i][k]*dis2[j][k];
					else if(dis[i][k]+dis[j][k]<dis[i][j])
					{
						dis2[i][j]=dis2[i][k]*dis2[j][k];
						dis[i][j]=dis[i][k]+dis[j][k];
					}
					if(dis2[i][j]>2)dis2[i][j]=3;
					//cerr<<i<<' '<<j<<' '<<dis2[i][j]<<'\n';
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)ans+=(dis2[i][j]==2);
		write(ans/2);
		puts("");
	}
	return 0;
}
/*
unaccepted 17:05 24pts total:216~224
*/
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/