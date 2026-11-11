#include <bits/stdc++.h>

using namespace std;
#define ll long long
const ll MAXN=5e5+5;
ll n,m,mx=0,t=0,a[MAXN],L=0,R,mid;
bool f(ll x){
	for(int i=x;i<=n;i++){
		ll s=0;
		for(int j=i-x+1;j<i;j++){
			s+=a[i]-a[j];
		}
		if(s<=m){
			return true;
		}
	}
	return false;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	R=n;
	while(L<R){
		mid=(L+R+1)>>1;
		if(f(mid)){
			L=mid;
		}else{
			R=mid-1;
		}
	}
	cout<<L;
	return 0;
}
