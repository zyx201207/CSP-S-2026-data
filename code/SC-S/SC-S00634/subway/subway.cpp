/*
数据范围巨大，考虑计算两条线路的最短换乘时间，存得下，查询O(d^2)
此处的O(d^2)是因为出发和到达站也可能是换乘站，于是还要枚举 
现在考虑如何进行计算
对于每一个换乘站，直接两两取min………………
时间复杂度O(md^2+qd^2)，大概是2e1*2e1*5e5*2，总时间复杂度4e8，能过了？ 还有1/2的常数，可能没问题 
不对吧？
写一下 
停！不能直接换乘呢？
再来一个floyd，在给定了不少边权的情况下跑，就行了 
*/
#include<bits/stdc++.h>
#define getchar getchar_unlocked
#define putchar putchar_unlocked
using namespace std;
long long mct[505][505];//min changing time,最小换乘时间
int sum[1008617];//一个地铁站出站的时间 
int c,n,m,d,q;
vector<pair<int,int> > g[1008617];//每个站点的线路数量 
int t[505][500005];
namespace fastest_IO
{
	long long read()
	{
		int ans=0;
		char c=getchar();
		while(c<'0'||c>'9')c=getchar();
		while('0'<=c&&'9'>=c)
		{
			ans=ans*10+c-'0';
			c=getchar();
		}
		return ans;
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
#define int long long
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	memset(mct,0x3f3f3f3fll,sizeof(mct));
	for(int i=1;i<=m;i++)sum[i]=read();
	for(int i=1;i<=n;i++)mct[i][i]=0;
	for(int i=1;i<=n;i++)
	{
		int res;
		res=read();
		for(int j=1;j<=res;j++)
		{
			int u=read(),w=read();
			t[i][u]=w;
			g[u].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++)
	{
		//这里可以优化掉1/2的常数，到时候再说
		for(auto x:g[i])
		{
			int u=x.first,w1=x.second;
			for(auto y:g[i])
			{
				if(y==x)continue;
				int v=y.first,w2=y.second;
				mct[u][v]=mct[v][u]=min(mct[u][v],(long long)w1+w2);
			}
		} 
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j)continue;
				if(k==i||k==j)continue;
				mct[i][j]=min(mct[i][j],mct[i][k]+mct[j][k]);
			}
		}
	}
	/*
	忘记floyd怎么写了，反正只有八种，等会儿试试 （测大洋里的时候） 
	*/
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=n;j++)
//		{
//			cout<<mct[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	while(q--)
	{
		int a=read(),b=read();
		long long ans=1e18;
		//这里可以优化掉1/2的常数，到时候再说
		for(auto x:g[a])
		{
			int u=x.first,w1=x.second;
			for(auto y:g[b])
			{
				int v=y.first,w2=y.second;
				//cout<<u<<' '<<v<<' '<<ans<<'\n';
				ans=min(ans,(long long)(mct[u][v]+t[u][a]+t[v][b]));
			}
		} 
		write(ans+sum[a]+sum[b]);
		puts("");
	} 
	return 0;
} 
/*
probably accepted 16:15 92~100 total:192~200(比去年总分还高了！！！)
*/
/*
1:

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

阳历2：
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
 
*/