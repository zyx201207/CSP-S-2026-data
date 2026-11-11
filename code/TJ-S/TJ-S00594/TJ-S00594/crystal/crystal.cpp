#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500010];
ll b[500010];
ll n,m;
int panduan(int y){
	ll ans=1;
	for(int i=y;i<n;i++){
		ll x=i*b[i];
		if(m>=x){
			m-=x;	
			ans++;
		}
		else if(i==1) {	
			return 0;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
	}
	ll mx=-1e8;
	for(int i=1;i<=n;i++){
		ll x=panduan(i);
		mx=max(mx,x);
	}
	cout<<mx;
	return 0;
}
