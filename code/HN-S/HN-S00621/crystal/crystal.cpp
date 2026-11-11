#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+5;
ll n,m,a[N],ans=1,f[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
//		cout<<f[i]<<" ";
	}
	for(ll i=0;i<=n;i++){
		ll l=0,r=n;
		while(l<r){
			ll mid=l+r+1>>1;
//			cout<<l<<" "<<r<<" "<<mid<<"\n"; 
//			cout<<m<<" "<<abs(f[mid]-f[i])<<" "<<abs((mid-i)*a[mid])<<"\n\n";
			if(m+f[mid]-f[i]>=abs((mid-i)*a[mid]))l=mid;
			else r=mid-1;
		}
//		if(l>=i){
//			cout<<l<<" "<<i<<" "<<f[l]<<" "<<m+abs(f[l]-f[i])<<" "<<abs((l-i)*a[l])<<"\n\n"; 
			ans=max(ans,l-i);	
//		}
	}
	cout<<ans;
	return 0;
}
