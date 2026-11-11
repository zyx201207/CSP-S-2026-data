#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
bool check(long long x){
	long long k=0;
	for(int i=1;i<=x;i++) k+=a[x]-a[i];
	if(k<=m) return true;
	for(int i=x+1;i<=n;i++){
		k=k-a[i-1]+a[i-x]+(a[i]-a[i-1])*(x-1);
		if(k<=m) return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	long long l=1,r=n,ans=0;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
//			ans=max(ans,l);
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}  
