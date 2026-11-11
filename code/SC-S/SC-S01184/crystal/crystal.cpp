#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<n;i++){
		s[i]=a[i+1]-a[i];
	}
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+s[i]*i;
	}
	ll ans=0,cnt=2;
	for(ll i=1;i<n;i++){
		if(ans>n+1-i){
			break;
		}
		for(ll j=cnt;j<=n;j++){
			if(s[j-1]-s[i-1]-(a[j]-a[i])*(i-1)<=m){
				ans=max(ans,j+1-i);
			}
			else{
				cnt=j;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}