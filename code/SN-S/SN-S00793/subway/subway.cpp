#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q;
struct Kokona{
	int u,v;
}; 
vector<Kokona> g[1500721];
vector<int> g1[1500721];
queue<Kokona> qq;
int dis[1500721];
int biao[1007][1007];
int the12to19[500721];
/*
我的悲伤是水做的-洛天依
chillchili 
嫌弃下雨的天气
讨厌垮掉的发型
新买的鞋子沾上泥
金鱼在袜子里嬉戏
摘掉泪腺行不行
眼妆花得很彻底
最近很不顺利
讨厌水星又逆行
其实也
不爱比基尼
其实也
并不喜欢吃鱼
我的悲伤
是水做的是水做的
一个巨浪
心里凉得透透的
我的太阳
在哪里呢在哪里呢
晒干这一片蓝色 
*/ 
int solve(int s,int f){
	while(!qq.empty()){
		qq.pop();
	}
	for(int i=1;i<=2*m+n;i++){
		dis[i]=1e18;
	}
	dis[s]=0;
	qq.push({s,0});
	while(!qq.empty()){
		Kokona mom=qq.front();
		qq.pop();
		for(Kokona mother:g[mom.u]){
			if(dis[mother.u]>mother.v+dis[mom.u]){
				dis[mother.u]=mother.v+dis[mom.u];
				qq.push({mother.u,dis[mother.u]});
			}
		}
	}
	if(f==-1){
		for(int i=1;i<=n;i++){
			biao[i][s]=dis[i];
		} 
	}
	return dis[f];
}
int solve2(int s,int f){
	while(!qq.empty()){
		qq.pop();
	}
	for(int i=1;i<=2*m+n;i++){
		dis[i]=1e18;
	}
	dis[s]=0;
	qq.push({s,0});
	while(!qq.empty()){
		Kokona mom=qq.front();
		qq.pop();
		for(int mother:g1[mom.u]){
			if(dis[mother]>1+dis[mom.u]){
				dis[mother]=1+dis[mom.u];
				qq.push({mother,dis[mother]});
			}
		}
	}
	
	return dis[f];
}
signed main(){
	// 虚拟节点耍起嘛 
	//对于每一条地铁 建立一个虚拟节点嘛 
	//1-m 地面 m+1 - 2*m 地铁站内 2*m+1 - 2*m+n 虚拟节点 
	//20tps
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	//性质B的来了
	if(12<=c&&c<=19){
		//bfs
		int diss=0;
		for(int i=1;i<=m;i++){
			cin>>the12to19[i];
		}
		for(int i=1;i<=n;i++){
			int b;
			cin>>b;
			for(int j=1;j<=b;j++){
				
				int uu;
				cin>>uu>>diss;
				g1[2*m+i].push_back(uu);
				g1[uu].push_back(2*m+i);
			}
		}
		for(int i=1;i<=q;i++){
			int st,fl;
			cin>>st>>fl;
			int sr=solve2(st,fl)*diss+the12to19[st]+the12to19[fl];
			cout<<sr<<endl; 
		}
		return 0;
	} 
	for(int i=1;i<=m;i++){
		int a;
		cin>>a;
		g[i].push_back({i+m,a});
		g[i+m].push_back({i,a});
	} 
	
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		for(int j=1;j<=b;j++){
			
			int uu,vv;
			cin>>uu>>vv;
			g[2*m+i].push_back({uu+m,vv});
			g[uu+m].push_back({2*m+i,vv});
		}
	}
	//你说的对 但是卡拉比丘好玩
	
	if(c>8){
		for(int i=1;i<=n;i++){
			solve(i,-1);
		} 
		for(int i=1;i<=q;i++){
			int st,fl;
			cin>>st>>fl;
			cout<<biao[st][fl]<<endl;
		}
		
	} 
	else{
		
		//稳定能过的
		for(int i=1;i<=q;i++){
			int st,fl;
			cin>>st>>fl;
			cout<<solve(st,fl)<<endl;
		}
		return 0;
	} 
} 
