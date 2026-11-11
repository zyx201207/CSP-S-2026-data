#include"bits/stdc++.h"
#define ll long long
using namespace std;
ll n;
ll ans;
ll a[200010];
char c[200010];
int main(){
	//openfree~~~
	//openfree~~~
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else l++,r--;
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				ans+=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				ans+=a[l];
				l++;
			}else{
				ans+=a[l];
				l++,r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
