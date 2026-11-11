#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
long long check(long long mid){
	long long cnt=0,t=0;
	for(long long i=1;i<=n;i++){
		cnt+=max(t,mid-a[i]);
	}
	return cnt;
}
long long f(long long l,long long r){
	if(!(l<=r))return l;
	long long mid=(l+r)/2;
	long long x=check(mid);
	if(x>m){
		return f(l,mid-1);
	}else if(x<m){
		return f(mid+1,r);
	}else return mid;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if((a[n]-a[n-1])==(a[n-1]-a[n-2])){
		long long j=1;
		if((a[n]-a[n-1])==1){
			for(long long i=1;i*(i+1)<=m;i++){
				j=i;
			}
			cout<<j+1;
			return 0;
		}
		long long len=a[n]-a[n-1];
		long long x=m/len;
		long long t=1;
		long long ans=0;
		while(x>=t){
			x-=t*len;
			t++;
			ans++;
		}
		cout<<ans+1;
		return 0;
	}
	long long len=f(a[1],a[n]);
	long long ans=0;
	for(long long i=1;i<=n;i++){
		if(a[i]<=len){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
