#include <bits/stdc++.h>
using namespace std;
#define ll long long 
ll c,t;
long long n,d,a[1000100];
struct f{
	ll leng;
	ll cnt;
}dp[5050][5050];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			ll ans=0;
			cin>>n>>d;
			for(long long i=1;i<=n;i++){
			cin>>a[i];
			}
			for(ll i=n;i>=1;i--)
			a[i]-=a[i-1];
			ll x=a[2];
			ll k=d/x;
			k=k*2-1;
			cout<<max(int(n-k),0)<<endl;
		}
		return 0;
	}
	while(t--){
		ll ans=0;
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++)
			dp[i][j].leng=n;
		}
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		for(ll i=n;i>=1;i--)
		a[i]-=a[i-1];
		for(ll i=1;i<=n;i++)
		a[i]=a[i-1]+a[i];
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					dp[i][j]={1,1};
				}
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				for(ll w=j+1;w<=n;w++){
					if(dp[i][w].leng==dp[i][j].leng+dp[j][w].leng)
					dp[i][w].cnt+=1;
					if(dp[i][w].leng>dp[i][j].leng+dp[j][w].leng)
					dp[i][w]={dp[i][j].leng+dp[j][w].leng,1};
				}
			}
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(dp[i][j].cnt==2)
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
