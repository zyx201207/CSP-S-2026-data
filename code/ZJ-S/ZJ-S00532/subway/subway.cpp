#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <map>
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,W[N],k[N],vis[N],dis[N];
vector<pair<int,int>>e[N],t[N];
void dijstral(int x,int y){
	memset(dis,0x7f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[x]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	q.push({0,x});
	for(auto v:e[x])dis[v.first]=v.second,q.push({dis[v.first],v.first});
	while(!q.empty()){
		auto t=q.top();q.pop();
		int k=t.second;
		if(vis[k])continue;
		vis[k]=1;
		for(auto v:e[k]){
			int u=v.first,w=v.second;
			if(dis[u]>dis[k]+w){
				dis[u]=dis[k]+w;
				q.push({dis[u],u});
				vis[k]=0;
			}
		}
	}
	cout<<dis[y]+W[x]+W[y]<<endl;
	return ;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>W[i];
	
	
		for(int i=1;i<=n;i++){
			cin>>k[i];
			for(int j=1;j<=k[i];j++){
				int x,y;
				cin>>x>>y;
				//x->L
				t[i].push_back({x,y});
				//line i->x
			}
		}
		for(int i=1;i<=n;i++){
			for(auto u:t[i])
				for(auto v:t[i]){
					//u->v
					if(u!=v)e[u.first].push_back({v.first,u.second+v.second});
				}
		}
		
	
	while(q--){
		int x,y;
		cin>>x>>y;
		dijstral(x,y);
	}
	return 0;
}
//start 1.1h
//end 2.6h
