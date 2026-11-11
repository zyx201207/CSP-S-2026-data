#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,g[505][505];
void dfs(int dep){
	if(dep==k){
		
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,u,v;i<=n-1;i++){
			cin>>u>>v;
			g[u][v]=1;
			g[v][u]=1;
		}
	}
	
	return 0;
}
