#include <bits/stdc++.h>
#define int long long
using namespace std;
int dis[500010],ans[5100][5100],n,m,c,qwe,d,w[5100],cnt=0;
struct gcc{
	int v,t;
};
int vis[500010];
vector<gcc> q[500010];
void disj(int s){
	for(int i=1;i<=cnt;i++) dis[i]=1e8,vis[i]=0;
	dis[s]=0;
	priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> > q1;
	q1.push({0,s});
	while(!q1.empty()){
		auto u=q1.top();
		q1.pop();
		if(vis[u.second]==1) continue;
		vis[u.second]=1;
		for(auto v:q[u.second]){
			if(dis[v.v]>dis[u.second]+v.t){
//				cout<<dis[u.first]+v.t<<endl;
				dis[v.v]=dis[u.second]+v.t;
				q1.push({dis[v.v],v.v});
			}
		}
	}
	return ;
}
int read(){
	int res=0,flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>qwe;
	for(int i=1;i<=n;i++){
		w[i]=read();
	}
	cnt=n+1;
	for(int i=1;i<=m;i++){
		int k=0,now=0;
		k=read();
		for(int j=1;j<=k;j++){
			int u,t;
			u=read(),t=read();
			q[u].push_back({cnt,t});
			q[cnt].push_back({u,t});
			if(j>1) {
				q[cnt].push_back({now,0});
				q[now].push_back({cnt,0});
			}
			now=cnt;
			cnt++;
		}
	}
	for(int i=1;i<=n;i++){
		disj(i);
		for(int j=1;j<=n;j++){
			ans[i][j]=dis[j];
		}
	}
	for(int i=1;i<=qwe;i++){
		int u,v;
		u=read(),v=read();
		cout<<w[u]+w[v]+ans[u][v]<<endl;
	}
	return 0;
}
/*
还有42min就结束了
我真的好累啊 
这个T1做了快两个小时
这个T2我明明数组已经开到最大了,开了long long,板子也看了好几遍了,为什么还是不对，后面几个大样例还是RE
我真的好难受啊
S组拿不到1=我大概率是要退役了 
但不想就这样结束我的信奥生涯
CCF我求你多给我点分吧…………
*/ 
/*
还有30min
T3 T4暴力完全不会写,也没有时间写了,好难啊,为什么会这么难 
算了下在我不挂分的情况下,我最多只有144分(还不可能不挂分),完全拿不了1= ,好难受啊 
*/ 
/*
还有10min
已经完全放弃了
感觉好困啊
马上就要结束了
*/ 
