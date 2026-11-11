#include<iostream>
#include<vector>
#include<queue>
//#include<unordered_set>
#define pii pair<int,int>
#define x first
#define y second
#define ll long long
using namespace std;

const int N=5e3+5;

int c,T;
int n;
ll d;
ll x[N];
vector<int>e[N]/*往右*/,g[N]/*往左*/;
bool flg[N]/*flg[i] -> 当前轮中，所有到达 i 的点的 f 是否都为 1*/,vis[N];
int dis[N],cnt[N];
int que[N];int front,tail;
//unordered_set<int>st;

//ll sum;

inline void clear(){
	for(int i=1;i<=n;++i){
		e[i].clear(),g[i].clear();
		e[i].reserve(n+2),g[i].reserve(n+2);
	}
//	st.clear();
	return ;
}

inline void bfs(int ed,int &res){
	for(int i=1;i<=n;++i)dis[i]=1e9,vis[i]=0,cnt[i]=0;
	dis[ed]=0;
	front=1,tail=0;
	que[++tail]=ed,cnt[ed]=1;
	while(front<=tail){
		int u=que[front++];
		vis[u]=0;
		for(auto v:g[u]){
//			++sum;
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1,cnt[v]=cnt[u];
				if(!vis[v]){
//					if(st.find(v)==st.end())continue ;
					vis[v]=1,que[++tail]=v;
				}
			}else if(dis[v]==dis[u]+1){
				++cnt[v];
//				if(cnt[v]>2)st.erase(v);
			}
		}
	}
	for(int i=1;i<ed;++i){
		if(cnt[i]==2)++res;
	}
	return ;
}

inline void work(){
	cin>>n>>d;clear();
	for(int i=1;i<=n;++i)cin>>x[i];//,st.insert(i);
	for(int st=1;st<=n;++st){
		for(int ed=st+1;ed<=n;++ed){
			if(x[ed]-x[st]>d)continue ;
			e[st].push_back(ed),g[ed].push_back(st);
//			++sum;
		}
	}
//	cerr<<"edg sum:"<<sum<<"\n";
//	sum=0;
	int res=0;
	for(int ed=2;ed<=n;++ed){
//		cerr<<"ed:"<<ed<<",ok1\n";
		bfs(ed,res);
//		cerr<<"ok2\n";
	}
//	cerr<<"bfs sum:"<<sum<<"\n";
	return cout<<res<<"\n",void();
}

signed main(){
//	freopen("migrate3.in","r",stdin),freopen("out.txt","w",stdout);
	freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
//	freopen("in.txt","r",stdin);
//	ios::sync_with_stdio(false);cin.tie(0);
	cin>>c>>T;
	while(T--)work();
	return 0;
}

/*

肯定是单向飞的，不妨令 st<ed
先枚举下点对，然后判这个东西
两条最短路长什么样子
全程恰有一步可以选两个后继点
有什么高效的手段吗，暴力跳应该是 O(n^3)，有 24pts
如果是固定终点，统计起点呢，有没有单调性
从 ed 往左 bfs，每个状态是一个二元组 (u,flg)，表示走到了 u，是否已经经过了两种选择
如果说一个状态的 flg 为 1，那对应的点要记一下，每次搜到都是 flg=1，才是合法的起点
然后如果对于一个 flg 为 1 的点，如果下一步可达的点不止一个，那么不再往下走了
这样好像就是 O(n^2) 的，有 40pts
写下看？
不对，好像是梦话
人类的做法是不是该是先 bfs 一遍得到到左边所有点的最短路
然后开始搜
但是这样的复杂的还是平方吗
哦等下，最短路过程中是不是可以记录最短路条数
那就是 O(n^2) 的了 \o/\o/\o/
答案偏小？？哦写错了
但是怎么没有 5e3 的大样例
吓哭了怎么跑了 50s，小卡一下来到 17s，怎么这么慢啊
越往后跑开销越大，有没有什么可复用的东西
一个点如果在靠前的 ed 处的最短路条数已经超过 2，那一定不会再次产生贡献
不产生贡献的点，再往下搜也一定不产生贡献。这是一个剪枝
开个 unordered_set 维护下点集是不是就可以了
但是似乎一来没有变快，二来也 WA 了
不是，bfs 里面才 1.2e7 轮啊，vector 也 reserve 过了啊，怎么会这么慢
饿啊，少爷机助我
来看下别的分
？？bfs 里实际循环了 2e10 轮，也就是这个东西是 O(n^3) 的？？还真是
不会优化了啊，换道题先
性质 B 有什么用吗
是不是只相当于保证了有一个点不产生贡献

*/
