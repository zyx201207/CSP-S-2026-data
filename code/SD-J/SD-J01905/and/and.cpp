#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200000+5],ans=INT_MIN,vis[200000+5];
long long dfs(long long step,long long x){
	if(step==m){
		ans=max(ans,x);
		return ans;
	}
	for(long long i=1;i<=n;i++){
		if(vis[i]==1){
			continue;
		}
		vis[i]=1;
		dfs(step+1,x&a[i]);
		vis[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		vis[i]=1;
		ans=max(ans,dfs(1,a[i]));
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
