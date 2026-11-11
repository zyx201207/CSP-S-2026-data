#include<bits/stdc++.h>
using namespace std;
const int M=3e5+100,N=5e5+100;
int n,m;
int cards[N],last[M],ans[M];
//int fa[N];
vector<int> c[N];
//int mf[N];
/*
void f(int l){
	if(l>n) return;
	f(last[cards[l]]+1);
	ans[cards[l]]++;
}
*/
bool vis[M];
int dfs(int u){
	int r=1;
	for(auto k:c[u]){
		r+=dfs(k);
	}
	if(!vis[cards[u]]) ans[cards[u]]+=r;
	return r;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cards[i];
		last[cards[i]]=i;
	}
	/*
	for(int i=1;i<=n;i++)
		f(i);
	*/
	for(int i=n;i>=1;i--){
		//fa[i]=last[cards[i]]+1;
		c[last[cards[i]]+1].push_back(i);
	}
	dfs(n+1);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
