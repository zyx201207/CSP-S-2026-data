#include <bits/stdc++.h>//这是我代码 
using namespace std;//这是我代码
typedef long long ll;//这是我代码
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	ll mx=0;
	cin>>n>>m;
	ll a[n+1];
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll a1[n+1];
	for(ll i=2;i<=n;i++){
		a1[i-1]=a[i]-a[i-1];
	}
	for(ll i=1;i<=n;i++){
		ll t=0,y=0;
		while(1){
			t++;
			y+=a1[t]*t;
			if(m<y){
				break;
			}else if(t>=n)break;
		}
		mx=max(mx,t);
	}
	cout<<mx;
	return 0;
}
