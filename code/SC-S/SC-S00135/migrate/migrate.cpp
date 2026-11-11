#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int N=5e3+5;
ll n,m;
void slove(){
	ll f=0,ans=0;
	vector<ll> a;
	a.push_back(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
	}
	
	for(ll i=1;i<a.size();i++){
		
		pair<ll,ll> dp[a.size()+1]={};
		dp[i].first=1;dp[i].second=0;
		
		for(ll j=i+1;j<a.size();j++){
			for(ll k=1;k<=m&&j-k>=i;k++){
				if(dp[j-k].second+1<dp[j].second||(dp[j].second==0&&a[j]-a[j-k]<=m)){
					dp[j].second=dp[j-k].second+1;
					dp[j].first=1;
				}else if(dp[j].second==dp[j-k].second+1)dp[j].first++;
				if(dp[j].first==0)break;
			}
			if(dp[j].first==2){	
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int q,t;
	cin>>q>>t;
	while(t--){
		slove();
	}
	return 0;
} 
