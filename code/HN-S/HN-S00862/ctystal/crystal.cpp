#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],b[500001];
long long k = 0;
long long sum[500001];
int pd() {
	long long max = -999999;
	for(long long i = 0; i<n; i++) {
		sum[k] = 0;
		for(long long j =0; j<n; j++) {
			if(a[i]==a[j]) {
				sum[k]+=1;
			}
		}
		if(sum[k]>max) {
			max = sum[k];
		}
	}
	sum[k] = max;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i =0; i<n; i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i =0; i<n; i++) {
		b[i]=a[i];
	}
	for(long long i=0; i<n; i++) {
		int t1=m;
		for(long long i =0; i<n; i++) {
			a[i]=b[i];
		}
		for(long long j =0; j<n; j++) {
			for(long long l=t1; l>=0; l--) {
				if(a[j]+l==a[i] && t1>=l) {
					a[j]+=l;
					t1-=l;
				}
			}
		}
		pd();
		k+=1;
	}
	sort(sum,sum+n);
	cout<<sum[n-1];
}
