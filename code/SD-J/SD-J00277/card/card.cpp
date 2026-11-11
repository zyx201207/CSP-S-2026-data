#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
const int MAXM=3e5+5;
int n,m;
int a[MAXN];
int last[MAXM];
vector<int> g[MAXN];
int siz[MAXN];
int ans[MAXM];
void dfs(int u,int fa){
	siz[u]=1;
	for(int v:g[u])if(v!=fa){
		dfs(v,u);
		siz[u]+=siz[v];
	}
	ans[a[u]]+=siz[u];
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],last[a[i]]=i;
	for(int i=1;i<=n;i++)g[last[a[i]]+1].push_back(i);
	dfs(n+1,0);
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<' ';
	}
	cout<<endl;
	return 0;
}

