#include<bits/stdc++.h>
#define ll long long
#define up(_i,_l,_r) for(auto _i=(_l);_i<=(_r);_i++)
#define dn(_i,_r,_l) for(auto _i=(_r);_i>=(_l);_i--)
using namespace std;
const int N=1e6+5,M=2e5+5;
const int inf=0x3f3f3f3f,mod=1e9+7;
int n,m;
vector<int> G[N];
int f[N][25],d[N];
void dfs1(int x,int from){
	d[x]=d[from]+1;
	f[x][0]=from;
	up(i,1,20) f[x][i]=f[f[x][i-1]][i-1];
	for(auto to:G[x]){
		if(to==from) continue;
		dfs1(to,x);
	}
}
int LCA(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	dn(i,20,0){
		if(d[f[x][i]]>=d[y]) x=f[x][i];
	}
	if(x==y) return x;
	dn(i,20,0){
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	}
	return f[x][0];
}
int dis(int u,int v){
	return d[u]+d[v]-2*d[LCA(u,v)];
}
int ans=inf;
bool c[N];
bool vis[N];
void dfs2(int x){
	for(auto to:G[x]){
		vis[x]=1;
		if(vis[to]||!c[to]) continue;
		dfs2(to);
	}
}
int check(){
	up(i,1,n) vis[i]=0;
	int cnt=0;
	up(i,1,n){
		if(c[i]&&!vis[i]){
			cnt++;
			dfs2(i);
		}
	}
	if(cnt>2) return -1;
	int ret=0;
	up(i,1,n){
		if(c[i]) continue;
		int d=inf;
		up(j,1,n){
			if(!c[j]) continue;
			d=min(d,dis(i,j));
		}
		ret=max(ret,d);
	}
	return ret;
}
void gen(int x,int y){
	if(y>m) return;
	if(x==n+1){
		if(y!=m) return;
		int ret=check();
		if(~ret) ans=min(ans,ret);
		return;
	}
	if(y<m){
		c[x]=1;
		gen(x+1,y+1);
	}
	c[x]=0;
	gen(x+1,y);
}


void Main(){
	scanf("%d%d",&n,&m);
	up(i,1,n) G[i].clear();
	up(i,1,n-1){
		int u,v;scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	d[0]=-1;
	dfs1(1,0);
	ans=inf;
	gen(1,0);
	printf("%d\n",ans);
}
/*
题意：在树上标记k个，至多两个连通块的点，使得未被标记的点到最近的标记的点
的距离的最大值最小 
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
signed main(){
	if(1){
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
	}
	int c,Test=1;
	scanf("%d%d",&c,&Test);
	while(Test--){
		Main();
	}
	return 0;
}
/*
迷惑行为大赏会有我吗
关注洛谷uid967841谢谢喵
大胆无畏 维新革命
光明磊落 反战国家
骑着日之丸印的二轮车
恶灵退散ICBM
骑行穿过环状线 东奔西走 不算什么
少年少女 战国无双 跟从着浮世浪
千本樱 夜空中飞散
你的声音 也传达不到啊
此处设宴 钢铁牢笼中
从那断头台上跳下来吧
三千世界 黄泉之暗
青蓝之空 遥向彼方
就以那光线枪击穿吧
*/

