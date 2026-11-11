#include<bits/stdc++.h>
#define int long long
#define fr first
#define sc second
#define pii pair<int,int>
using namespace std;
const int inf=1e18;


/*
东营没有地铁，我还要先自己理解如何坐地铁，
还好我前一天玩了青鱼轨道
应该是 ：地铁口->站厅->若干站台->
->站厅->若干站台->重复->地铁口
答案组成首先有w_s和w_t，这个最后单独加就行
然后每条线路的实质是，从u到v只需要花费t_u+t_v即可
可以对每个线路建立一个虚点，u到第i个线路的权值为t_iu
总边数大约是5e6~1e7，实在不行最后写暴力
好困难啊，图论有前途吗？四点之后再写吧
海岛、展览、划分、游戏，这个应该是游戏了，考虑数据结构
我想不出来！打个六十暴力，T3T4暴力一打走人吧，我赌今年分数线<200
期待五点之前写完
16.23我似乎会了？常熟略大，精细实现应该可以
草，为啥是dmlogm+qd^2的？！qd^2可以去掉一个d吗
no，假了
哦，还好只是我写挂了，测了测样例，算法应该没错
问题是我数组开不下，就要止步于此了吗？
我要开始神秘优化了 
我在SD，分数线不会>200，我将死磕T2一直到六点
直接floyd还比n次dij快
2s2s2s!! 
关流大样例0.78s，ccf少爷机求你了，让我过吧，这样我明年还会给你捐钱的 
哦，原来是没开O2，开了就0.3s，ok 
六点十分了，就这样吧，100+100+0+0 
T3还能挣吗？反正距离wc很远，sd去年都280，随便打几分吧 
*/
int c,n,m,d,q;
int w[500005]; 
vector<pii> xx[500005];
int gg[502][502];
void solve() {
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++)cin>>w[i];
	for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)gg[i][j]=inf;
	for(int i=1; i<=n; i++)gg[i][i]=0;
	for(int i=1,k; i<=n; i++) {
		cin>>k;
		for(int j=1,a,t; j<=k; j++) {
			cin>>a>>t;
			for(auto p1:xx[a]) {
				int v1=p1.fr,w1=p1.sc;
				gg[i][v1]=gg[v1][i]=min(gg[v1][i],w1+t);
			}
			xx[a].push_back({i,t});
		}
	}
	for(int k=1; k<=n; k++)
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				gg[i][j]=min(gg[i][j],gg[i][k]+gg[k][j]);
	for(int i=1,u,v,ans=inf; i<=q; i++) {
		cin>>u>>v;
		ans=inf;
		for(auto p1:xx[u]) {
			int v1=p1.fr,w1=p1.sc;
			for(auto p2:xx[v]) {
				int v2=p2.fr,w2=p2.sc;
				ans=min(ans,w1+w2+gg[v1][v2]);
			}
		}
		cout<<ans+w[u]+w[v]<<"\n";
	}
}

signed main() {
	int T=1;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
//	cin>>T;
	while(T--)solve();
	return 0;
}
/*
多测要清空
注意 ll 和 double 精度
ds 要 build
不要饭堂qwq
*/

