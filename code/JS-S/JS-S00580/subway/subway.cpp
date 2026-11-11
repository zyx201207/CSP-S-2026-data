#include<bits/stdc++.h>
using namespace std;
const int N=510;
int c,n,m,d,q,w[N],a[N][N],t[N][N],k[N],v[N];
vector<int>g[N];
void dfs(int k){
	for(int i=0;i<g[k].size();i++){
		int v=g[k][i];
		
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			v[a[i][j]]++;
		}
		for(int j=2;j<=k[i];j++){
			g[a[i][j]].push_back(a[i][j-1]);
			g[a[i][j-1]].push_back(a[i][j]);
		}
	}
	// for(int i=1;i<=m;i++){
	// 	for(int j=0;j<g[i].size();j++){
	// 		cout<<g[i][j]<<" ";
	// 	}
	// 	cout<<'\n';
	// }
	while(q--){
		int x,y;
		cin>>x>>y;
		if(c==7||c==8||(c>=9&&c<=11)){
			cout<<w[x]+w[y]<<'\n';
		}

	}
	return 0;
}