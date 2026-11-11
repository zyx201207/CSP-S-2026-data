#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1; i<=t; i++) {
		int n,d;
		cin>>n>>d;
		long long x[2000005];
		for(int k=1; k<=n; k++) {
			cin>>x[k];
		}
		int ans=0;
		for(int m=0;m<=n;m++){
			for(int j=2;j<=n;j++){
				if(x[j]-x[m]>d||x[j]-x[m]<2*d){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
