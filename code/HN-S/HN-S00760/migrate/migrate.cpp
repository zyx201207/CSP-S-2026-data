#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for (int i=1;i<=n;i++){
		cin>>n>>d;
		for (int i=1;i<=n;i++) cin>>x[i];
		cout<<d<<'\n';
	}
	return 0;
}
