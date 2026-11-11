#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],p[100006],l,r;
bool check(int x){
	for(long long i=1;i<=(n-x+1);i++){
		long long sum=a[i+x-1]*x;
		if((sum-p[i+x-1]+p[i-1])<=m)return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(),cout.tie();
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
	}
	l=2,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(!check(mid))r=mid-1;
		else l=mid+1;
	}
	cout<<l-1;
	return 0;
}
