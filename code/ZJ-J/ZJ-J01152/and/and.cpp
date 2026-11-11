#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n,m,mx,a[N],vis[N];
bool s[N][32];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	for(ll i=1;i<=n;i++){
		for(ll j=30;j>=1;j--){
			s[i][j]=a[i]%2;
			a[i]/=2;
		}
	}
	ll ans=0;
	for(ll i=1;i<=30;i++){
		ll cnt=0;
		for(ll j=1;j<=n;j++){
			if(s[j][i]&&!vis[j]){
				cnt++;
			}
		}
		if(cnt>=m){
			ans+=(1<<(30-i));
			for(ll j=1;j<=n;j++){
				if(!s[j][i]&&!vis[j]){
					vis[j]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
