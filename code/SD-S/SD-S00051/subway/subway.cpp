#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,M=5e5+5;
int C,n,m,d,q,k[N];
ll val[N];
//vector <ll> a[N],t[N];
struct edge{
	int v;
	ll w;
};
vector <edge> g[N+M];
struct node{
	int u;
	ll dis;
	friend bool operator >(node p,node q){
		return p.dis>q.dis;
	}
};
ll bfs(int s,int t){
	map <int,ll> mp; 
	priority_queue <node,vector<node>,greater<node> > q;
	q.push({s,0ll});
	mp[s]=0ll;
	while(!q.empty()){
		auto u=q.top();
		q.pop();
		if(mp[u.u]!=u.dis) continue;
		for(auto it:g[u.u]){
			int v=it.v;
			ll w=it.w;
			if(mp.count(v)==0||mp[v]>w+u.dis){
				mp[v]=w+u.dis;
				q.push({v,mp[v]});
			}
		}
	}
//	cout<<mp.count(t)<<"\n";
	return val[s]+val[t]+mp[t];
}
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&C,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&val[i]);
	} 
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
//		a[i].push_back(0);
//		t[i].push_back(0);
		for(int j=1;j<=k[i];j++){
			int x,y;
			scanf("%d%d",&x,&y);
//			a[i].push_back(x);
//			t[i].push_back(y);
			g[x].push_back({i+m,y});
			g[i+m].push_back({x,y});
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",bfs(x,y));
	} 
	return 0;
}
/*
安吉做过类似的思路？
虚拟点？ 
跑一遍最短路转化成树，然后用一个类似lca的东西？
那关于虚拟点呢，那就记父亲的时候特殊处理？
其实好像不用管，不影响我们 
hack:
a->b 7
a->c 8
b->c 2
所以我们不能用这种想法
算了算，每次一次dij好像复杂度没啥大问题？ 
但dis清空会炸吧，那就舍弃dis？
为啥数太大直接不输出？ 
d非常小，难道是正解的引导？ 
*/
