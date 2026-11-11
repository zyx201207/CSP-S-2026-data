#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll m,n,ans,dp[200005][2];
vector<ll> a;
bool use[200005];
void dfs(ll f,ll num){
	if(f==m){
		ans=max(ans,num);
		return;
	}
	for(size_t i=1;i<=n;i++){
		if(!use[i]){
			use[i]=true;
//			cout<<(a[i]&num)<<' '<<a[i]<<endl;
			dfs(f+1,a[i]&num);
			use[i]=false;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(size_t i=1;i<=n;i++){
		ll in;
		cin>>in;
		a.push_back(in);
	}
	for(size_t i=1;i<=n;i++){
		use[i]=true;
		dfs(1,a[i]);
		use[i]=false;
	}
//	for(size_t i=1;i<=n;i++){
//		
//	}
	cout<<ans;
	return 0;
}
