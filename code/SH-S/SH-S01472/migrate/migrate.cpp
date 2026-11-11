#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000002];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int l=0;l<t;l++){
		cin>>n>>d;
		long long ans=0;
		for(int i=0;i<n;i++) cin>>x[i];
		long long q=x[1]-x[0];
		long long k=(d/q)*2-1;
		if(n-k>ans&&k>2) ans=n-k;
	    cout<<ans<<endl;
	}
	return 0;
} 
