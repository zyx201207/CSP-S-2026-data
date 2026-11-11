#include<bits/stdc++.h>
using namespace std;
#define N 510
#define M 500010
#define int long long
struct node {
	int v,w,fa;
};
int c,n,ans=1e9,m,d,t;
int w[N],a[M*2],vis[N],w1[N];
vector<node> e[N],q[M];
void dfs(int now,int end,int tmp,int siz,int bl) {
	if(now==end) {
		ans=min(ans,tmp+siz);
		return;
	}
	for(auto i:q[now]) {
		if(vis[i.v]) continue;
		vis[i.v]=1;
		if(i.fa!=bl) {
			dfs(i.v,end,tmp+siz+i.w,i.w,i.fa);
//			cout<<now<<" "; 
		} else {
			dfs(i.v,end,tmp,i.w,bl);
		}
		vis[i.v]=0;
	}
}
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>t;
	for(int i=1; i<=m; i++) {
		cin>>w[i];
	}
	for(int i=1; i<=n; i++) {
		int k;
		cin>>k;
		for(int j=1; j<=k*2; j++) {
			cin>>a[j];
		}
		for(int j=1; j<=k*2; j+=2) {
			e[i].push_back(node {a[j],a[j+1],i});
		}
	}
//	for(int i=1;i<=n;i++){
//		for(auto j:e[i]){
//			cout<<i<<" "<<j.v<<" "<<j.w<<" "<<j.fa<<" "<<"\n";
//		}
//	}
//	cout<<"\n\n\n\n";
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=e[i].size()-1; j++) {
			if(j!=0)			 q[e[i][j].v].push_back(node{e[i][j-1].v,e[i][j-1].w,e[i][j-1].fa});
			if(j!=e[i].size()-1) q[e[i][j].v].push_back(node{e[i][j+1].v,e[i][j+1].w,e[i][j+1].fa});
		}
	}
//	for(int i=1;i<=m;i++){
//		for(auto j:q[i]){
//			cout<<i<<" "<<j.v<<" "<<j.w<<" "<<j.fa<<" "<<"\n";
//		}
//	}
	for(int k=1; k<=t; k++) {
		int u,v;
		ans=1e9;
		cin>>u>>v;
		vis[u]=1;
		for(auto i:q[u]) {
			for(auto j:q[i.v]){
				if(j.v==u){
//					cout<<w[u]+w[v]+j.w<<" ";
					dfs(i.v,v,w[u]+w[v]+j.w,i.w,i.fa);
				}
			}
			
		}
		cout<<ans<<"\n"; 
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
力竭了，再给我一小时我绝对改出来！！
袁总nb 
*/

