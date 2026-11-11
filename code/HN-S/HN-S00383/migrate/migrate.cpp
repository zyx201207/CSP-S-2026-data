#include <bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n=0,d=0,x[2000005];
		cin>>n>>d;
		for (int i=0;i<n;i++) cin>>x[i];
		if (n%2==0) puts("1");
		else cout<<d<<'\n';
	}
	return 0;
}
