#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m;
ll a[N];
bool check(int mid){
	bool f=0;
	ll sum=0;
	int l=n-mid+1,r=n;
	for(int i=l;i<=r;i++) sum+=a[r]-a[i];
	if(sum<=m) f=1;
	l--;r--;
	for(;l>=1;l--,r--){
		sum+=a[r+1]-a[l]-(a[r+1]-a[r])*mid;
		if(sum<=m) f=1;
	}
	return f;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
