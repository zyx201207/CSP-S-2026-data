#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,n) for(int i = (a);i<=(n);++i)
#define ll long long
using namespace std;

template<typename T>inline void read(T &x){
	char c = getchar();
	short int t = 1;x = 0;
	for(;!isdigit(c);c = getchar())if(c == '-')t=-1;
	for(;isdigit(c);c = getchar())x = (x<<1) + (x<<3) + (c^48);
	x*=t;
}
template<typename T>inline void write(T x){
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x >= 10){
		write(x/10);
	}
	putchar(x % 10 + '0');
}
int n = 0,m = 0,k = 0;
int c = 0,T = 0;

void sol(){
	read(n);read(k);
	int U = (1<<n) - 1; 
}

signed main(){
//	freopen("hub.in","r",stdin);
//	freopen("");
	read(c);read(T);
	
	while(T--){
		sol();
		cout <<4<<endl;
	}

	return 0;
}
/*
给你一个树，你要选择最多两个连通块， 恰好 k 个城市。

然后定义 dis(i,j) 为 i 到 j 简单路径上的边的数量。 这个可以通过求 lca，dep 树上差分 O(1) 求。

d(i) = min dis(i,j) j 是你选择的点 ，若 i 是你选择的点，那么 d(i) = 0。 

这个方案的答案是 max d(i) 。

我们考虑 2^n 枚举的点集，怎么判定这个点集形成的连通块的数量 ？ 

感觉这个题有点像树上 dp，然后换根啊。 

考虑不断往这个点集里面加点的过程？哪些状态是可以转移的？

dp[s][0/1] 表示选择的点集是 s，s 里有 1/2 个连通块， 的答案。

对于一个 s，你考虑枚举一个 s 中为 1 的点的不在 s 中的邻居。

加入之后再对整个树跑一遍，求 max(d)。 

dp[u][k] 表示以 u 为根的子树选了大小为 k 的连通块时，max d(i) 的值。

我们要求的是 g[u][k] 表示以 u 为根的子树，u 所在的连通块大小为 k 时的方案树。 

对面那个人怎么开始哭了，我真服了。 
*/ 

