#include<bits/stdc++.h>
#define ll long long
const int N=5e5+5;
using namespace std;
ll n,m,l,r,mid,ans,a[N];
bool count(ll x){
	ll L=1,R=x,num=0;
	for(ll i=1;i<=x;i++){
		num+=a[x]-a[i];
	}
	if(num<=m) return 1;
	while(R<n){
		L++,R++;
		num-=a[R-1]-a[L-1];
		num+=(a[R]-a[R-1])*x;
		if(num<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	r=n;
	sort(a+1,a+n+1);
	while(l<=r){
		mid=(l+r)>>1;
		if(count(mid)){
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
