#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,n,m,a[200005],ans;
vector <bool> c[200005],b,dp[200005];
void an(ll x,ll y){
	b.clear();
	for(ll i=0;i<min(c[y].size(),dp[x].size());i++){
		if(dp[x][i]&&c[y][i]){
			b.push_back(1);
		}
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>x;
		ll j=1;
	   	while(x){
	    	c[i].push_back(x%2);
	   		x/=2;
       		j++;
    	}
	}
	dp[0]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	for(ll i=1;i<=n;i++){
		for(ll j=min(i,m);j>=1;j--){
			an(j-1,i);
			dp[j]=max(b,dp[j]);
		}
	}
	ll t=1;
	for(auto i:dp[m]){
		ans+=i*t;
		t*=2;
	}
	cout<<ans;
	return 0;
}
