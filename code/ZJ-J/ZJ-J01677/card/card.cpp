#include<bits/stdc++.h>
using namespace std;
bool st[500009],s[500009];
bool g[500009];
int ans[500009];
int x[500009];
int c[500009];
int e[500009];
int n,m;
void dfs(int u){
	if(u<1)return;
	if(st[u])return;
	st[u]=1;
	for(int i=1;i<=m;i++){
		ans[i]+=g[i];
	}
	if(e[u])dfs(e[u]);
	if(s[u-1])return;
	g[x[u-1]]++;
	dfs(u-1);
	g[x[u-1]]-=1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",x+i);
		if(c[x[i]]){
		    e[i]=c[x[i]];	
		    s[c[x[i]]]=1;
		}
		c[x[i]]=i;
	}
	g[x[n]]=1;
	dfs(n);
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
