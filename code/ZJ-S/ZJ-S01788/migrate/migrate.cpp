#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--) {
		int n;long long d;
		cin>>n>>d;
		vector<long long> x(n+1);
		bool flag=1;
		for(int i=1;i<=n;i++) {
			cin>>x[i];
			if(i>=2&&x[2]-x[1]!=x[i]-x[i-1]) flag=0; 
		}
		if(flag) {
			if(x[2]-x[1]>d) cout<<0<<"\n";
			else {
				if(n<4) cout<<0<<"\n";
				else cout<<n-3<<"\n";
			}
		}
		else {
			cout<<0<<"\n";
		}
	}
	return 0;
}