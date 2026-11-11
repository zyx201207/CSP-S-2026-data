#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;
struct node{
	int v,t;
}; 
vector<node>edge[500001];
int x[500001];
int c,n,m,d,q;
int T;
int l,r;
int vis[500001];
int t[51][500001];
int ans=2147483647;
void dfs(int u,int s,int d){
	if(u==r){
		ans=min(ans,d+t[s][r]);
		return;
	}
	vis[l]=1;
	for(node nd:edge[u]){
		int v=nd.v;
		int i=nd.t;
		if(vis[v]) continue;
		vis[v]=1;
		if(i==s){
			dfs(v,s,d);
		}else{
			dfs(v,i,d+t[s][u]+t[i][v]);
		}
		vis[v]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>x[i];
	}
	for(int j=1;j<=n;j++){
		int k;
		cin>>k;
		int b;
		cin>>b;
		cin>>t[j][b];
		for(int i=1;i<k;i++){
			int a;
			cin>>a;
			cin>>t[j][a];
			edge[b].push_back(node{a,j});
			b=a;
		}
	}
	while(q--){
		cin>>l>>r;
		int cnt=2147483647;
		ans=2147483647;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++){
			if(t[l][i]==0) continue; 
			dfs(l,i,t[l][i]);
			cnt=min(cnt,ans+x[l]+x[r]);
		}
		cout<<cnt<<endl;
	}
	return 0;
}
