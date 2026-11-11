#include<bits/stdc++.h>
using namespace std;
long long a[500010],n,m,s=0;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			s+=a[i]-a[j];
		}
		if(s==m&&a[i]!=a[i+1]) {
			cout<<i;
			return 0;
		}
		else if(s>m&&a[i]!=a[i+1]) {
			cout<<i-1;
			return 0;
		}
		s=0;
	}
	return 0;
}