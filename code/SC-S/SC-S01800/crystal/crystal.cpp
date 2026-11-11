#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500002],s[500002];
bool check(long long x){
	for(int i=x;i<=n;++i){
		if(a[i]*x-(s[i]-s[i-x])<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<l-1;
	return 0;
} 