#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=500005;
int c,n,m,d,p;
ll w[N],t[25][N],dist[N],maxv;
vector<int> g[N];
int a[N];

void dfs(int u,int fa,int k,int end){
	ll res=0;
	if(u==end){
		ans=min(ans,res);
		return ;
	}
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(v==fa) continue;
		for(int j=1;j<=20;j++){
			if(t[j][v]){
				if(v!=k) res+=t[k][v]+t[j][v];
				dfs(v,u,j,end);
			}
		}
	}
}


void solve1(){
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int v,time;
			cin>>v>>time;
			t[i][v]=time;
			a[j]=v;
			maxv=max(v,maxv);
		}
		for(int j=1;j<k;j++){
			int u=a[j],v=a[j+1];
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	while(q--){
		int u,v;
		cin>>u>>v;
		ll ans=0;
		ans+=w[u]+w[v];
		
		
	}
}

int main(){
	cin>>c>>n>>m>>d>>q;

	
	
	
	
	return 0;
}
