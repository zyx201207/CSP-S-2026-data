#include <bits/stdc++.h>
using namespace std;
int n,m,a[214514],dp[214514];
int ans=0,x=0;
void dfs(int k,int hv,int lst){
	if(lst==0){
		ans=max(ans,hv);
		return;
	}if(k>n) return;
	dfs(k+1,(hv&a[k]),lst-1);
	dfs(k+1,hv,lst);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}if(m==n-1){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}for(int i=1;i<=n;i++){
			x=max(x,ans&(~a[i]));
		}cout<<x;
		return 0;
	}
	dfs(1,0xffffffff,m);
	cout<<ans;
	return 0;
}
