#include<bits/stdc++.h>
using namespace std;
const int N=5e5+8;
const int L=1e12+8;
int n;
long long m;
long long a[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long maxn=1,last=a[1],sum=1;
	for(int i=2; i<=n; i++) {
		if(last==a[i]) {
			sum++;
			maxn=max(sum,maxn);
			continue;
		}
		long long t=m;
		sum=0;
		for(int j=i; j>=1; j--) {
			long long b=a[i]-a[j];
			if(b<=t) {
				sum++;
				t-=b;
			} else break;
		}
		maxn=max(sum,maxn);
		last=a[i];
	}
	cout<<maxn;
	return 0;
}
