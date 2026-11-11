#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
const int N=1e6+10,M=5e3+10,MOD=1e9+7;
ll n,d,fast[M][M],c,t,a[M],cnt=0;
void pan(ll i,ll j,ll x,ll yi){
	if(x==j&&yi==fast[i][j]){
		cnt++;
		return;
	}
	if(yi+fast[x][j]>fast[i][j]) return;
	ll r=upper_bound(a+x+1,a+j+1,a[x]+d)-a-1;
	for(ll tx=x+1;tx<=r;tx++){
		pan(i,j,tx,yi+1);
	}
}
int main(){
	fastio;
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			for(ll j=1;j<=n;j++){
				fast[i][j]=LLONG_MAX;
			}
		}
		for(ll len=1;len<=n;len++){
			for(ll i=1;i+len-1<=n;i++){
				ll j=i+len-1;
				if(a[j]-a[i]<=d) fast[i][j]=1;
				for(ll k=i+1;k<j;k++){
					fast[i][j]=min(fast[i][j],fast[i][k]+fast[k+1][j]);
				}
			}
		}
		for(ll i=1;i<=n;i++) fast[i][i]=0;
		ll ans=0;
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				pan(i,j,i,0);
				if(cnt==2) ans++;
				cnt=0;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
