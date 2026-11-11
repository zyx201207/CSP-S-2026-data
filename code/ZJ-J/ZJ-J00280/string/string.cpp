#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,m,k,ans;
ll a[N];
char c[N];
void solve(){
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	ll l=1,r=n;
	while(l<r&&l<=n&&r>=1){
		if(c[l]==c[r]){
			if(a[l]<a[r]) a[r]-=a[l],++l;
			else if(a[l]>a[r]) a[l]-=a[r],--r;
			else ++l,--r;
		}else{
			if(a[l]<a[r]) ans+=a[l],a[r]-=a[l],++l;
			else if(a[l]>a[r]) ans+=a[r],a[l]-=a[r],--r;
			else ans+=a[l],++l,--r;
		}
	}
	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solve();
	return 0;
}
/*
aabbc
abca
4212

aaaabbcaa
*/
