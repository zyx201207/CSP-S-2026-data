#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const ll N=5e5+5;
ll n,m,cnt,f,ans,a[N],s[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]&&i>=2&&i!=n){
			f=1;
		}
	}
	cnt=m;
	if(f==0){
		ans=n;
		f=a[2]-a[1];
		for(ll i=n;i>=1;i--){
			if(cnt-(a[n]-a[i])<0){
				ans=n-i;
				break;
			}
			cnt-=a[n]-a[i];
		}
		cout<<ans;
		return 0;
	}
	for(ll k=1;k<=n;k++){
		ll x=1;
		cnt=m;
		x=k;
		for(ll i=k-1;i>=1;i--){
			if(cnt-(a[k]-a[i])<0){
				x=k-i;
				break;
			}
			cnt-=a[k]-a[i];
		}
		ans=max(ans,x);
	}
	cout<<ans;
	return 0;
}