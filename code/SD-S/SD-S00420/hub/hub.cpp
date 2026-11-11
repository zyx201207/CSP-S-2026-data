#include<bits/stdc++.h>
#define umap unordered_map
#define mset multiset
#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define yes cout<<"Yes\n"
#define no cout<<"No\n"
#define all(x) (x).begin(),(x).end()
#define tmax(a,b) (a)=max((a),(b))
#define tmin(a,b) (a)=min((a),(b))
#define cout(x) cout<<fixed<<setprecision(x)

using namespace std;
typedef unsigned long long ULL;
typedef long long LL;typedef pair<int,int> PII;
typedef vector<int> vi;typedef vector<PII> vp;
typedef array<int,3> a3;typedef vector<a3> va3;

const int N=1e6+5;
int n,k,vis[N],fa[N],ans;
vi g[N],nd;
map<ULL,int>mp;
bool vv[N];

int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int dis(int s){
	queue<PII>q;
	for(int i=1;i<=n;i++) vv[i]=0;
	q.push({0,s});
	while(q.size()){
		int u=q.front().se,d=q.front().fi;
		q.pop();
		if(vis[u]) return d;
		for(auto v:g[u]){
			if(!vv[v]){
				vv[v]=1;
				q.push({d+1,v});
			}
		}
	}
}

void clear(){
	mp.clear();
	for(int i=1;i<=n;i++){
		g[i].clear();
	}
}
void solve(){
	cin>>n>>k;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].pb(v),g[v].pb(u);
		if(u>v) swap(u,v);
		mp[(ULL)u*(n+1)+v]=1;
	}
	ans=n+n;
	for(int s=1;s<(1<<n);s++){
		if(__builtin_popcount(s)!=k) continue;
		nd.clear();
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++){
			if(s>>i-1&1){
				nd.pb(i);
				vis[i]=1;
			}
			fa[i]=i;
		}
		vi bel;
		for(auto u:nd){
			for(auto v:nd){
				if(u>=v) continue;
				if(!mp.count((ULL)u*(n+1)+v)) continue;
				fa[find(u)]=find(v);
			}
		}
		for(auto u:nd){
			bel.pb(find(u));
		}
		sort(all(bel));
		bel.erase(unique(all(bel)),bel.end());
		if(bel.size()>2) continue;
		int res=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				tmax(res,dis(i));
			}
		}
		tmin(ans,res);
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1,c;cin>>c>>t;
	while(t--) clear(),solve();
	return 0;
}
/*

*/

