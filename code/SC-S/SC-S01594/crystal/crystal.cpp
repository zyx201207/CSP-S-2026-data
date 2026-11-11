#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+5;
ll a[N];	
ll n,m;
ll ans=0;
bool check(ll mid){
	ll sum=0;
	for (int i=1;i<=mid;i++){
		sum+=a[mid]-a[i];
	}
	if (sum<=m) return true;
	else return false; 
}
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,r=n;
	while (l<=r){
		ll mid=(l+r)/2;
		if (check(mid)){
			ans=mid;
			l=mid+1;
		}else {
			r=mid-1;
		}
	}
	cout <<ans;
}
