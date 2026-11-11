#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+3;
int w[N],a[503][N],t[503][N],x,y;
vector<pii> g[N];
ll dfs(int u,int i,ll sum){
	if(u==y){
		return sum+t[i][u];
	}
	ll res=1e12;
	for(int l=0;l<g[u].size();l++){
		int v=g[u][l].first,j=g[u][l].second;
		if(i!=j) res=min(res,dfs(v,j,sum+t[i][u]+t[l][u]));
		else res=min(res,dfs(v,j,sum));
	}
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			pii k_1,k_2;
			k_1.first=i,k_1.second=a[i][j-1];
			k_2.first=i,k_2.second=a[i][j];
			g[a[i][j]].push_back(k_1);
			g[a[i][j-1]].push_back(k_2);
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<dfs(x,0,0)+w[x]+w[y]<<endl;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
