#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N=500010;
int a[N],n,m;
int r[N],sz[N],ans[N];
vector<int > edge[N];
void dfs(int u,int fa){
	sz[u]=1;
	for(const int& v:edge[u]){
		if(v!=fa){
			dfs(v,u);
			sz[u]+=sz[v];
		}
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(r[a[i]]) edge[r[a[i]]].emplace_back(i);
		else edge[i+1].emplace_back(i),r[a[i]]=i;
	}
	dfs(n,0);
	for(int i=1;i<=n;i++) ans[a[i]]=max(ans[a[i]],sz[i]);
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
