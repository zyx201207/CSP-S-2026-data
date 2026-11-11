#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll n,m;
ll mx=-inf;
ll a[N];
ll ma=-inf,mn=inf;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>ma) ma=a[i];
		if(a[i]<mn) mn=a[i];
	}
	if((ma-mn)*n<=m){
		cout<<m;
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		ll ans=0;
		if(mx>i){
			cout<<mx;
			return 0;
		}
	    for(int j=i-1;j>=1;j--){
			if(ans+(a[i]-a[j])<=m){
				ans+=(a[i]-a[j]);
				if(i-j+1>mx) mx=i-j+1;
			}else break;
		 }
	}
	cout<<mx;
	return 0;
} 
