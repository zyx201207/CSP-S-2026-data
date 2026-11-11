#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=5e5+1000;
int n;
ll m,a[N],b[N],c[N],d[N];
ll ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
		b[i]=b[i-1]+(i-1)*c[i];
	}
	ll l,r;
	for(int i=2;i<=n;i++){
		l=0,r=i;
		while(l<=r){
			ll mid=(r+l)/2;
			if(b[i]-mid*(a[i]-a[mid+1])-b[mid+1]<=m){
				ans=max(ans,i*1LL-mid);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		
	}
	cout<<ans;
	return 0;
}

