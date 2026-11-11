#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500010,M=300010;
int n,m;
int a[N],b[M];
bool vis[M];
int fa[N];
vector<int>e[N];
int f[N],g[N],ans[M];
void dfs(int x){
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i];
		dfs(y);
		f[x]+=f[y];
	}
	f[x]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(vis[a[i]]==0){
			vis[a[i]]=1;
			b[a[i]]=i;
		}
		fa[i]=b[a[i]]+1;
		e[fa[i]].push_back(i);
	}
	dfs(n+1);
	for(int i=1;i<=n;i++){
		ans[a[i]]+=f[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}