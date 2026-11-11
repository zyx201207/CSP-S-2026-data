#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int c,n,m,d,q;
const int N=5e5+5;
const int M=5e2+5;
int w[N],pos[M],val[M];
int dis[N],f[N];
struct pii{
	int fi,se;
	bool operator<(const pii &other)const{
		return se>other.se;
	}
};
vector<pii> vec[N],num[N];//哪几条线路中存在当前站 
inline void dijkstra(int s){
	priority_queue<pii> q;
	memset(f,0,sizeof f);
	memset(dis,0x3f,sizeof dis);
	dis[s]=0;
	q.push({s,0});
	while(!q.empty()){
		int k=q.top().fi;
		if(f[k]) continue;
		f[k]=1;
		q.pop();
		for(auto u:vec[k]){
			int t=u.fi,v=u.se;
			if(dis[t]>dis[k]+v){
				dis[t]=dis[k]+v;
				q.push({t,dis[t]});
			}
		}
	}
	return ;
}
inline int query(int x,int y){
	dijkstra(x);
	return dis[y]-w[x]-w[y];
}
int main(){
	//why q 1e5?
	//why d 20?
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//第几条线 
		int t;cin>>t;
		for(int j=1;j<=t;j++){//第几站 
			cin>>pos[j]>>val[j];
		}
		vec[pos[1]].push_back({pos[2],val[1]+w[1]+val[2]+w[2]});
		vec[pos[2]].push_back({pos[1],val[1]+w[1]+val[2]+w[2]});
	}
	for(int i=1;i<=q;i++){
		int x,y;cin>>x>>y;
		cout<<query(x,y)<<endl;
	}
	return 0;
}
