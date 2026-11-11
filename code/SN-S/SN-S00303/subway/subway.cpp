#include<bits/stdc++.h>
using namespace std;
const int N=501;
const int M=5e5+1;
int c,n,m,d,q,w[M],a[N],sum[N],k[N],ca,ct,cx,cy,dis[M];
struct node{int a,t;};
vector<node> cc[N];
struct node1{int bi,t;};
vector<node1> z[M];
struct node2{int val,st,ed;};
bool check(int bid,int f,int s){
	for(int i=0;i<k[bid];i++){
		if(cc[bid][i].a==f) return 1;
		else if(cc[bid][i].a==s) return 0;
	}
}
void dfs(int u,int x,int fa,int faw,int w){
	if(w>dis[x]) return;
	dis[x]=w;
	if(x==cy) return;
	for(int i=x;i<=k[u];i++){
		dfs(u,i,u,x,w);
		for(int j=0;j<z[i].size();j++){
			if(z[i][j].bi==fa&&check(fa,faw,i)) continue;
			dfs(z[i][j].bi,i,u,x,w+z[i][j].t);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>ca>>ct;
			cc[i].push_back({ca,ct});
			z[ca].push_back({i,ct});
		}
	}
	while(q--){
		cin>>cx>>cy;
		for(int i=1;i<=m;i++){
			dis[i]=INT_MAX;
		}
		dis[cx]=0;
		dfs(z[cx][0].bi,cx,-1,-1,0);
		cout<<dis[cy]+w[cx]+w[cy]<<"\n";
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
*/
