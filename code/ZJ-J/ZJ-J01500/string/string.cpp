#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a[200010];
char op[200010];
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i]>>op[i];
	ll l,r;
	l=1,r=n;
	while(l<=r){
		if(op[l]!=op[r]){
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				a[l]-=a[r];
				r--;
			}
		}
	}cout<<ans;
	return 0;
}