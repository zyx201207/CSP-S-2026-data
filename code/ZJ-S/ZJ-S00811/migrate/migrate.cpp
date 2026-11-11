#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,d,n,T,X[500007],D[500007],dis[500007],cnt[500007],vis[500007];
vector<int>road[500007];
struct Point{
	int dis,pos;
	friend bool operator < (Point A,Point B){
		return A.dis>B.dis;
	}
};
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	if(c==11||c==12){
		while(T--){
			int ans=0;
			scanf("%lld%lld",&n,&d);
			for(int i=1;i<=n;i++) scanf("%lld",&X[i]);
			int k=d/(X[2]-X[1]);
			for(int i=k+1;i<=k*2-1;i++){
				ans+=n-i;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	while(T--){
		int ans=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&X[i]);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(X[j]<=X[i]+d) road[i].push_back(j);
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++) dis[j]=1e18,vis[j]=0;
			priority_queue<Point>Q;
			Q.push({0,i});
			dis[i]=0;
			while(!Q.empty()){
				Point tmp=Q.top();
				Q.pop();
				int now=tmp.pos;
				for(int j=0;j<road[now].size();j++){
					if(dis[road[now][j]]>dis[now]+1){
						dis[road[now][j]]=dis[now]+1;
						vis[road[now][j]]=1;
						Q.push({dis[road[now][j]],road[now][j]});
					}
					else if(dis[road[now][j]]==dis[now]+1){
						vis[road[now][j]]++;
						if(vis[road[now][j]]==2) Q.push({dis[road[now][j]],road[now][j]});
					}
				}
			}
			for(int j=i+1;j<=n;j++){
				if(vis[j]==2) ans++;
			}
		}
		for(int i=1;i<n;i++) road[i].clear();
		printf("%lld\n",ans);
	}
	return 0;
}
/*
T2时
我忘却了Floyd 
只可用Dis(并不会拼)去跑多源最短路。
本地跑了1.4s
不知前路如何 
人生很长
一天就有86400s
CCF却卡那几s
掐住了我们命运的咽喉。 

哈哈哈
我尽力了
比去年要好
过去的时间不能重来
OI的路终将一去不复返
一年的成长
我从T1写到了T3
可能T3只有10分
可那也不重要
高中的旅途才刚刚开始 
踏碎过去的路 
迎来未来的曙光 
可是回忆总是在不经意间漫入脑海
我总想从训练的点点滴滴中拼凑出过去的全貌
以为可以扭转时间 
我们最留恋的永远是那些转瞬即逝
我又一次在这片OI的赛场上面对难题迷茫
四个小时转瞬即逝
我马上就要离开这片土地
离开诗与远方 

若明年还可以来到此处
那么
再来一次新的开端又何妨 
愿所有的人
都有属于自己的华丽的人生
人生不是选择题
而是开放题 
*/
