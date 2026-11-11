#include<bits/stdc++.h>
using namespace std;
int ID,n,m,d,q;
int c[500005];
long long dis[500005],ans[100005];
bool vis[500005];
priority_queue<pair<int,int>> pq;
int s[100005];
int t[100005];
int id[500005];
int cnt[500005];
int pos[500005];
vector<int> all,dian[505];
vector<pair<int,int>> e[500005];
set<pair<int,int>> ee[500005];
int tim[500005][505];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>ID>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>pos[j];
			dian[i].push_back(pos[j]);
			cin>>tim[i][pos[j]];
			id[pos[j]]=i;
			cnt[pos[j]]++;
		}
		for(int j=2;j<=k;j++){
			e[pos[j]].push_back({pos[j-1],0});
			e[pos[j-1]].push_back({pos[j],0});
		}
	}
	for(int i=1;i<=m;i++){
		if(cnt[i]>=2){
			all.push_back(i);
		}
	}
	for(auto i:all){
		for(auto x:e[i]){
			for(auto y:e[i]){
				int xx=x.first;
				int yy=y.first;
				if(xx!=yy&&id[xx]!=id[yy]){
					ee[xx].insert({yy,tim[id[xx]][i]+tim[id[yy]][i]});
					ee[yy].insert({xx,tim[id[xx]][i]+tim[id[yy]][i]});
				}
			}
		}
	}
	for(int u=1;u<=m;u++){
//		for(auto v:e[u]){
//			ee[u].insert({v.first,0});
//			ee[v.first].insert({u,0});
//		}
		e[u].clear();
	}
	for(int i=1;i<=m;i++){
		for(auto x:ee[i]){
			e[i].push_back({x.first,x.second});
			//cout<<i<<" "<<x.first<<" "<<x.second<<"\n";
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s[i]>>t[i];
	}
	for(int T=1;T<=q;T++){
		while(!pq.empty()){
			pq.pop();
		}
		int cnt1=e[s[T]].size();
		for(int i=0;i<cnt1;i++){
			e[s[T]].push_back({e[s[T]][i].first,tim[id[e[s[T]][i].first]][s[T]]});
			e[e[s[T]][i].first].push_back({s[T],tim[id[e[s[T]][i].first]][s[T]]});
		}
		int cnt2=e[t[T]].size();
		for(int i=0;i<cnt2;i++){
			e[t[T]].push_back({e[t[T]][i].first,tim[id[e[t[T]][i].first]][t[T]]});
			e[e[t[T]][i].first].push_back({t[T],tim[id[e[t[T]][i].first]][t[T]]});
		}
		for(int i=1;i<=m;i++){
			dis[i]=INT_MAX;
			vis[i]=false;
		}
		dis[s[T]]=0;
		pq.push({0,s[T]});
		while(!pq.empty()){
			int u=pq.top().second;
			pq.pop();
			if(vis[u]){
				continue;
			}
			vis[u]=true;
			for(auto nxt:e[u]){
				int v=nxt.first;
				int w=nxt.second;
				if(dis[u]+w<dis[v]){
					dis[v]=dis[u]+w;
					pq.push({-dis[v],v});
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(dis[i]==INT_MAX){
				dis[i]=0;
			}
		}
		for(int i=1;i<=cnt1;i++){
			e[s[T]].pop_back();
		}
		for(int i=1;i<=cnt2;i++){
			e[t[T]].pop_back();
		}
		ans[T]=c[s[T]]+c[t[T]]+tim[id[s[T]]][s[T]]+tim[id[t[T]]][t[T]]+dis[t[T]];
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<"\n";
	}
}
