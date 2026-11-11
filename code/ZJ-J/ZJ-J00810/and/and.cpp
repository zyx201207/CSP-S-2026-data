#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],ans;
bool vis[N];
void dfs(int k,int res){
	if(k>m){
		ans=max(ans,res);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(k+1,res&a[i]);
		vis[i]=0;
	}
}
bool cmp(int u,int v){
	return u>v;	
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool tb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)tb=0;
	}
	if(tb){
		sort(a+1,a+n+1,cmp);
		ans=(1<<30)-1;
		for(int i=1;i<=m;i++){
			ans=ans&a[i];
		}
	}
	else dfs(1,(1<<30)-1);
	cout<<ans;
	return 0;
}
