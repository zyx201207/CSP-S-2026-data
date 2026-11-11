#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll m;
ll a[500010];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	bool fa=true,fb=true,fd=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=i)fa=false;
		if(i!=1){
			if(a[i]!=a[i-1])fd=false;
		}
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])fb=false;
		}
	}
	if(fd){
		cout<<n;
		return 0;
	}
	if(fa){
		ll x=(2+sqrt(4+8*m))/2;
		for(ll i=x;;i--){
			if(i*i+2*i<=4*m){
				cout<<i;
				return 0;
			}
		}
	}
	if(fb){
		ll cha=a[2]-a[1];
		ll x=(-a[1]+sqrt(a[1]*a[1]-4*cha*(a[1]-4*m)))/(2*cha);
		for(ll i=x;;i--){
			if(i*i+2*i<=4*m){
				cout<<i;
				return 0;
			}
		}
	}
	ll cha=a[2]-a[1];
	ll x=(-a[1]+sqrt(a[1]*a[1]-4*cha*(a[1]-4*m)))/(2*cha);
	for(ll i=x;;i--){
		if(i*i+2*i<=4*m){
			cout<<i;
			return 0;
		}
	}
}

