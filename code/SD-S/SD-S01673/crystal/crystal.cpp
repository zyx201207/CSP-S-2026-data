#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5000){
		for(ll i=1;i<=n;i++){
			ll sum=0,x=0;
			for(int j=1;j<=n;j++){
				if(i==j||a[i]<a[j])continue;
				if(sum+a[i]-a[j]>m)break;
				sum+=a[i]-a[j];x++;
			}
			ans=max(ans,x+1);
		}
		cout<<ans;
		return 0;
	}else{
		bool f1=1,f2=1,f3=1;
		for(ll i=1;i<=n;i++){
			if(abs(a[i])>100)f1=0;
			if(a[i]!=i)f2=0;
			if(i>=3&&abs(a[i]-a[i-1])!=abs(a[i-1]-a[i-2]))f3=0;
		}
		if(f1){
			for(ll i=-100;i<=100;i++){
				ll sum=0,x=0;
				for(ll j=min(upper_bound(a+1,a+1+n,i)-a,n);j>=1;j--){
					if(sum+i-a[j]>m)break;
					sum+=i-a[j];x++;
				}
				ans=max(ans,x-1);
			}
			cout<<ans;
			return 0;
		}
		if(f2){
			ll l=0;
			for(;l*(l+1)/2<=m;l++);
			cout<<l;
			return 0;
		}
		if(f3){
			ll sum=0;
			for(ll i=2;i<=n;i++){
				if(sum+(i-1)*abs(a[i]-a[i-1])>m){cout<<i-1;return 0;}
				sum+=(i-1)*abs(a[i]-a[i-1]);
			}cout<<n;
			return 0;
		}
	}
	return 0;
}
