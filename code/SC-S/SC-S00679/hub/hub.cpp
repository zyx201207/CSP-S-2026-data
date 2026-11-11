#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e6+5;
vector<int> v[N]; 
bool tag[N];int cnt,n,k;
int st[N],dep[N],f[N][25],top;

inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*f;
}

inline void solve(int x,int fa){//求出 tag=1 的有几个连通块
	cnt+=((tag[x]==1) && (tag[fa]==0));
	for(int y:v[x])
		if(y!=fa) solve(y,x);
}

inline bool check(int state){//state 状态是不是 <=2 个连通块 
	for(int i=1;i<=n;i++) tag[i]=((state&(1<<(i-1)))?1:0);
	cnt=0;solve(1,0);
	return (cnt<=2);
}

inline void dfs(int x,int fa){
	dep[x]=dep[fa]+1;f[x][0]=fa;
	for(int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
	for(int y:v[x])
		if(y!=fa) dfs(y,x);
}

inline int LCA(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

inline int dis(int x,int y){return dep[x]+dep[y]-2*dep[LCA(x,y)];}

signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs(1,0);
		if(c<=3){
			int ans=2e9;
			for(int i=0;i<(1<<n);i++){
				top=0;
				for(int j=1;j<=n;j++)
					if(i&(1<<(j-1))) st[++top]=j;
				if(top!=k) continue;
				if(!check(i)) continue;
				int maxn=0;
				for(int j=1;j<=n;j++){
					int minn=2e9;
					for(int k=1;k<=top;k++) minn=min(minn,dis(j,st[k]));
					maxn=max(maxn,minn);
				}
				ans=min(ans,maxn);
			}		
			cout<<ans<<"\n";
		} 
		for(int i=1;i<=n;i++) v[i].clear(); 
	}	
	return 0;
}
/*
It wiil be alright.

什么最小的最大的最小，吓哭了
二分最小通勤距离 d
然后问题就转化为了：
	给你一颗树，选出 k 个点，至多为两块
	要求每个节点距离最近的一个选出点的距离 <= d

树上 dp，记 dp[x][k][i][0/1/2][0/1] 代表：
	x 的子树选了 k 个
	当前需要上面补 i 的距离 
	形成了 0/1/2 个连通块 
	是否选了根节点

然后就有奇妙 O(n^4 log n) 的做法，自带 8 倍常数

欸怎么和暴力同分啊，生气了 
算了就写暴力吧，Keep calm and carry on.



现在还有 40min，但是学生已经完全没有状态了
注意到《老男孩》在我班里也算作是班歌，所以唱一唱 

那是我日夜思念 深深爱着的人啊
到底我该如何表达 她会接受我吗 
也许永远都不会跟她说出那句话 注定我要浪迹天涯 怎么能有牵挂

梦想总是遥不可及 是不是应该放弃
花开花落又是一季 春天啊你在哪里

青春如同奔流的江河 一去不回来不及道别 
只剩下麻木的我 没有了 当年的 热血
看那满天飘零的花朵 在最美丽的时刻凋谢 有谁会记得这世界她来过 

转眼过去多年时间多少离合悲欢
曾经志在四方少年 羡慕南飞的燕
各自奔前程的声音 匆匆渐行渐远
未来在哪里平凡哪 啊谁给我答案

那时陪伴我的人呐 你们如今在何方
我曾经爱过的人呐 现在是什么模样 

青春如同奔流的江河 一去不回来不及道别 
只剩下麻木的我 没有了 当年的 热血
看那满天飘零的花朵 在最美丽的时刻凋谢 有谁会记得这世界它曾经 来过

当初的愿望实现了吗 事到如今只好祭奠吗
任岁月风干理想 再也找不回真的我
抬头仰望着满天星河 那时候陪伴我的那颗 这里的故事你是否还记得

如果有明天 祝福你 亲爱的 




然后我听说很多人会在后面写一些与游戏相关的，所以我来写一点
原 uid 250844886，绝 uid 23568391，都是 60 老登，原淡坑了
然后 Kards T7_Daniel#4880，欢迎找我击剑！

洛谷 uid 903392，也欢迎私信打扰
哦对了对了，有一部分人应该已经面到我了，我是七中高新考点的那只神秘蟑螂
	做迷惑行为大赏的老师可以找我要一张图

如果不出所料的话，CSP-S 又可以喜提机房倒一了。。。。。。
预估的是 100+100+40+15
吉祥物的脑容量在 T1 T2 做 2h 之后就已经没有了，T3 T4 没有写出任何非平凡的东西 
*/