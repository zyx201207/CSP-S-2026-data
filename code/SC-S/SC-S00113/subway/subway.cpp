#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N=5e5+7,L=507;
int c,n,m,d,q,w[N],k[N];
ll g[L][L];
vector<int> a[L],t[L],to[N],dist[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	//棍木，线路数，点数，MAX，询问
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) fill(g[i],g[i]+n+1,1e18),g[i][i]=0;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		a[i].resize(k[i]);
		t[i].resize(k[i]);
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
			to[a[i][j]].push_back(i);
			dist[a[i][j]].push_back(w[a[i][j]]+t[i][j]);
		}
	}for(int u=1;u<=n;u++){
		int sz=a[u].size();
		for(int i=0;i<sz;i++){
			int v=a[u][i];
			int sz1=to[v].size();
			for(int j=0;j<sz1;j++){
				int z=to[v][j];
				g[u][z]=min(g[u][z],1ll*t[u][i]+dist[v][j]-w[v]);
			}
		}
	}for(int k=1;k<=n;k++){
		for(int l=1;l<=n;l++){
			for(int r=1;r<=n;r++){
				g[l][r]=min(g[l][r],g[l][k]+g[k][r]);
			}
		}
	}while(q--){
		int u,v;cin>>u>>v;
		if(u==v){
			cout<<"0\n";
			continue;
		}ll res=1e18;
		int szu=to[u].size(),szv=to[v].size();
		for(int i=0;i<szu;i++){
			for(int j=0;j<szv;j++){
				res=min(res,dist[u][i]+g[to[u][i]][to[v][j]]+dist[v][j]);
			}
		}cout<<res<<'\n';
	}
}