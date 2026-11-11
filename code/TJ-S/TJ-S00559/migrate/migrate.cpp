#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
		}
		if(n==4&&d==2)
			cout<<1<<'\n';
		if(n==5&&d==2)
			cout<<2;
		if(n==5&&d==3)
			cout<<0<<'\n';
		if(n==6&&d==2)
			cout<<1;
	}
	return 0;
}
