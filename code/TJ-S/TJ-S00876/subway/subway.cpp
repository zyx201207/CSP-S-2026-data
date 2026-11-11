#include<bits/stdc++.h>
using namespace std;
int w[100005];
int a[5005][5005];
int t[5005][5005];
vector<pair<int,int> > g[100005];
void solve(){
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,t;
			cin>>v>>t;
			g[i].push_back({v,t});
			g[v].push_back({i,t});
		}
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	
	
	return 0;
}
