#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
#define int long long 
int n,m;
int a[MAXN];
int dp[MAXN];
int f(int x){
	int len=m;
	int i=x-1;
	int ans=1;
	while((a[x]-a[i])<=len&&i>=1){
		len-=(a[x]-a[i]);
		ans++;
		i--;
	}
	return ans;
}
int solve(){
	int ans=-1;
	for(int i=2;i<=n;i++){
		ans=max(ans,f(i));
	}
	return ans;
}
signed main(void){
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<solve();	
	return 0;
}