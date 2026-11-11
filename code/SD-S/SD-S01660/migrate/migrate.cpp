#include<bits/stdc++.h>
using namespace std;
int c,t;
int main () {
	freopen("migrate.in","r",stdin) ;
	freopen("migrate.out","w",stdout) ;
	cin>>c>>t;
	while(t--) {
		int a[1000001];
		int n,m;
		cin>>n>>m;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}

		if((m+2+a[2]-a[1]-1)/(a[2]-a[1])==4) {
			cout<<n-3<<endl;
		} else {
			cout<<"0"<<endl;
		}
	}
	return 0 ;
}

