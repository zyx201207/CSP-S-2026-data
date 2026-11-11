#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
int a[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[1]=0;
	ll ans=0;
	ll l=1;
	for(ll i=2;i<=n;i++){
		while(c[i-1]+(i-l)*(a[i]-a[i-1])>m){
			c[i-1]-=(a[i-1]-a[l]);
			l++;
		}
		c[i]=c[i-1]+(i-l)*(a[i]-a[i-1]);
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}