#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e5+5;
//n条路径 m个点 d每点最多几条路径 q计划 
int c,n,m,d,q;
ll w[M];
ll t[M][505]={};
vector<int> nd[M];
int vis[M]={};
int fa[M][505];
void st(int dm,int dn){
	for(int i=1;i<=dn;i++){
		for(int j=1;j<=dm;j++){
			fa[j][i]=j;
		}
	}
}
int find(int k,int dn){
	if(fa[k][dn]==k)
	return k;
	return fa[k][dn]=find(fa[k][dn],dn);
}
void u(int n1,int n2,int nl){
	if(find(n1,nl)==find(n2,nl)){
		return;
	}
	fa[find(n1,nl)][nl]=find(n2,nl);
}
ll mi=LLONG_MAX;
ll po;
void dfs(int x,int y,int nl){
		if(find(x,nl)==find(y,nl)){
			mi=min(mi,po+t[y][nl]);
			return;
		}
		for(int i=1;i<=m;i++){
			if(i==x){
				continue;
			}
			if(find(x,nl)==find(i,nl)&&vis[i]==0){
				for(int j=0;j<nd[i].size();j++){
					po+=t[x][nl]+t[i][nd[i][j]];
					vis[i]=1;
					dfs(i,y,nd[i][j]);
					vis[i]=0;
					po-=t[x][nl]+t[i][nd[i][j]];
				}
			}
		}
}
int main(){
	/*
	0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
	*/
		freopen("subway.in","r",stdin);
		freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i]; 
	}
	st(m,n);
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		ll a,nt;
		ll la=0;
		for(int j=1;j<=k;j++){
			cin>>a>>nt;
			if(la!=0){
				u(la,a,i);
			}
			la=a;
			t[a][i]=nt;
			nd[a].push_back(i);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ll cost=w[x]+w[y];
		mi=LLONG_MAX;
		po=0;
		vis[x]=1;
		dfs(x,y,nd[x][0]);
		cout<<cost+mi;
	}
	return 0;
}
