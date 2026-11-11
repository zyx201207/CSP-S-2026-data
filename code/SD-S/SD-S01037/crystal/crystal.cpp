#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r;
bool check(long long x){
	long long t=0;
	for(int i=1;i<=x;i++) t+=(a[x]-a[i]);
	if(t<=m) return true;
	for(int i=x+1;i<=n;i++){
		t=t-(a[i-1]-a[i-x])+(x-1)*(a[i]-a[i-1]);
		if(t<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	r=n;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(check(mid)) l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
