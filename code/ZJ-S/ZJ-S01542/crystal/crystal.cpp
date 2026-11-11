#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll n,m,a[1000000],b[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(ll i=0;i<n;i++){
		ll h=0;
		for(ll j=0;j<i;j++){
			h+=a[i]-a[j];
		}
		b[i]=h;
		if(b[i]>m){
			cout<<i;
			break;
		}
	}
	return 0;
}  