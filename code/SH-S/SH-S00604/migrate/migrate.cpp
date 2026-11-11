#include<bits/stdc++.h>
using namespace std;
long long x[2000005],c,t,n,d,k;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		k=x[2]-x[1];
		if(d/k<2) cout<<0<<"\n";
		else cout<<n-3<<"\n";
	}
}
