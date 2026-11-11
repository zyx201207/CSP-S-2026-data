#include<bits/stdc++.h>
using namespace std;
int n,m,a[500500],f[300300];
int g[300300],pa[300300],ans[300300];
vector<int> e[300300];
int dfs(int x){
	int sz=e[x].size();
	int ret=g[x];
	for(int i=0;i<sz;i++){
		ret+=dfs(e[x][i]);
	}
	ans[x]=ret;
	return ret;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		g[a[i]]++;	
	}
	for(int i=n;i>=1;i--){
		if(f[a[i]]==0){
			pa[a[i]]=a[i+1];
			e[a[i+1]].push_back(a[i]);
			f[a[i]]=1;
		}
	}
	int root=a[n];
	dfs(root);
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
