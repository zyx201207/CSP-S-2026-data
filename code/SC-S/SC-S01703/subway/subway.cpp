#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
struct node
{
	int b,w;
};
long long ljjz[N][N];
int fa[M],W[M],zx[M];
long long dp[N][N];
vector<node> dd[M];//
//int find(int x)
//{
//	if(fa[x]==x)return x;
//	return fa[x]=find(fa[x]);
//}
//void merge(int a,int b)
//{
//	a=find(a),b=find(b);
//	fa[b]=a;
//}
int main()
{
	freopen("subway.in","r",stdin);//考试之后记得拿回水杯和纸巾
	freopen("subway.out","w",stdout);//考试之后记得拿回水杯和纸巾
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);//考虑这个特性b。有边就行，那么枚举每个暴力连边，复杂度：(nW)/w，此处W指最大含点个数
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&W[i]);
	}
	memset(ljjz,0x3f,sizeof(ljjz));
	for(int i=1;i<=n;i++)ljjz[i][i]=0;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a,w;
			scanf("%d%d",&a,&w);
			dd[a].push_back({i,w});
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(node j:dd[i])
		{
			for(node k:dd[i])
			{
				ljjz[j.b][k.b]=min(ljjz[j.b][k.b],1ll*j.w+k.w);
			}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]=ljjz[i][j];
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
			}
		}
	}
	while(q--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		long long minn=1e18;
		for(node i:dd[a])
		{
			for(node j:dd[b])
			{
				minn=min(minn,dp[i.b][j.b]+i.w+j.w+W[a]+W[b]);
			}
		}
		printf("%lld\n",minn);
	}
	return 0;
}
/*
缩点，那么肯定是跑全源最短路，然后查询了
但是CCF评测机好像比较慢来着
这个建图非常垃圾啊
查询部分还好，最短路应该也能做做，但是他一个建图就有2e8，大部分都是废物边
我们考虑去掉废物边
查询两个地铁线路之间的直接连边，那么肯定要看同时包含他们的地铁站，然后枚举……
这只能枚举吗
绝不可能建出地铁站吧
算了，再垃圾他也是个84分暴力啊，不想了
CCF评测机不太行，难道有125e6的题？肯定是n^2d的吧
先放着，T3打完暴力再来看
*/
/*
这里的话如果直接暴力建图，复杂度先来一个md^2，然后全源最短路，复杂度为n^3，真能过吗？
A特性自己就被过了，B特性改一点点就能打
所以，这是一个很好的算法，可以获取到84分
这怎么假算冲过去了，不会是正解吧！
*/