#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+5;
int g[600][600];//各线路之间的边权 
int c,n,m,d,qq;
int w[N];
pair<int,int> t[N][50]; //线路 + 耗时
int rootans[600][600];
void init(){
	for(int i=1;i<=m;i++){
		for(int j = 1;j<=t[i][0].first;j++){
			for(int k = 1;k<j;k++){
				g[t[i][j].first][t[i][k].first]\
				=min(\
				g[t[i][j].first][t[i][k].first],\
				t[i][j].second + t[i][k].second);

				g[t[i][k].first][t[i][j].first]\
				=g[t[i][j].first][t[i][k].first];
			}
		}
	}
	return;
}
vector<pair<int,int> > gg[600];
int vis[600],val[600];
priority_queue<pair<int,int> >q; //定义优先队列
int solve(int s,int e){
	int add = w[s] + w[e];
	int ans = LONG_LONG_MAX;
	for(int i=1;i<=t[s][0].first;i++){ //枚举起点
		for(int j=1;j<=n;j++)
			vis[j] = 0,val[j] = LONG_LONG_MAX; // 初始化
		int ss = t[s][i].first; //设置一下起点
		if(rootans[ss][0] == 1){
			for(int j=1;j<=t[e][0].first;j++)
				ans = min(ans,add + t[s][i].second + t[e][j].second + rootans[ss][t[e][j].first]);
			continue;
		}
		rootans[ss][0] = 1;
		val[ss] = 0;
		q.push({0,ss}); //把起点塞入优先队列 
		while(!q.empty()){
			auto node = q.top();q.pop(); //取出堆顶的点
			if(vis[node.second]) continue;//排掉已经松弛的点
			vis[node.second] = 1;//标记该点已经松弛
			for(auto edge:gg[node.second]){//遍历相邻的点
				int ww = val[node.second] + edge.second;
				if(val[edge.first] <= ww) continue;
				val[edge.first] = ww;
				q.push({val[edge.first],edge.first});
			}
		}
		for(int i=1;i<=n;i++){
			rootans[ss][i] = val[i];
		} 
		for(int j=1;j<=t[e][0].first;j++){
			ans = min(ans,add + t[s][i].second + t[e][j].second + val[t[e][j].first]);
		}
	}
	return ans;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	int k;
	for(int i=1;i<=n;i++){
		for(int j =1;j<=n;j++)
			g[i][j] = LONG_LONG_MAX;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a,tt;
			scanf("%d%d",&a,&tt);
			int line = ++t[a][0].first;
			t[a][line] = {i,tt};
		}
	}
	init();
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(g[i][j] == LONG_LONG_MAX) continue;
			gg[i].push_back({j,g[i][j]});
			gg[j].push_back({i,g[j][i]});
		}
	}
	for(int i=1;i<=qq;i++){
		int s,t;
		scanf("%lld%lld",&s,&t);
		cout<<solve(s,t)<<"\n";
	}
	return 0;
}