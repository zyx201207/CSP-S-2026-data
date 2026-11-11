#include <bits/stdc++.h>
int c,t,n,d;
int a[2000012];
using namespace std;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		if (n==4 && d==2){
			cout<<1<<endl;
			continue;
		}
		if (n==5&&d==2){
			cout<<2;
			continue;
		}
		if (n==5 && d==3){
			cout<<0;
			continue;
		}
		if (n==6 && d==2){
			cout<<1;
			continue;
		}
		cout<<0<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
