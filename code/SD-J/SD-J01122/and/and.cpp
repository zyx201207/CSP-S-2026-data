#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf=0x3f3f3f3f;
const i64 INF=0x3f3f3f3f3f3f3f3f;
const int N=2e5+5;
int n,m;
int a[N];
int ans=-inf;
void dfs(int dep,int cnt,int sum){
	if(dep==n+1||cnt>=m){
		if(cnt==m){
			ans=max(ans,sum);
		}
		return ;
	}
	dfs(dep+1,cnt+1,sum&a[dep]);
	dfs(dep+1,cnt,sum);
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0,inf);
	cout<<ans;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}
