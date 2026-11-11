#include<bits/stdc++.h>
#define int long long
#define INF 4e18
#define PII pair<int,int> 
//#define debug(x) cerr<<__LINE__<<":"<<#x<<"="<<x;
using namespace std;
const int N=2e5+10;
int n,c,t,k,res[N],dist[N],vis[N],sz[N],f[N],cnt;
vector<int> a[N];
set<int> st;
bool v[N];
void init(){
	for(int i=1;i<=n;i++){
		sz[i]=1;
		f[i]=i;
	}
}
int dfs(int x){
	if(f[x]!=x){
		f[x]=dfs(f[x]);
	}
	return f[x];
}
bool same(int x,int y){
	return dfs(x)==dfs(y);
}
void merge(int u,int v){
	if(sz[u]<sz[v])swap(u,v);
	int fu=dfs(u),fv=dfs(v);
	f[fv]=fu;
	sz[fu]+=sz[fv];
}
void add(int u,int v){
	a[u].push_back(v);
}
void dijkstra(int s){
	for(int i=1;i<=n;i++){
		dist[i]=INF;
		vis[i]=0;
	}
	dist[s]=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push({0,s});
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		vis[u]=1;
		for(int it:a[u]){
			int v=it;
			if(dist[v]>dist[u]+1){
				dist[v]=dist[u]+1;
				q.push({dist[v],v});
			}
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int u,v,i=1;i<n;i++){
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		int ans=INF;
		for(int i=0;i<(1<<n);i++){
			cnt=0;
			memset(v,0,sizeof(v));
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					res[++cnt]=j+1;
					v[j+1]=1;
				}
			}
			if(cnt!=k)continue;
			init();
			for(int j=1;j<=cnt;j++){
				for(int it:a[res[j]]){
					if(v[it]){
						merge(res[j],it);	
					}
				}
			}
			st.clear();
			for(int j=1;j<=cnt;j++){
				st.insert(f[res[j]]);
			//	debug(f[res[j]]);
			}
			//cerr<<"\n\n";
			//debug(st.size());
			if((int)st.size()<=k){
				int tqbj=0;
				for(int I=1;I<=n;I++){
					if(v[I])continue;
					dijkstra(I);
					int mn=INF;
					for(int j=1;j<=cnt;j++){
						mn=min(mn,dist[res[j]]);
					}
					tqbj=max(tqbj,mn);
				}
				ans=min(ans,tqbj);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

