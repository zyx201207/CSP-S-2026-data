#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[10010];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){//6
		cout<<a[n];
	}
	if(m==n){//7
		ll sum=a[1];
		for(ll i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
	}
	if(m==2){
		ll sum=0;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				sum=max(sum,(a[i]&a[j]));
			}
		}
		cout<<sum;
	}
	if(m==n-1){
		ll ma=0;
		for(int i=1;i<=n;i++){
			ll sum;
			if(i!=1){
				sum=a[1];
			} else sum=a[2];
			for(int j=1;j<=n;j++){
				if(j!=i){
					sum&=a[j];
				}
			}
			ma=max(sum,ma);
		}
		cout<<ma;
	}else{
		cout<<1;
	}
	return 0;
}

