#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n;
	long long m;
	cin>>n>>m;
	ll a[500005]={},b[500005]={};
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	ll l,r,ans=0;
	l=a[0];
	r=a[n-1];
	while(l<=r){
		ll mid=(l+r)/2,maxi=0;
		long long k=0;
		for(int i=0;i<n;i++)b[i]=mid-a[i];
		sort(b,b+n);
		for(int i=0;i<n;i++){
			if(b[i]>=0){
				maxi++;
				k+=b[i];
			}
			if(k>m){
				maxi--;
				break;
			}
			if(k==m)break;
		}
		if(k>m)r=mid-1;
		else l=mid+1;
		ans=max(ans,maxi);
	}
	cout<<ans;
	return 0;
}
