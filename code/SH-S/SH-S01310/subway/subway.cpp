#include<bits/stdc++.h>
//#define int long long
#define N 200005
using namespace std;
int c,n,m,d,q,a[505][N],t[505][N],ff[N],mp[N],nn;
int w[N];
int k[505],dis[N];
struct Node{
	int v,w;
	bool operator <(const Node& a)const{
		return w>a.w;
	}
};
vector<Node> cnt[N];
vector<Node> edge[N];
int dijkstra(int st,int en){
	for(int i=1;i<=nn;i++)dis[i]=1e9;
	dis[st]=0;
	priority_queue<Node> q;
	q.push({st,0});
	while(q.size()){
		int u=q.top().v,w=q.top().w;
		q.pop();
		if(dis[u]<w)continue;
		dis[u]=w;
		if(u==en){
			return dis[u];
		}
		for(auto i:edge[u]){
			if(dis[i.v]>w+i.w){
				if(u==st){
					if(u>n){
						int ttt=0;
						for(auto t:cnt[ff[u]]){
							if(t.v==i.v){
								ttt=t.v;
								break;
							}
						}
						dis[i.v]=t[i.v][ttt];
						q.push({i.v,t[i.v][ttt]});
					}else{
						int ttt=0;
						for(auto t:cnt[u]){
							if(t.v==u){
								ttt=t.v;
								break;
							}
						}
						dis[i.v]=t[u][ttt];
						q.push({i.v,t[u][ttt]});
					}
				}else{
					dis[i.v]=w+i.w;
					q.push({i.v,dis[i.v]});
				}
			}
		}
	}
	return -1;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			cnt[a[i][j]].push_back({i,j});
		}
	}
	int len=n;
	for(int i=1;i<=m;i++){
		if(cnt[i].size()>1){
			mp[i]=++len;
			ff[len]=i;
			for(auto u:cnt[i]){
				edge[len].push_back({u.v,t[u.v][u.w]});
				edge[u.v].push_back({len,t[u.v][u.w]});
			}
		}
	}
	nn=len+n;
	while(q--){
//		cout<<"HOOOOOOOOOOOO"<<endl;
		int st,en;
		cin>>st>>en;
		int ans=0;
		if(cnt[st].size()>1){
			if(cnt[en].size()>1){
				dijkstra(n+mp[st],n+mp[en]);
				ans=dis[n+mp[en]];
			}
			else{
				dijkstra(n+mp[st],cnt[en][0].v);
				ans=dis[cnt[en][0].v];
			}
		}else{
			if(cnt[en].size()>1){
				dijkstra(cnt[st][0].v,dis[n+mp[en]]);
				ans=dis[n+mp[en]];
			}
			else{
				dijkstra(cnt[st][0].v,cnt[en][0].v);
				ans=dis[cnt[en][0].v];
			}
		}
		cout<<w[st]+w[en]+ans<<"\n";
	}
	return 0;
}

