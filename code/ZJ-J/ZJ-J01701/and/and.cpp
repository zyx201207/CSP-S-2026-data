#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[200005];
ll n,m,sum;
ll a[200005];
void dfs(ll p,ll q){
	if(q==m){
		sum=max(sum,p);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(dp[i]!=1){
			dp[i]=1;
			dfs(p&a[i],q+1);
		}
	}
}
int main(){
	freopen("add.in","r",stdin);
    freopen("add.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i]=1;
		dfs(a[i],1);
		for(int i=1;i<=n;i++){
			dp[i]=0;
		}
	}
	cout<<sum;
	return 0;
}