#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+1;
ll a[N],d[N],flag=0,flag2=0; 
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	ll n,m,k=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]!=i) {
			flag=1;
		}
		if(i==1) {
			continue;
		}
		else if(i==2) {
			k = a[2]-a[1];
		}
		else if(k!=(a[i]-a[i-1])){
			flag2=1;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) {
		d[i] = d[i-1]+a[i];
	}
	if(flag==0) {
		if((ll)sqrt((double)(2*m))*((ll)sqrt((double)(2*m))+1)<=2*m) {
			cout<<(ll)sqrt(2*m)+1;
		}
		else {
			cout<<(ll)sqrt(2*m);
		}
	}
	else if(flag2==0){
		ll w = 2*m/k;		
		if((ll)sqrt((double)(w))*((ll)sqrt((double)(w))+1)<=w) {
			cout<<(ll)sqrt(w)+1;
		}
		else {
			cout<<(ll)sqrt(w);
		}
	}
	else {
		for(int i=n; i>=2; i--) {
			for(int j=1; j<=n-i+1; j++) {
				if(a[j+i-1]*i<=d[j+i-1]-d[j-1]+m) {
					cout<<i;
					return 0;
				}
			}
		}
		cout<<1;
	}
	return 0;
} 
