#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
int a[500010];
int mx[300010];
vector<int>pos[300010];
vector<int>e[500010];
int ans[500010];
void dfs(int x){
	ans[x]=1;
	if(e[x].size()==0)return ;
	for(int i=0;i<e[x].size();i++){
		int v=e[x][i];
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
		mx[a[i]]=max(mx[a[i]],i);
	}
	for(int i=1;i<=n;i++)pos[a[i]].push_back(i);
	for(int i=1;i<=m;i++){
		for(int j=pos[i].size()-1;j>=1;j--){
			e[pos[i][j]].push_back(pos[i][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		e[mx[i]+1].push_back(mx[i]);
	}
	dfs(n);
	for(int i=1;i<=m;i++){
		if(i==1)cout<<ans[mx[i]];
		else cout<<' '<<ans[mx[i]];
	}
	return 0;
}
/*
*/