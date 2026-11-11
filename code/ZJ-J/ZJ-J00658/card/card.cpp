#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m,a[N],lst[N],ans[N],sz[N];
vector<int>V[N];
void dfs(int u){
	sz[u]=1;
	for(int v:V[u])dfs(v),sz[u]+=sz[v];
	ans[a[u]]+=sz[u];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],lst[a[i]]=i;
	for(int i=1;i<=n;i++)V[lst[a[i]]+1].push_back(i);
	dfs(n+1);
	for(int i=1;i<=m;i++)cout<<ans[i]<<(i==m?'\n':' ');
	return 0;
}