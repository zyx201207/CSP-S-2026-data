#include <bits/stdc++.h>
using namespace std;
long long n,m,a[511111],p[511111],q[511111],s[511111];
int check(long long mid){
	long long cnt=q[mid-1];
	for(int i=1;i<=n-mid;i++){

		if(m>=cnt) return 1;
		cnt=cnt-s[i+mid-2]+s[i-1]+(mid-1)*p[i+mid-1];
		
	}
	return 0;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++){
		p[i]=a[i+1]-a[i];
		q[i]=q[i-1]+i*p[i];
		s[i]=s[i-1]+p[i];

	}	
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r+1)/2;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
