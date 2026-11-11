#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,sum,s,a[N];
bool f1=1,f2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	ll t=a[2]-a[1];
	for(ll i=n;i>=1;i--){
		if(a[i]!=i) f1=0;
		if(a[i+1]-a[i]!=t&&i!=n) f2=0;
		sum+=a[n]-a[i];
	}
	if(m>=sum){
		cout<<n;
		return 0;
	}
	if(n==1){
		cout<<1;
		return 0;
	}
	if(f1){
		int ans;
		for(ll i=1;i<n;i++){
			s+=i;
			if(s>m){
				cout<<i;
				return 0;
			}
			if(s==m){
				cout<<i+1;
				return 0;
			}
			ans=i;
		}
		cout<<ans;
		return 0;
	}
	if(f2){
		int ans;
		for(ll i=1;i<n;i++){
			s+=a[n]-a[n-i+1];
			if(s>m){
				cout<<i-1;
				return 0;
			}
			if(s==m){
				cout<<i;
				return 0;
			}
			ans=i;
		}
		cout<<ans;
		return 0;
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
