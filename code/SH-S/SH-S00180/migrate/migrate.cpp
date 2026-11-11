#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//ios:sync_with_stdio(false);
	cin.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		ll n,d,cnt=0;
		cin>>n>>d;
		ll x[10009],dp[10009];
		for(ll i=1;i<=n;i++){
			cin>>x[i];
		}
		dp[1]=1;
		dp[2]=1;
		dp[3]=1;
		for(ll i=4;i<=n;i++){
			for(ll j=i-1;j>=1;j--){
				if(x[i]-x[j]>d){
					break;
				}
				dp[i]+=dp[j];	
			}
			if(dp[i]==2) cnt++;
			dp[i]=1;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
