#include <bits/stdc++.h>
using namespace std;
int n,ans=1,m,c,t,mm,d;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int iii=1; iii<=t; iii++) {
		cin>>n>>d;
		int z[n+2]={};
		long long x[n+2]={};
		int ans=0;
		cin>>x[1]>>x[2];
		for(int i=3; i<=n; i++) {
			cin>>x[i];
			if(x[i]-x[i-2]<=d){
				z[i]++;
			}
		}
		for(int i=4; i<=n; i++) {
			for(int j=n; j>=i; j--) {
				z[j]+=z[j-1];
				if(z[j]==2){
					ans++;
				}
			}
		}
		if(x[n]-x[1]<=d){
			cout<<0<<endl;
		}else{
			cout<<ans<<endl;
		}
	}
	return 0;
}
