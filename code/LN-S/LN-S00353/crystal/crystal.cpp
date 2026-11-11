#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=500005;
ll n,m,a[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5000){
		int mx=INT_MIN;
		for(int i=1;i<=n;i++){
			int ans=1;
			int m1=m;
			for(int j=i-1;j>=1;j--){
				if(m1>=a[i]-a[j]){
					ans++;
					m1-=(a[i]-a[j]);
				}else{
					continue;
				}
			}
			mx=max(mx,ans);
		}
		cout<<mx;
		return 0;
	}else{
		ll d=(a[n]-a[1])/(n-1),ans;
		for(int i=1;i<=n;i++){
			ans=i;
			ll xs=(a[i]-a[1])/d+1;
			if((a[i]+a[1])*xs/2>m) break;
		}
		cout<<ans;
	}
	return 0;
}
