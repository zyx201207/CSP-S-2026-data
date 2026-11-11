#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
#define ll long long
ll n,m;
int a[N];
int check_n(ll x){
	ll co=0;
	for(int i=0;i<n;i++){
		if(a[i]<x){
			co+=x-a[i];
		}
	}
	return co;
}
int check(ll x){
	ll op=0;
	for(int i=0;i<n;i++){
		if(a[i]<=x){
			op++;	}
	}
	return op;
}
int main() {
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll l=a[0],r=a[n-1],mid;
	while(l<r-1){
		mid=(l+r)/2;
		if(check_n(mid)<=m){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<check(mid);
	return 0;
}
