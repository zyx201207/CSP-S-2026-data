#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
struct node{
	int v,w;
	bool operator<(const node x)const{
		return w>x.w;
	}
};
priority_queue<node> que;
vector<node> G[N];
int c,n,m,d,q,point_val[N];
int flag[N],dis[N];
void dijstra(int s){
	memset(flag,0,sizeof flag);
	memset(dis,0x3f,sizeof dis);
	que.push({s,0});
	dis[s]=0;
	while(!que.empty()){
		int u=que.top().v; que.pop();
		if(flag[u]) continue;
		for(auto x:G[u]){
			int v=x.v,w=x.w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				que.push({v,dis[v]});
			}
		}
		flag[u]=1;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>point_val[i];
	int super_point_id=m;
	for(int i=1;i<=n;i++){
		int subway_len; cin>>subway_len;
		super_point_id++;
		for(int j=1;j<=subway_len;j++){
			int x,y; cin>>x>>y;
			G[super_point_id].push_back({x,y});
			G[x].push_back({super_point_id,y});
		}
	}
	for(int i=1;i<=q;i++){
		int uu,vv; cin>>uu>>vv;
		int sum=point_val[uu]+point_val[vv];
		dijstra(uu);
		cout<<sum+dis[vv]<<"\n";
	}
	return 0;
}
