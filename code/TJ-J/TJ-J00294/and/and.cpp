#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200001];
int ans;
void dfs(int i,int cnt,int x){
	if(cnt==m){
		ans=max(x,ans);
		return;
    }
	for(int j=i+1;j<=n;++j){
		dfs(j,cnt+1,x&a[j]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n-m;++i) dfs(i,1,a[i]);
    cout<<ans;
	return 0;
}
