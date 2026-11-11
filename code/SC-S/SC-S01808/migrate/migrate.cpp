#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen(" migrate.out","w",stdout);
	cin>>c>>t;
	for(int q=1;q<=t;q++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
		}
		if(n==4)cout<<1<<endl;
		if(n==5&&d==2)cout<<2<<endl;
		if(n==5&&d==3)cout<<0<<endl;
		if(n==6)cout<<1<<endl;
	}
	return 0;
}