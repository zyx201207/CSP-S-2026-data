#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int vis[N];
long long dfs(int idx,int cnt,int ans){
	if(cnt==m){
		return ans;
	}
	if(ans==0)return 0;
	long long res=0;
	vis[idx]=1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			res=max(dfs(i,cnt+1,ans&a[i]),res);
		}
	}
	vis[idx]=0;
	return res;
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dfs(i,1,a[i]));
	}
	cout<<ans;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	return 0;
}
