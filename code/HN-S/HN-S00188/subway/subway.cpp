#include "bits/stdc++.h"
using namespace std;
int c,n,m,p,q;
long long ans;
const int M=5*1e5+5;
const int N=1e5+5;
int w[M],k,x,y,a,t,st[M][505];
map<int,int>mp[505];
void dfs(int x,int y){
	ans=w[x]+w[y];
	for(int i=1;i<=n;i++){
		if(mp[i][x]&&mp[i][y]){
			ans+=mp[i][x]+mp[i][y];
			return ;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>p>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			mp[i][a]=t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		dfs(x,y);
		cout<<ans<<'\n';
	}
	
	return 0;
}
