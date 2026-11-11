#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ll n,m;
	cin>>n>>m;
	for (ll i=1;i<=n;i++)cin>>a[i];
	if (m==1){
		ll maxn=0;
		for (ll i=1;i<=n;i++)maxn=max(maxn,a[i]);
		cout<<maxn;
	}else if(m==2){
		ll maxn=0;
		for (ll i=1;i<=n;i++){
			for (ll j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
	}else if(m==n-1){
		for (ll i=1;i<=n;i++)a[i]&=a[i-1];
		ll maxn=0;
		for (ll i=1;i<=n;i++){
			maxn=maxn(maxn,(a[n]|a[i]));
		}
		cout<<maxn;
	}else{
		cout<<0;
	}
	return 0;
} 
