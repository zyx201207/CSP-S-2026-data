#include<bits/stdc++.h>
using namespace std;
struct train{
	int v;
	int cnt; 
	//long long t; 
};
long long z[5000][5000];
long long w[500010];
vector<train> adj[500010];
int x,y;
long long ans=5e10+5;
void dfs(int e,long long an){
	if(e==x){
		ans=min(ans,an);
		return;
	}
	for(auto i:adj[e]){
		dfs(i.v,an+z[i.v][e]);
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n;
	long long m;
	int d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a1;
		long long t1;
		cin>>a1>>t1;
		int a;
		long long t;
		for(int j=2;j<=k;i++){
		 	cin>>a>>t;
		 	adj[a1].push_back({a,i});
		 	adj[a].push_back({a1,i});
		 	if(z[a1][a]==0){
		 		z[a1][a]=t1+t;
				z[a][a1]=t1+t;	
			}else{
				z[a1][a]=min(z[a1][a],t1+t);
				z[a][a1]=min(z[a][a1],t1+t);
			}
		}
	for(int i=1;i<=q;i++){
		ans=5e10+5;
		cin>>x>>y;
		dfs(x,w[x]);
		cout<<ans<<"\n";
	}
	
	
	
	}
}
