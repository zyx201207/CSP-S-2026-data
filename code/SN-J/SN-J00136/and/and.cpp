#include<bits/stdc++.h>
using namespace std;
int a[200001],b;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long m,n;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	long c;
	for(int i=1; i<=n; i++) {
		c=a[i];
		for(int j=i; j<=n; j++) {
			for(int z=1; z<m; z++) {
				c=c&a[j];
			}
		}
		if(c>b) {
			b=c;
		}
	}
	cout<<b<<endl;
	return 0;
}
