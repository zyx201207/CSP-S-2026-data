#include<cstring>
#include<iostream>
#include<queue>
#include<vector>
const int N=500005;
#define ll long long
#define pli pair<ll,int>
using namespace std;

int c,n,m,d,q,k;
ll ans;
ll Time[N];
ll dis[N];
bool vis[N];
vector<pli>shd[N];
ll f[1000][1000];
void Floyd(){
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			for(int k=1;k<=n;++k){
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);	
			}
		}
	}
}
inline void solve(){
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>Time[i];	
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1;j<=k;++j){
			int arv;ll Time1;
			cin>>arv;
			cin>>Time1;
			for(pli node:shd[arv]){//存的是这个 地铁站 在哪些路线里面
				//我们要维护的值是从 当前线路的 站厅 转至 其他线路的 站厅 的时间
//				edge[node.second].push_back({node.first+Time1,i});
//				edge[i].push_back({node.first+Time1,node.second});
				f[i][node.second]=min(f[i][node.second],node.first+Time1);
				f[node.second][i]=min(f[node.second][i],node.first+Time1);
			}
			shd[arv].push_back({Time1,i});
		}
	}
	Floyd();
	while(q--){
		ans=2e18;
		int u,v;
		cin>>u>>v;
		for(pli node:shd[u]){
//			Dij(node.second);
			for(pli to:shd[v]){
//				cout<<ans<<" ";
//				if(node.second==to.second)ans=min(ans,node.first+to.first);
				ans=min(ans,f[node.second][to.second]+node.first+to.first);
			}
		}
		cout<<ans+Time[u]+Time[v]<<"\n";
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;	
}
/*
TLE 1吨
但是 fc 找不出差异
也就是说优化一下成正解了
然而第二个样例没对(fake)
但是大样例是对的
Linux can compile it!

难道要开始写游记了吗？
不知为何，时间过去的很快
我也从高一刚开始的菜鸟，转为有一战之力的蒟蒻
然而 T1 切， T2 骗，不知道能否拿到一等奖
考前挺自大的，也没有想到三道图论直接砸过来
也是只能写一个暴力了
其实我是很害怕爆炸的
这样我停课就成为了一个小丑
室友也不时的笑话我
笑我听信了传销
因为这个，她也离开了
可是我还不想离开……
算了，继续骗分去了

我突然想到
好像 Floyd 硬处理后可以 O(1) 查询
注意到 n<=500
n^3可以接受
然后就可以优化
可以先对边排序
找到
*/
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
32
17


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
//vector<pli>edge[N];
//inline void Dij(int start){
//	priority_queue<pli,vector<pli>,greater<pli> >qq;
//	memset(dis,0x3f,sizeof(dis));
//	memset(vis,0,sizeof(vis));
//	dis[start]=0;
//	qq.push({dis[start],start});
//	while(!qq.empty()){
//		pli node=qq.top();
//		qq.pop();
//		int now=node.second;
//		if(vis[now])continue;
//		vis[now]=true;
//		for(pli To:edge[now]){
//			ll val=To.first;int to=To.second;
//			if(dis[now]+val<dis[to]){
//				dis[to]=dis[now]+val;
//				qq.push({dis[to],to});
//			}
//		}
//	}
//	return ;
//}