#include <bits/stdc++.h>
typedef long long ll;
using namespace std; 
ll a[2000005],f[2000005],n,d,ct;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		ll ct=0;
		for(int i=3;i<n;i++){
			ll t1=lower_bound(a+1,a+n+1,a[i]-d)-a;
			ll t2=upper_bound(a+1,a+n+1,a[i-1]+d)-a-1;
			bool flag=0;
			if(t1==i-2&&t2==i+1) flag=1;
			else if(t1==i-2) flag=(a[t2]-a[i+1]>d);
			else if(t2==i+1) flag=(a[i-2]-a[t1]>d);
			else flag=(a[t2]-a[i+1]>d&&a[i-2]-a[t1]>d);
			if(flag) ct+=(i-t1-1)*(t2-i);
		}
		cout<<ct<<'\n';
	}
}
