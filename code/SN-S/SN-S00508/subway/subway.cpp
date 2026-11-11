//by : xt66666
//lihaoyang
//TYZ
//SN-S00508
//luogu uid : 去年就忘了，今年还是没记住
//太棒了今年T1贼简单
//不过我忘排序跳了整整1min
//嘿
//好像是最短路状物 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mid ((l+r)>>1)
#define lc t[p].ls
#define rc t[p].rs
#define pb push_back
#define fir first
#define sec second
//？！我直接……
//直接暴力每次跑一个最短路
//复杂度就是mq量级
//5e10
//先写个暴力
ll Test,n,m,D_max,Q;
ll ste[510][510];
ll w[500010];
//暴力写完了，看T3，一会在想T2
//太棒了看完T3严肃发现自己只配想T2
//n<=300
//嗯
//n方的 话呢
//不对我先存一下暴力 
//实际上这道题和站台的关系不大
//可以枚举一下
//就是任意两个站台，把距离预处理
//然后枚举出栈和入栈的线路是哪一条
// 就是这样，所以d<=20,20*20*5e5,2e8
//还得精细实现不然卡常
//我试乐子这题Q<=1e5不是5e5
//没错应该就是这么做的
//let me think think 
//我一辈子的英语功底都在上面那句话了不要笑
//哦我知道了，先枚举一个站台的线路
//把这个边弄好
//然后弗洛……点爱哦（确信
//floyd
//不管了写吧，其实我到现在不明白floyd的原理但是以后再说吧
//反正就三个循环背过了哈哈
//不不不不不m<=5e5卡常 
//2e8的话，额总共应该有个3e8
//CCF其实我喜欢你能不能不要卡我QAQ 
vector<pair<ll,ll> > g[500010];
void solve()
{
	

	cin>>Test>>n>>m>>D_max>>Q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		while(k--)
		{
			ll a,t;
			cin>>a>>t;
			g[a].pb({i,t});
		}
	}
	memset(ste,0x3f,sizeof(ste));
	//嗯我哦好像突然明白floyd 的原理了 
//	return ;

	for(int i=1;i<=n;i++)ste[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<(ll)g[i].size();j++)
		{
			for(int k=0;k<(ll)g[i].size();k++)
			{
				ll x=g[i][j].fir,y=g[i][k].fir;
				ll w1=g[i][j].sec,w2=g[i][k].sec; 
				ste[x][y]=min(ste[x][y],w1+w2);
			}
		}	 
	}
	//某高一巨佬虽然我不知道叫啥但是跑错考场来我们这了 
//	cout<<ste[1][2]<<' '<<ste[2][1]<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				ste[j][k]=min(ste[j][i]+ste[i][k],ste[j][k]);
			}
		}
	}//无向边很好弄 
	//
//	cout<<ste[2][2]<<endl;
	while(Q--)
	{
		ll x,y;
		cin>>x>>y;
		ll ans=1e18;
		for(int i=0;i<(ll)g[x].size();i++)
		{
			for(int j=0;j<(ll)g[y].size();j++)
			{
//				if(g[x][i].fir==g[y][j].fir&)
//			cout<<g[x][i].fir<<' '<<g[y][j].fir<<endl;
				ans=min(ans,ste[g[x][i].fir][g[y][j].fir]+g[x][i].sec+g[y][j].sec);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
}
//500开成300幸好RE不然挂大分 
//OK大阳历过了对拍一下
//重新换个文件夹吧这个不动了 
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll T=1;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	while(T--)solve();
	return 0;
}

