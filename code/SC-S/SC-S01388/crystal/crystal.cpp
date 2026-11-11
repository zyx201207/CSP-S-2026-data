#include<bits/stdc++.h>
#define frein(x) freopen(x".in","r",stdin)
#define freout(x) freopen(x".out","w",stdout)
#define cinios cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
using ll=long long;
const int N=5e5+10;
ll a[N];
ll n,m;
void dencha(){
	sort(a+1,a+1+n);
	ll ans=0;
	ll cnt=m;
	for(int i=2;i<=n;i++){
		ll c=(a[i]-a[i-1])*(i-1);
		if(cnt-c>=0){
			cnt-=c;
			ans++;
		}
	}
	if(ans) cout<<ans+1;
	else cout<<ans;
}
int main(){
	frein("crystal");
	freout("crystal");
	cinios;
	cin>>n>>m;
	int x=0;
	int f1=1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i<=2) x=a[i]-a[i-1]; 
		if(x!=a[i]-a[i-1]) f1=0;
	}
	if(f1){
		dencha();
		return 0;
	}
	sort(a+1,a+1+n);
	ll ans=0;
	for(ll i=2;i<=n;i++){
		ll cnt=m;
		ll res=0;
		for(ll r=i;r<=n;r++){
			ll c=(a[r]-a[r-1])*(r-i+1);
			if(cnt-c>=0){
				res++;
				cnt-=c;
			}else break;
		}
		if(res) ans=max(ans,res+1);
	}
	cout<<ans;
	return 0;
}
