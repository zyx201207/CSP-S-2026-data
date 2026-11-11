#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n>5000){
		ll d=a[2]-a[1];
		ans=1;
		for(ll i=1;i<=n;i++){
			ll x=((1+i)*i)*d/2;
			if(x>m){
				cout<<ans;
				break ;
			}else ans++;
		}
		return 0;
	}
	for(ll i=2;i<=n;i++){
		ll cnt=m,sum=1;
		for(ll j=i-1;j>=1;j--){
			if(cnt-a[i]+a[j]>=0){
				cnt=cnt-a[i]+a[j];
				sum++;
			}else continue ;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
