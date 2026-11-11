#include<bits/stdc++.h>
using namespace std;

int n,m;
long long a[200005],ans;
void dfs(int tot,long long zhi,int s){
	if(s==m){
		ans=max(ans,zhi);
		return;
	}
	for(int i=tot; i<=n-m+1+s; i++){
		dfs(i+1,zhi&a[i],s+1);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n-m+1; i++){
		dfs(i+1,a[i],1);
	}
	cout<<ans;
	return 0;
}
