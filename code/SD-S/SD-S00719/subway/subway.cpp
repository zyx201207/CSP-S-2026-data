#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505,M=5e5+5;
int n,m,q,x,y,W[N];
int idx,h[M],e[M<<5],w[M<<5],ne[M<<5];
void add(int x,int y,int z){
	ne[++idx]=h[x];
	h[x]=idx;
	e[idx]=y;
	w[idx]=z;
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
int dis[M];
bool vis[M];
int dijstra(int st,int en){
	memset(dis,0x3f,sizeof(dis));
	memset(vis,false,sizeof(vis));
	dis[st]=0;
	pq.push({0,st});
	while(!pq.empty()){
		int x=pq.top().second;
		pq.pop();
		if(vis[x]) continue;
		vis[x]=true;
		for(int i=h[x];~i;i=ne[i]){
			int y=e[i];
			if(vis[y]) continue;
			if(dis[y]>dis[x]+w[i]){
				dis[y]=dis[x]+w[i];
				pq.push({dis[y],y});
			}
		}
	}
	return dis[en];
}
int k,t[M],a[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(h,-1,sizeof(h));
	int c,d;
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&W[i]);
	while(n--){
		scanf("%lld",&k);
		for(int i=1;i<=k;i++){
			scanf("%lld%lld",&a[i],&t[i]);
			for(int j=1;j<i;j++){
				add(a[i],a[j],t[i]+t[j]);
				add(a[j],a[i],t[i]+t[j]);
			}
		}
	}
	while(q--){
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",W[x]+W[y]+dijstra(x,y));
	}
	return 0;
}
/*
上午J组已经爆炸，236pts顶多 -- SD-J00972

那，我还犯不犯呢?
Yes!

Minecraft:NeoForge Loading...
Create!
Let's Create!
(机动老玩家^v^)

Paint craft Launch
(好像没拼错^v^)
PCL的下载功能(T_T)...
默哀10分钟。
龙猫我支持你!

冈易你的浮木在吗?
你举报个鸡毛! 

Mojang Studio给了你Minecraft代理权是一个错误!
Mojang不了解你!

冈易你怎么不举报官方启动器?
仗着你备了案就嚣张?
(个人猜测) 

让我们祈祷Mojang将于Minecraft 27.1 发布时将它的代理权收回，亲自下场。
打压冈易!

冈易浮木被烧了。
做用户们的怒火。
它的代理权终将变成棍木!

我的89大洋不是白花的!

试题密码:
Oct31==Dec25?

估分:
T1:AC
T2:AC?
T3:0pts
T4:0pts
Total:100pts+

山东二等稳拿!
弥补上午J组爆炸!
											临沂润盈工艺品有限公司 宣(^v^)
															2026年10月31日
																1933577
*/
