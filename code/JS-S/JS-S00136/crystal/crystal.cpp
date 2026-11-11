#include <bits/stdc++.h>
using namespace std;
long long n,m,ans;
long long a[5100000];
bool check(long long mid){
	long long vis=0;
	for(long long i=1;i<mid;i++){
		vis+=(a[mid]-a[i]);
		if(vis>m)return false;
	}
	if(vis>m)return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1,r=n,mid;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	for(long long i=1;i<=l;i++)ans++;
	cout<<ans;
	return 0;
}
