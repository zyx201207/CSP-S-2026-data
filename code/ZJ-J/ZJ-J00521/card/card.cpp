#include<bits/stdc++.h>
using namespace std;
//#define fr(x) freopen(#x".in","r",stdin)
//#define fw(x) freopen(#x".out","w",stdout)
int n,m;
vector<int> vc[300005];
int vis[300005];
int a[500005];
int val[300005];
void dfs(int u){
	for(int v:vc[u]){
		dfs(v);
		val[u]+=val[v];
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		val[a[i]]++;
		if(!vis[a[i]]){
			vis[a[i]]=1;
			vc[a[i+1]].push_back(a[i]);
		}
	}
	dfs(a[n]);
	for(int i=1;i<=m-1;i++){
		cout<<val[i]<<' ';
	}
	cout<<val[m];
	return 0;
}
/*
CSP-J

8:32  open travel
10:36 AK.
*/
