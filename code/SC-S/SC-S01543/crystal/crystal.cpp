#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50000005],ans=INT_MIN;
bool check(long long x){
	long long cnt=INT_MAX;
	for(long long i=1;i<=n-x+1;i++){
		long long t=0;
		for(long long j=i+x-2;j>=i;j--){
			t+=a[i+x-1]-a[j];
		}
		cnt=min(t,cnt);
	}
	if(cnt>m) return 0;
	else return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	long long l=1,r=n,mid;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans<<endl;
	return 0;
}