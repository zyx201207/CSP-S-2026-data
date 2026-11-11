#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ma=1;
	
	for(ll i=n;i>=2;i--){
		ll num=m;
		ll l=i-1;
		ll sum=1;
		while(a[i]<=a[l]+num){
			num=num-a[i]+a[l];
			sum++;
			if(l-1<=0){
				break;
			}
			l--;
		}
		ma=max(sum,ma);
	}
	
	cout<<ma;
	return 0;
}