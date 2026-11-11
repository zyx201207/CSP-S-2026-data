//Just Sayori
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<vector>
#include<random>
#define ll long long
#define ull unsigned long long
#define gr getchar
#define pr putchar
#define N 500005
//#define M 1000000007
//#define M 998244353
#define M 0x3f3f3f3f3f3f3f3f
#define for1(i,a,b) for(auto i=(a);i<=(b);i++)
#define for2(i,a,b) for(auto i=(a);i>=(b);i--)
using namespace std;
inline ll read()
{
	ll x=0,f=1;
	char ch=gr();
	while (ch<'0' || ch>'9') ch=='-'?f=-1,ch=gr():ch=gr();
	while (ch>='0' && ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=gr();
	return x*f;
}
//inline int add(int a,int b,const int mod=M){return (a+=b)>=mod?a-mod:a;}
//inline int del(int a,int b,const int mod=M){return (a-=b)<0?a+mod:a;}
template<typename T> inline bool chkmin(T &a,T b){return a>b?a=b,1:0;}
template<typename T> inline bool chkmax(T &a,T b){return a<b?a=b,1:0;}
int k[N],w[N];
ll d[505][505];
vector<pair<int,ll>> ve[N];
int main()
{
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c=read(),n=read(),m=read(),g=read(),q=read(),a,s,t;
	ll ans;
	for1 (i,1,m) w[i]=read();
	for1 (i,1,n)
	{
		k[i]=read();
		for1 (j,1,k[i]) a=read(),t=read(),ve[a].emplace_back(i,t);
	}
	for1 (i,1,n)
		for1 (j,1,n)
			d[i][j]=M;
	for1 (i,1,n) d[i][i]=0;
	for1 (i,1,m)
		for1 (j,0,(int)ve[i].size()-1)
			for1 (k,j+1,(int)ve[i].size()-1)
				chkmin(d[ve[i][j].first][ve[i][k].first],ve[i][j].second+ve[i][k].second),chkmin(d[ve[i][k].first][ve[i][j].first],ve[i][j].second+ve[i][k].second);
	for1 (k,1,n)
		for1 (i,1,n)
			for1 (j,1,n)
				chkmin(d[i][j],d[i][k]+d[k][j]);
//	for1 (i,1,n)
//		for1 (j,1,n)
//			cout<<d[i][j]<<" \n"[j==n];
	for1 (i,1,q)
	{
		s=read(),t=read(),ans=M;
		for1 (i,0,(int)ve[s].size()-1)
			for1 (j,0,(int)ve[t].size()-1)
				chkmin(ans,d[ve[s][i].first][ve[t][j].first]+ve[s][i].second+ve[t][j].second);
		cout<<ans+w[s]+w[t]<<"\n";
	}
	return 0;
}
/*
做不出 T2，自刎归天！
首先肯定没法最短路，这个查询就不好搞
但是我们发现没必要最短路，注意到 d 这个性质，肯定是要用上的
考虑如何做，我们可以分别枚举两个人的一条铁路路线，那么是不是要 O(1) 求解啊
感觉就差一点了啊
我们考虑对于一个询问各自的一条铁路。
然后最开始我们枚举两条铁路，求出它们相交的位置分别是在这两条铁路上的第几号
那么对于询问，要求这两条铁路上有一个位置满足在 x 的后面且在 y 的前面的最小值
二维偏序可以 log，但是这样就是 4e7 的 log 了
但是我们可以发现位置的个数不会超过 md^2，是 2e8 的
额，这怎么老哥
不对啊，我的做法有问题，你不一定只会转一条线啊
等等啥意思，线路是可以反着走的吗
tm 的，什么神人出题人，线路可以反着走都不说，给我气笑了
那么我们应该就可以算两条铁路的距离了！
初始就是对于 i，它在多条铁路中被算到，那么更新这些铁路之间的距离
然后可以 floyd 求出所有铁路之间的距离
然后就可以 O(1) 查询了！
妈妈，我终于做出来 T2 了
不过我们的太子爷应该已经 AK 了吧
*/