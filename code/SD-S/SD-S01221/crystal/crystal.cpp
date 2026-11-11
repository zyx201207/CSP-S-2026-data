#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
	sort(a+1,a+1+n);
	ll mx=-1e18;
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		ll p=i*a[i];
		if(p-s[i]>m){
			ll l=1,r=i;
			while(l<=r){
				ll mid=(l+r)/2;
				ll len=i-mid+1;
				if(a[i]*len-(s[i]-s[mid-1])<=m){
					r=mid-1;
				}else l=mid+1;
			}
			mx=max(mx,i-l+1);			
		}else{
			mx=max(mx,i);
		}
	}
	cout<<mx<<'\n';
	return 0;
}
//gey666
