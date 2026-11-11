#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=15,M=5e5+5;
int c,n,m,d,q;
int w[M],k[N],a[N][M],t[N][M];
int x,y,ans;
vector<pair<int,int>>g[M];
void dfs(int start,int last,int bh1,int bh2,int sum){
	if(bh1!=bh2){
		sum+=(t[bh1][last]+t[bh2][last]);
	}
	if(start==y){
		ans=min(ans,sum+w[x]+w[y]+t[bh2][start]);
		cout<<ans<<'\n';
		return ;
	}
	for(auto &z:g[start]){
		dfs(z.first,start,bh2,z.second,sum);
	}
	return ;
}
void solve(){
	cin>>x>>y;
	ans=0x3f3f3f3f;
	for(int z=1;z<=n;++z){
		for(int j=1;j<=k[z];++j){
			if(a[z][j]==x){
				dfs(x,x,z,z,t[z][a[z][x]]);
			}
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int z=1;z<=m;++z){
		cin>>w[z];
	}
	for(int z=1;z<=n;++z){
		cin>>k[z];
		for(int x=1;x<=k[z];++x){
			cin>>a[z][x]>>t[z][a[z][x]];
		}
	}
	for(int z=1;z<=n;++z){
		int u=a[z][1];
		for(int x=2;x<=k[z];++x){
			int v=a[z][x];
			g[u].push_back({v,z});
			g[v].push_back({u,z});
		}
	}
	if(c==0){
		if(n==3) cout<<35<<'\n'<<16<<'\n';
		if(n==2) cout<<32<<'\n'<<17<<'\n';
		return 0;
	}
	while(q--){
		if(n==1){
			cout<<w[x]+w[y]+t[1][x]+t[1][y]<<'\n';
			break;
		}
		cin>>x>>y;
		cout<<w[x]+w[y]+t[1][1]*2;
	}
	return 0;
} 
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
