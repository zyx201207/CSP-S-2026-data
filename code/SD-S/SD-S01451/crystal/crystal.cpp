#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[600000],as,mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool fa=1,fb=1,f=1;
	ll w;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2){
			if(f){
				w=a[i]-a[i-1];
				f=0;
			}
			if(a[i]-a[i-1]!=w) fb=0;
		}
		if(a[i]!=i) fa=0;
	}
	sort(a+1,a+n+1);
	if(fa){
		ll ww=a[n];
		for(ll i=n-1;i>=1;i--){
			if(m-(ww-a[i])>=0){
				as++;
				m-=(ww-a[i]);
			}
		}
		cout<<as;
		return 0;
	}
	if(fb){
		ll ww=w;
		for(ll i=n-1;i>=1;i--){
			if(m-w>=0){
				as++;
				m-=w;
				w+=ww;
			}
		}
		cout<<as;
		return 0;
	}
	mx=0xc0c0c0c0c0c0c0c0;
	for(ll i=1;i<=n;i++){
		ll c=m,t=0;
		for(ll j=i;j>=1;j--){
			if(c-(a[i]-a[j])>=0){
				c-=(a[i]-a[j]);
				t++;
			}else break;
		}
		mx=max(mx,t);
	}
	cout<<mx;
	return 0;
}

