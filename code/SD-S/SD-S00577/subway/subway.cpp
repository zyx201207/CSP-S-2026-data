#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,q,w[500100],dis[510][510];
vector<pair<int,int> >sub[500100],edge[510];
void dijk(int s){
	memset(dis[s],-1,sizeof(dis[s]));
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >pq;
	pq.push({0,s});
	dis[s][s]=0;
	while(pq.size()){
		int u=pq.top().second;
		if(dis[s][u]!=pq.top().first){pq.pop();continue;}
		pq.pop();
		for(pair<int,int>p:edge[u]){
			int v=p.first,w=p.second+dis[s][u];
			if(dis[s][v]==-1||w<dis[s][v]){
				dis[s][v]=w;
				pq.push({dis[s][v],v});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int a,t;
			cin>>a>>t;
			sub[a].push_back({i,t});
		}
	}
	for(int i=1;i<=m;i++)
		for(pair<int,int>j:sub[i])
			for(pair<int,int>k:sub[i]){
				if(j.first<=k.first)continue;
				edge[j.first].push_back({k.first,j.second+k.second});
				edge[k.first].push_back({j.first,j.second+k.second});
			}
	for(int i=1;i<=n;i++)dijk(i);
	while(q--){
		int x,y,ans=1e18;
		cin>>x>>y;
		for(pair<int,int>i:sub[x])
			for(pair<int,int>j:sub[y])ans=min(ans,w[x]+w[y]+i.second+j.second+dis[i.first][j.first]);
		cout<<ans<<"\n";
	}
	return 0;
}
/*
14:49 有了一个不需要c和d的思路，怀疑d存在的意义
思路：
只建4种边 
地铁口->站厅
站厅->地铁线路
地铁线路->站厅
站厅->地铁口
地铁口=地铁口编号
站厅=站厅编号+m
地铁线路=地铁线路号+2m
我去多次询问？！ 
重新思考。
14:55 发现了一大块被遗忘的黑玻璃，疑似因不粘而被弃用的防窥膜 
14:58 n<=500，我们好像可以每次查询O(d^2)的根据地铁站间的距离求出答案？！
15:00 我们好像可以枚举2个线路间的重复点求出2个线路间的距离，这样建边时间复杂度O(nm)，会T
15:02 欸我们可以枚举点！每个点O(d^2)的更新2个地铁站间的长度好多了！
15:04 那这样我们计算2个地铁站间最短距离就可以n个dijk，最后时间复杂度O(n^2logn+nd^2+q^2)，理解了d的意义，但还是怀疑要输入d的意义，开写
15:33 写完了并测试样例，AC 
*/

