#include<bits/stdc++.h>
using namespace std;
const long long  N=1e6+5;
long long n,m,a[N],s[N];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long  i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long  i=2; i<=n; i++) {
		s[i]+=s[i-1]+(a[i]-a[i-1])*(i-1);
	}
	for(long long  i=1; i<=n; i++) {
		if(s[i]>m) {
			cout<<i-1;
			return 0;
		}
	}
}

