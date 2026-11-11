#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,M=3e5+5;
int n,m,a[N];
int fa[N];
int lst[M];
int size[N];
int ans[M];
vector<int> f[N];
void dfs(int u){
	size[u]=1;
	for(auto it:f[u]){
		dfs(it);
		size[u]+=size[it];
	}
	if(u==n||a[fa[u]]!=a[u]) ans[a[u]]+=size[u];
	//cout<<u<<' '<<size[u]<<'\n';
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	lst[a[n]]=n;
	for(int i=n-1;i>0;--i){
		if(lst[a[i]]){
			fa[i]=lst[a[i]];
		}else{
			fa[i]=i+1;
		}
		f[fa[i]].push_back(i);
		lst[a[i]]=i;
	}	
	dfs(n);
//	for(int i=1;i<=n;++i){
//		cout<<fa[i]<<' ';
//	}
	for(int i=1;i<m;++i){
		cout<<ans[i]<<' ';
	}
	cout<<ans[m]<<'\n';
}

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
