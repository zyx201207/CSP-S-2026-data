#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],s[300010],vis[300010],ans[300010];
vector<int> e[300010];
void dfs(int u){
	ans[u]=s[u];
	for(int i:e[u]){
		dfs(i);
		ans[u]+=ans[i];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]++;
	}
	for(int i=n;i>=1;i--){
		if(!vis[a[i]]){
			vis[a[i]]=1;
			e[a[i+1]].push_back(a[i]);
		}
	}
	dfs(a[n]);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} 
