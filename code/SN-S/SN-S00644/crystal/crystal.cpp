#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],c[500005],r=1,mx,sum; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<n;i++)c[i]=a[i+1]-a[i];
	sum=c[1];
	for(ll l=1;l<n&&r<n;l++){
		if(r<l){
			r++;
			sum+=(r-l+1)*c[r]; 
		}
		sum-=c[l-1];
		sum-=a[r]-a[l];
		while(sum<=m){
			r++;
			sum+=(r-l+1)*c[r]; 
			if(r>=n){
				r--;
				break;
			}
		}
		if(sum>m){
			sum-=(r-l+1)*c[r]; 
			r--;
		}
		mx=max(mx,r-l+2);
	}
	cout<<mx<<"\n";
	return 0;
}
