#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int>x(n+1,0);
		for(int i=1;i<=n;i++)cin>>x[i];
		int s=x[2]-x[1];
		if(d>=2*s&&d<3*s)cout<<n-3<<'\n';
		else cout<<0<<'\n';
	}
	return 0;
}
