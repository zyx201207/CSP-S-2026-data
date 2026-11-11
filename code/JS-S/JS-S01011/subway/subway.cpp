#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,M=5e5+5,K=1e3+5;
vector<int> a[N],t[N];
int len[N];
vector<pair<int,int>> g[M];
struct node{
	int d,v;
};
bool operator<(const node &x,const node &y){
	return x.d>y.d;
}
priority_queue<node> q;
int dis[K][K],vis[M],w[M],d[M];
set<int> s[N],s1[N];
vector<int> g1[M],now;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,D,T;cin>>c>>n>>m>>D>>T;
	for(int i=1;i<=m;i++) cin>>w[i];
	if(c>=12 and c<=19){
		for(int i=1;i<=n;i++){
			cin>>len[i];a[i].push_back(0),t[i].push_back(0);
			for(int j=1,x,y;j<=len[i];j++) cin>>x>>y,s[i].insert(x),t[i].push_back(y),g1[x].push_back(i);
			//cout<<len[i]<<" "<<a[i][3]<<endl;
		}
		while(T--){
			int x,y;cin>>x>>y;
			for(int i=1;i<=m;i++) d[i]=1e18;
			d[x]=0;
			for(int i=1;i<=n;i++) for(auto it:s[i]) s1[i].insert(it);
			queue<int> q;q.push(x);
			while(!q.empty()){
				int u=q.front();q.pop();
				for(int id:g1[u]){
					for(auto it=s1[id].begin();it!=s1[id].end();it++){
						if(*it==u) continue;
						d[*it]=d[u]+1,q.push(*it);
					}s1[id].clear();
				}
			} 
			cout<<d[y]*t[1][1]*2+w[x]+w[y]<<"\n";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>len[i];a[i].push_back(0),t[i].push_back(0);
		for(int j=1,x,y;j<=len[i];j++) cin>>x>>y,a[i].push_back(x),t[i].push_back(y);
		//cout<<len[i]<<" "<<a[i][3]<<endl;
		for(int j=1;j<=len[i];j++){
			for(int k=j+1;k<=len[i];k++){
				//cout<<a[i][j]<<" "<<a[i][k]<<endl;
				g[a[i][j]].push_back({a[i][k],t[i][j]+t[i][k]});
				g[a[i][k]].push_back({a[i][j],t[i][j]+t[i][k]});
			}
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int s=1;s<=m;s++){
		for(int i=1;i<=m;i++) vis[i]=0;
		while(!q.empty()) q.pop();
		dis[s][s]=0;q.push({0,s});
		while(!q.empty()){
			int u=q.top().v;q.pop();
			for(auto e:g[u]){
				int v=e.first,w=e.second;
				if(dis[s][v]>dis[s][u]+w) dis[s][v]=dis[s][u]+w,q.push({dis[s][v],v});
			}
		}
	}
	while(T--){
		int u,v;cin>>u>>v;cout<<dis[u][v]+w[u]+w[v]<<"\n";
	}
	return 0;
}
