#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll a[500003];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	bool c=1;
	int x=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=x){
			c=0;
			break;
		}
	}
	if(n*n<=30000000){
		ll ans=1;
		for(int i=2;i<=n;i++){
			ll mm=0,ansm=1;
			for(int j=i-1;j>=1;j--){
				if(mm+a[i]-a[j]<=m)mm+=(a[i]-a[j]),ansm++;
				else break;
			}
			ans=max(ans,ansm);
		}
		cout<<ans;
	}
	else if(c){
		ll mm=0,ansm=1;
		for(int j=n-1;j>=1;j--){
			if(mm+a[n]-a[j]<=m)mm+=(a[n]-a[j]),ansm++;
			else break;
		}
		cout<<ansm;
	}
	else{
		ll ans=1;
		for(int i=n;i>=2;i--){
			ll mm=0,ansm=1;
			for(int j=i-1;j>=1;j--){
				if(mm+a[i]-a[j]<=m)mm+=(a[i]-a[j]),ansm++;
				else break;
			}
			ans=max(ans,ansm);
			if(ans>=i-1)break;
		}
		cout<<ans;
	}
	return 0;
}
