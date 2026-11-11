#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,a[500005]={(ll)(1e12)},ans=1;
ll n;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<10000){
		ll m1=m;
		for(ll i=1;i<=n;i++){
			ll k=1;
			m=m1;
			for(ll j=i-1;j>0&&m>=0;j--){
				m-=a[i],m+=a[j];
				if(m<0)continue;
				k++;
			}
			ans=max(ans,k);
		}
		cout<<ans;
	}else{
		for(ll i=1;i<=n&&m>=0;i++,ans++){
			a[i]=a[i]+a[i-1];
			m-=a[i];
		}
		cout<<ans;
	}
	return 0;//10 23 2 6 8 4 16 12 18 10 14 20
}
