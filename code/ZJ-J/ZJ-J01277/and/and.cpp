#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
long long vis[200005];
void dfs(long long step,long long an){
	if(step==m){
		ans=max(an,ans);
		return ;
	}
	for(long long i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(step+1,an&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		vis[i]=1;
		dfs(1,a[i]);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
