#include<bits/stdc++.h>
using namespace std;
long long n,m,ma=-1e18;
long long a[500005],s[500005];
bool check(long long t){
	for(long long i=1;i+t-1<=n;i++){
		long long j=i+t-1;
		long long sum=t*a[j]-(s[j]-s[i-1])-m;
		if(sum<=0){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l-r)/2+r;
		if(check(mid)==1){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<l-1;
	return 0;
}  