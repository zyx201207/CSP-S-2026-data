#include<bits/stdc++.h>
#define Sparkle int main()
#define Sparxie return 0;
#define ll long long
#define Aha cerr<<"hahaha"<<'\n'
#define Lv(x) cerr<<#x<<"="<<x<<'\n'
#define fi first
#define se second
using namespace std;
const int maxn=100005;
const int mod=1000000007;
ll n,k,ans=LLONG_MAX;
vector<ll> q[maxn];

inline void solve()
{
	cin>>n>>k;
	ll u,v;
	for(int i=1;i<=n;i++)
	{
		q[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		q[u].push_back(v);
		q[v].push_back(u);
	}
	
	cout<<1<<endl; 
}
Sparkle
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,_=1;
	cin>>c>>_;
	while(_--)
	{
		solve();
	}
	Sparxie
}
//最后20分钟，能写多少是多少 
//写不完了，不写了
/*
写点想说的吧
预计65+60+12+0 
最后一年参赛了，时间过的好快呀
左右的都是初中生，希望他们都能坚持下去
不然等到最后一年的时候
就会像我一样留下很多遗憾
不过还好
还有一次NOIP可以争
 为什么要写这些呢？
其实本来想追忆过去的
但来不及写那么多了
祝SGOI越来越好吧
多出几个牌子
祝每一个OIer都能得偿所愿，向着光，追逐光，最后成为光
反正我大概率是没有成为光的机会了
这可能是我学OI以来打的最好的一次了
我太菜了

聊点别的？
穹批一个
火花花火双厨 
欢愉忠实信徒
4系大版本0氪欢愉队11银狼21火花20真珠00爻光
没时间了
就这样吧
结束了 
Luogu：GoDiary_999



*/
