#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a[200020],sum,t,cnt,f,orv,l,r;
char c[200020],b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}
	ll l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			cnt+=min(a[l],a[r]);
			if(a[l]>a[r]){
				a[l]=a[l]-a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]=a[r]-a[l];
				l++;
			}else{
				r--;
				l++;
			}
		}else{
			if(a[l]>a[r]){
				a[l]=a[l]-a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]=a[r]-a[l];
				l++;
			}else{
				r--;
				l++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
