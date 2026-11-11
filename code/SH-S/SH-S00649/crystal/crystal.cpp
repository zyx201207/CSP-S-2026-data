#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll a[n];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll md=a[n/2];
	ll mdx=n/2;
	ll cnt=0;
	for(ll i=0;m>0;i++){
		for(ll j=a[mdx-i];j<=md;j++)m--;
		cnt++;
	}
	for(ll i=mdx+1;i<n;i++){
		if(a[i]==md)cnt++;
	}
	cout<<cnt;
	return 0;
} 
