#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
bool check(long long x){
	long long s=0;
	for(int i=1;a[i]<=x;i++){
		s+=x-a[i];
	}
	return s<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=a[1],r=a[n];
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	for(int i=1;;i++){
		if(a[i]>ans){
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}
