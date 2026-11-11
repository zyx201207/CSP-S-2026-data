#include <bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,len,i,x,dl,j,pr;
int last[N],a[N],f[N],dis[N],vis[N];
vector<int> e[N];
void dfs(int u){
	dis[u]=1;
	int len=e[u].size();
	for(int i=0;i<len;i++){
		int v=e[u][i];
		dfs(v);	
		dis[u]+=dis[v];
	}
	if(u!=n+1) f[a[u]]+=dis[u];
	return ;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=n;i>=1;i--)
		if(!last[a[i]]) last[a[i]]=i;
	for(j=1;j<=n;j++){
		for(i=j;i<=n;i=last[a[i]]+1){
			if(vis[i]) break;
			vis[i]=1;
			e[last[a[i]]+1].push_back(i);
		}
	}
	dfs(n+1);
	for(i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3
*/
