#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,x,y,w[1000010],k[1000010],a[1510][1510];
vector<pair<int,int> >g[1000010];
void solve(){
	cin>>x>>y;
	int ans=1e18;
	for(auto i:g[x]){
		for(auto j:g[y]){
			ans=min(ans,j.second+i.second+a[i.first][j.first]);
//			cout<<j.second<<' '<<i.second<<' '<<a[i.first][j.first]<<'\n';
		}
	}
	cout<<w[x]+w[y]+ans<<'\n';
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			a[i][j]=1e18;
		}
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,v;
			cin>>u>>v;
			g[u].push_back({i,v});
		}
	}for(int i=1;i<=m;i++){
		for(auto j:g[i]){
			for(auto k:g[i]){
				if(j.first==k.first)continue;
				a[k.first][j.first]=a[j.first][k.first]=min(j.second+k.second,a[j.first][k.first]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	while(q--){
		solve();
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


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
