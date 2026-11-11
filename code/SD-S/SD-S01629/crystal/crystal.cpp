#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,arr[500010],pre[500010],prefix[500010],ans=-1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>arr[i];
	}
	sort(arr+1,arr+1+n);
	for(int i=1; i<=n-1; i++) {
		pre[i]=arr[i+1]-arr[i];
	}
	for(int i=n-1; i>=1; i--) {
		prefix[i]=pre[i]+prefix[i+1];
	}
	/*for(int i=1; i<=n; i++) {
		cout<<pre[i]<<" ";
	}cout<<endl;
	for(int i=1; i<=n; i++) {
		cout<<prefix[i]<<" ";
	}cout<<endl;*/ 
	for(int i=1; i<=n; i++) {
		//cout<<"i="<<i<<" "<<endl;
		ll l=0,r=i;
		while(l+1<r) {
			ll midd=l+r;
			midd/=2;
			//cout<<" "<<l<<" "<<prefix[l]<<" "<<r<<" "<<prefix[r]<<" "<<midd<<" "<<prefix[midd]<<" "<<prefix[midd]-prefix[i]<<endl;
			if(prefix[midd]-prefix[i]>m)l=midd;
			else r=midd;
			//cout<<l<<" "<<r<<endl;
		}
		ans=max(ans,i-r+1);
		//cout<<endl;
	}
	cout<<ans;
	return 0;
}
