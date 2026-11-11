#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans;
ll a[10000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bool flag=1;
	int x=a[n]-a[n-1];
	for(int i=n;i>1;i--){
		if(a[i]-a[i-1]!=x){
			flag=0;
			break;
		}
	}
	ll cnt=1;
	if(flag){
		for(int i=n-1;i>=1;i--){
			if(a[n]-a[i]<=m){
				m-=(a[n]-a[i]);
				cnt++;
			}
			else{
				break;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=n;i>=1;i--){
		ll u=m;
		cnt=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=u){
				u-=(a[i]-a[j]);
				cnt++;
			}
			else{
				ans=max(ans,cnt);
				if(ans==n){
					cout<<ans;
					return 0;
				}
				break;
			}
		}
		ans=max(ans,cnt);
		if(ans==n){
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}