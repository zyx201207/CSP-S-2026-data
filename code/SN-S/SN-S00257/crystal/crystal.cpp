#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005];
unsigned long long maxn;
bool check(long long x) {
	unsigned long long sum=0,ans=0;
	for(long long i=1; i<=n; i++) {
		if(a[i]<=x) {
			ans++;
			sum+=x-a[i];
		}
	}
//	cout<<sum<<endl;
	if(sum<=m) {
		maxn=max(maxn,ans);
	}
//	cout<<sum<<endl;
	return sum<=m;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
//	cout<<1<<endl;
	long long k=0;
//	cout<<k<<endl;
	for(long long i=pow(2,40); i; i/=2) {
//		cout<<1<<endl;
		if(check(k+i)) k+=i;
	}
	cout<<maxn<<endl;
	return 0;
}
