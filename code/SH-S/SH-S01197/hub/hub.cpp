#include<bits/stdc++.h>
//#define int long long
using namespace std;

const int Max_N = 1000000+10;
int c, T;
int n, k, disb, disr;
int dis[Max_N];
vector<int>V[Max_N];

void dfs(int u, int fa){
	for(int v:V[u]){
		if(v!=fa){
			dis[v] = dis[u] + 1;
			if(dis[v] > disb)disb=dis[v], disr = v;
			dfs(v, u);
		}
	}
}

void solve(){
	cin >> n >> k;
	
	for(int i = 1; i <= n - 1; i++){
		int u, v;
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}
	
	disb=0, disr = 0;
	dfs(1, 0);
	int o = disr;disb = 0, dis[o]=0;
	dfs(o, 0);
	
	if(k == 1){
		for(int i=1;i<=n;i++)V[i].clear();
		cout<<dis[disr]<<" "<< ((dis[disr]+1)>>1) << "\n";	
		return;
	}
	if(k == 2){
		for(int i=1;i<=n;i++)V[i].clear();
		cout<<dis[disr]<<" "<< ((dis[disr]-1)>>2) << "\n";
		return;
	}
	
	for(int i=1;i<=n;i++)V[i].clear();
}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	cin>>c>>T;
//	T=1;
	
	while(T--){
		solve();
	}
} 
/*关于T4

他已经死了。
我常常追忆过去
我该在那里停留
我问我自己 
dp[i][j]表示从i之前任意点到达点i已经有j种最短走法的路线有几条
dp[i][0]=dp[lx[i]][0]
dp[i][1]=
O(n)不会O(n2)骗个40分跑路吧。 
感谢地铁。这应该是我这辈子见过最简单的TG T2。
migrate可以竞选最神秘T3了。 
\我一次也没觉得做T3开心过/
直接在T4丢废话。T1 T2应该也不会改了。T4应该也出不来了。
喵喵喵?
暴力的O(nq)可过的
你知道我们在嘟嘟什么。
这道题 *800吧!(并非)
去年这个时候大概是已经鱼鱼了(
注意到海鸟不会坐地铁迁徙。
但是研发基地可以研发水晶。
我觉得T4有黑。
T1水T2板。
T3？T4？
对这种神秘序列上跳一跳问题真没招了。 
这怎么O(n)
i-j-k-l唯一当且仅当
i-j-k && j-k-l唯一
i-j-k唯一当且仅当 
i-j是i的最远 j-k是k的最远
i-k有且仅有2当且仅当
i最远为k+1 j最远为k
最远考虑用二分处理。
不明白啊!好魔怔啊! 
T4就是尽量四等分
并不明白。
T2 floyd板子题。
学过floyd的小朋友们都说好。
T1前缀和小练习
其实这是中国式吸asp而我掌握了憋尿憋到膀胱爆炸  
还是乌蒙dx好玩。 
考完CSP直接去出勤是否有道理。
注意到去年没有Ip太过困难所以我们加入了过于板子的T2和神秘的T3T4
我不管。要么就是T3是黑要么就是个人差。
骗你的其实T3是斜二倍增WJ太伟大了 
我将在考场上进食，然后在肠道被淀粉水解酶分解成小分子葡萄糖成为血糖，由血浆进入组织液，进入细胞，在细胞质基质发生糖酵解，生成丙酮酸ATP和NADH，并且进入线粒体
发生丙酮酸脱羧，脱去一份CO2，进入三羧酸循环产生NADH ATP与CO2
NADH进入电子传递链，H+ 
*/ 
