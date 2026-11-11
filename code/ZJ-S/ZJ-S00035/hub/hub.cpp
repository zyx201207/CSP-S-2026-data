#include<bits/stdc++.h>
#define N 1000010
#define int long long
using namespace std;
int T,c,n,k,mi,x,y,i,tt,fl[N],dis[N],a[N];vector<int>f[N];
int dfs2(int fx,int gr){
	int ans=0,i,sx;
	if(fl[fx]==1&&fl[gr]==0)ans++;
	for(i=0;i<f[fx].size();i++){
		sx=f[fx][i];
		if(sx==gr)continue;
		ans+=dfs2(sx,fx);
	}
	return ans;
}
void dfs3(int fx,int gr){
	int i,sx;
	for(i=0;i<f[fx].size();i++){
		sx=f[fx][i];
		if(sx==gr)continue;
		dis[sx]=min(dis[sx],dis[fx]+1);
		dfs3(sx,fx);
	}
}
int js(){
	int i,ma=0;
	for(i=1;i<=n;i++)dis[i]=1e18;
	for(i=1;i<=tt;i++)
		dis[a[i]]=0,dfs3(a[i],0);
	for(i=1;i<=n;i++)ma=max(ma,dis[i]);
	return ma;
}
void dfs(int t,int cnt){
	if(n+1-t<k-tt)return;
	if(t==n+1){
		if(dfs2(1,0)<=2)mi=min(mi,js());
		return;
	}
	if(cnt<k)tt++,a[tt]=t,fl[t]=1,dfs(t+1,cnt+1),tt--,fl[t]=0;
	dfs(t+1,cnt);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;mi=1e18;
		for(i=1;i<n;i++)cin>>x>>y,f[x].push_back(y),f[y].push_back(x);
		dfs(1,0);
		cout<<mi<<"\n";
		for(i=1;i<=n;i++)f[i].clear();
	}
}
//by wild cat
/*
虽然教练不让，但还是想写一些关于CSP-S的看法，毕竟可能马上就退役了
这两年的密码似乎都有些小故事，去年是上善若水、人杰地灵，
今年是不给糖就捣蛋、10.31是否等于12.25，都与万圣节有关
这次我的预估得分是100+32+24+15=171，如果按照去年的分数线，
并且不爆，应该是能拿S1=
除了T1，基本上都拿了最好拿的分（潦草急就了）
特殊性质感觉都没什么用（也有可能是我不会用）
T3的大样例3竟然要1.349s，没事，相信CCF的评测机（相信着你了）
没想到昨天下午复习的tarjan缩点竟然没考
更想不到今年的2,4都是（或接近）图论
还好我没复习的KMP、马拉车也没考
之所以不复习这些，是因为我认为复习了也没用（计划妥当了）
听说明天要考社会，ZDJD？（心神不宁了）
哦对了
去年的电脑打不了中文
17.51插播
T2变量不看、只看数字是什么意思
其实我一直没看懂T2，题目里说“任意两个地铁站都可以通过若干条线路互相到达”，
但样例解释里又说“依次经过第1,2,5个地铁站”，反正我双向建边来跑dij过了样例
18.04插播
突然发现自己糖了，T4的dfs(t,cnt)中的cnt完全可以不需要，但不想改了
18.16插播
在回收站里看到了travel.cpp
*/