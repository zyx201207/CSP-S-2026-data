#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N],cnt[N],x[10010],y[10010],k[510],timme;
bool vis[N];
struct node{
	int a[N],t[N];
}subw[510]; 
struct nodd{
	int tim,n_x,n_s;
};
vector<pair<int,int>> edge[N];//<可到点，走哪条地铁>
vector<int> pas[N];//每个点被哪些地铁经过 
int bfs(int x,int y,int sub){
	queue<nodd> q;//<时间，当前点，走地铁编号>
	q.push({timme,x,sub});
	while(!q.empty()){
		auto kkk=q.front();q.pop();
		int u=kkk.n_x,n_sub=kkk.n_s,n_time=kkk.tim;
		if(u==y){
			return n_time;
		}
		if(vis[u])continue;
		vis[u]=1;
		n_time+=subw[n_sub].t[u] ;
		for(auto kk:edge[u]){
			int v=kk.first,go_sub=kk.second;
			n_time+=subw[go_sub].t[v] ;
			q.push({n_time,v,go_sub});
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=k[i];++j){
			cin>>subw[i].a[j]>>subw[i].t[j];
//			if(j!=1){
//				edge[lst].push_back(subw[i].a);
//				edge[subw[i].a].push_back(lst)
//			}
//			lst=subw[i].a
			pas[subw[i].a[j]].push_back(j);
			cnt[subw[i].a[j]]++;
		}
	}for(int i=1;i<=q;++i)cin>>x[i]>>y[i];
	for(int cc=1;cc<=q;++cc){
		for(int i=1;i<=m;++i)edge[i].clear(); 
		for(int i=1;i<=n;++i){
			int u=subw[i].a[1];
			for(int j=2;j<=k[i];++j){
				int v=subw[i].a[j];
				if(cnt[v]>=1||v==x[cc]||v==y[cc]){
					edge[v].push_back({u,i});
					edge[u].push_back({v,i});
					u=v;
				}
			}
		}timme=w[x[cc]]+w[y[cc]];
		cout<<bfs(x[cc],y[cc],0)<<endl;
	}
	
//	for(auto i:pas[x]){
	
//	}
//
	return 0;
} 
