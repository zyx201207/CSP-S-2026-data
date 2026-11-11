#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000005],m,ans=2147483647,maxx=-0x7f7f7f7f;
bool vis[1000005];
void dfs(int step,int sum){
	if(step==m){
		maxx=max(maxx,sum);
		return ;
		for(int i=1;i<=n;i++){
			cout<<vis[i]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			dfs(step+1,(sum&a[i]));
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==m){
		for(int i=1;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
	if(n>2000){
		for(int i=n;i>n-m;i--){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	dfs(0,2147483647);
	cout<<maxx;
	return 0;
}
