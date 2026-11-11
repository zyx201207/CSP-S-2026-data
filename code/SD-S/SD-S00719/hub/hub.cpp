#include<bits/stdc++.h>
#define INF INT_MAX/2
using namespace std;
const int N=1e6+5;
int idx,h[N],e[N<<1],ne[N<<1];
void add(int x,int y){
	ne[++idx]=h[x];
	h[x]=idx;
	e[idx]=y;
}
struct node{
	int x,fa;
};
int n,k,u,v,ans=INF,dis[N],vis[N];
int bfs(int x,int k,bool flag){
	if(k==1) return 0;
	fill(dis+1,dis+n+1,INF);
	if(flag) fill(vis+1,vis+n+1,false);
	queue<node> q;
	q.push({x,0});
	dis[x]=0;
	int total=1;
	while(!q.empty()){
		int x=q.front().x,fa=q.front().fa;
		q.pop();
		if(total==k) break;
		if(flag) vis[x]=true;
		for(int i=h[x];~i;i=ne[i]){
			int y=e[i];
			if(y==fa) continue;
			if(vis[x]) continue;
			q.push({y,x});
			dis[y]=dis[x]+1;
		}
		total++;
	}
	return *max_element(dis+1,dis+n+1);
}
void f(){
	idx=0;
	scanf("%d%d",&n,&k);
	fill(h+1,h+n+1,-1);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++) ans=min(bfs(i,k,true),ans);
	for(int i=1;i<=n;i++){
		for(int t=k-1;t>=1;t--){
			int tmp=bfs(i,t,true);
			for(int j=1;j<=n;j++){
				if(!vis[j]){
					ans=min(tmp+bfs(j,k-t,false),ans);
				}
			}
		}
	}
	printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int _,__;
	scanf("%d%d",&__,&_);
	while(_--) f();
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
