#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
bool f[N];
int ans[N];
int p[N];
vector<int> g[N];
int dfs(int now){
	ans[now]+=p[now];
	for(auto i:g[now]){
		ans[now]+=dfs(i);
	}
	return ans[now];
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]]++;
	}
	for(int i=n;i>=1;i--){
		if(f[a[i]]==0){
			g[a[i+1]].push_back(a[i]);
			f[a[i]]=1;
		}	
	}
	dfs(a[n]);
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}                      