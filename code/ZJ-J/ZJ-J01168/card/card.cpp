#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],y[300005];
vector<int>f[300005];
void dfs(int x){
	for(int i=0;i<f[x].size();i++){
		int v=f[x][i];
		dfs(v);
		ans[x]+=ans[v];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]++;
		y[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		f[a[y[i]+1]].push_back(i);
	}
	dfs(0);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
