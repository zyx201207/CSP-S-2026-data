#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m;
ll a[N],b[N],c[N],d[N];
bool ok(ll len){
	for(int i=len;i<n;i++){
		if(d[i]-d[i-len]-len*(a[n]-a[len+1])<=m){
			return 1;
		}
	}
	return 0;
}
ll search(){
	ll mid,l=1,r=n-1,ans=0;
	while(l<=r){
		mid=(l+r)/2;
		if(ok(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=n-1;i>=1;i--){
		c[i]=c[i+1]+b[i];
	}
	for(int i=1;i<n;i++){
		d[i]=d[i-1]+c[i];
	}
	cout<<search()+1;
	return 0;
} 
