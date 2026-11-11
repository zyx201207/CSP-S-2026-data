#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
bool check(long long x,long long y){
	long long sum1=0;
	sum1=a[x]*(x-y)-sum[x]+sum[y];
	if (sum1>m) return 0;
	return 1;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long ans=1,ans1=1;
	cin >>n>>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for (int i=0;i<n;i++){
		long long l=1,r=n;
		while (l<=r){
			long long mid=(l+r)>>1;
			if (check(mid,i)){
				l=mid+1;
				ans=mid-i;
			}
			else{
				r=mid-1;
			}
		}
		ans1=max(ans1,ans); 
	}
	cout <<ans1;
	return 0;
} 
