/*
KSKBL
ZDJD
WKZKBL
MP
WZMP
NZZYSWZSBLL
叠甲:原神NB 鸣潮NB 1999NB 终末地NB 绝区零NB 蔚蓝档案NB 
神总是孤独的
神花了40分钟写完了T1,T2,T3暴力
可惜不能给整个七中高新考场播放司凤版雨爱
好了,我要耍起了




















1分钟到了,狱门疆,开!
进行一些论战
T1:二分+贪心,纯裸的红题
T2:弗洛伊德+枚举优化,考虑一下二分图的性质就没了,偏简单的绿题
T3:大概是线性DP,嗯,兑,偏难的蓝题
T4:孩子们,我没学过,大概就是一些省选的树上算法+树剖优化吧
提前祝CCF新年快乐,这次出的题挺简单的
*/
#include<bits/stdc++.h>
#define maxn 107
using namespace std;
int c,t,n,m,x,y;
int dis[maxn][maxn];
vector<int> p[maxn];
queue<int> q;
bool mk[maxn];
void dfs(int sd,int u){
	if(mk[u]) return;
	mk[u]=1;
	for(auto v:p[u]){
		if(sd&(1<<(v-1))) 
		dfs(sd,v);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e6;
			}
			dis[i][i]=0;
			p[i].clear();
		}
		for(int i=1;i<n;i++){
			cin>>x>>y;
			p[x].push_back(y);
			p[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			q.push(i);
			int step=0;
			while(!q.empty()){
				step++;
				int l=q.size();
				while(l--){
					int u=q.front();
					q.pop();
					for(auto v:p[u]){
						if(step<dis[i][v]){
							dis[i][v]=step;
							q.push(v);
						}
					}
				}
			}
		}
		int ans=114514;
		for(int i=0;i<(1<<n);i++){
			int kkc=0;
			for(int j=0;j<n;j++) 
			if(i&(1<<j)) ++kkc;
			if(kkc!=m) continue;
			for(int j=1;j<=n;j++) mk[j]=0;
			int cft=0;
			for(int j=1;j<=n;j++){
				if(!mk[j]&&(i&(1<<(j-1)))) dfs(i,j),++cft;
			}
			if(cft>2) continue;
			int Min=0;
			for(int j=1;j<=n;j++){
				int sumr=114514;
				for(int k=1;k<=n;k++){
					if(i&(1<<(k-1)))
					sumr=min(sumr,dis[j][k]);
				}
				Min=max(Min,sumr);
			}
			ans=min(Min,ans);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
考后感
扎扎帅无敌
关注塔菲喵,关注塔菲谢谢喵
窗外的天气
就像是  你 多变的表情
下雨了 雨陪我哭泣
看不清 我也不想看清
离开你 我安静的抽离
不忍揭晓的剧情
我的泪留在心里
学会放弃
听雨的声音
一滴滴清晰
你的呼吸像雨滴渗入我的爱里
*/