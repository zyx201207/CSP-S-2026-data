#include <bits/stdc++.h>
using namespace std;
long long c=0;
long long n,m;
long long sum=0,sum1=0;
long long a[999999];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool tio=0;
	int l=0;
	for(long long i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	c=a[1]-a[0];
	for(long long i=0; i<n-1; i++) {
		if(a[i]!=a[i+1]) {
			tio=1;
		} else {
			sum++;
		}
	}
	if(tio==0) {
		cout<<n;
		return 0;
	} else if(m==0) {
		cout<<sum;
		return 0;
	} else {
		if(c==1) {
			for(long long i=0; i<=n; i++) {
				l+=i;
				if(m>=l) {
					sum1++;
				}
			}
			if(m>=l) {
				cout<<n;
				return 0;
			}
			if(sum1==1) {
				cout<<"0";
			} else {
				cout<<sum1;
			}
		} else {
			for(long long i=0; i<=n; i+=c) {
				l+=i;
				if(m>=l) {
					sum1++;
				}
			}
			if(m>=a[n]) {
				cout<<n;
				return 0;
			}
			if(sum1==1) {
				cout<<"0";
			} else {
				cout<<sum1-1;
			}
		}
	}

	return 0;
}

