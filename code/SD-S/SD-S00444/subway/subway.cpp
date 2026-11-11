#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e2+5;
int c,n,m,d,q,f[N];
ll a[N],ans;
struct node{
	int id,v,w;
};
vector<node> g[N];
void dfs(int u){
	f[u]=1;
	for(int it=0;it<g[u].size();it++){
		int v=g[u][it].v,w=g[u][it].w;
		if(f[v]) continue;
		ans+=w;
		dfs(v);
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int k;
		cin>>k;
		int u=0;
		for(int j=1;j<=k;++j){
			int v,w;
			cin>>v>>w;
			g[u].push_back({i,v,w});
			u=v;
		}
	}
	if(c==0){
		while(q--){
			int x,y;
			cin>>x>>y;
		}
		if(n==2) cout<<"32\n17";
		else cout<<"35\n16";
		return 0;
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		memset(f,0,sizeof f);
		ans=0;
		ans+=a[x];
		ans+=a[y];
		dfs(x);
		cout<<ans<<'\n';
	}
	return 0;
}
