#include<bits/stdc++.h>
using namespace std;
int a[500005];
int pos[500005];
vector<int> vec[500005];
int ans[500005];
void dfs(int u){
	for(int v:vec[u]){
		dfs(v); ans[u]+=ans[v];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) pos[a[i]]=i,ans[a[i]]++;
	int st=0;
	for(int i=1;i<=m;i++){
		if(pos[i]<n) vec[a[pos[i]+1]].push_back(i);
		else st=i;
	}
	dfs(st);
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}
