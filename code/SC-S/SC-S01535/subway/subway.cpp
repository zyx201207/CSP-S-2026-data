#include <bits/stdc++.h>
using namespace std;

vector<map<int,int>> c;
int tim[505];
void add(int i,int u,int v){
	c[i].insert({u,v});
}
int find_mod(int u,int v){
	int ans=INT_MAX;
	for(auto j:c){
		if(j.count(u)&&j.count(v)){
			ans=min(ans,j[u]+j[v]);
		}
	}
	return ans+tim[u]+tim[v];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>tim[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int m,kk;
			cin>>m>>kk;
			add(i,m,kk);
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;cin>>u>>v;
		cout<<find_mod(u,v)<<'\n';
	}
	return 0;
}