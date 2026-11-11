#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010];
ll ans,mx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll j=0;
	for(ll i=0;i<n;i++){
		while(j<n&&a[j]*(j-i)-ans<=m){
			ans+=a[j];
			j++;
		}
		mx=max(mx,j-i);
		ans-=a[i];
	}
	cout<<mx;
	return 0;
} 
