#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000100],d;
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	cin>>T>>T;
	while(T--) {
		cin>>n>>d; 
		int tmp=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		tmp=a[2]-a[1];
		if(tmp<2*d){
			cout<<0<<"\n";
		}else {
			cout<<n-(d/tmp)-1;
		}
	}

	return 0;
}

