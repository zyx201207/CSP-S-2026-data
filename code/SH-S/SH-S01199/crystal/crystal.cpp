#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(int i=a[1]+1;;i++){
		ll x=0;
		ll cnt=0;
		for(int j=1;a[j]<=i;j++){
			x+=i-a[j];
			a[j]++;
			cnt++;
		}
		if(m>=x){
			if(i>=a[n]){
				cout<<n;
				return 0;
			}
			m-=x;
			ans=max(ans,cnt);
		}else{
			ans=max(ans,m);
			break;
		}
	}
	cout<<ans;
}
