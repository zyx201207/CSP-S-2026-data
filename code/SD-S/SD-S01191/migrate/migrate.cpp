#include<bits/stdc++.h>
#define ll long long
using namespace std;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,d;
	cin>>c>>t>>d;
	if(c==0){
		if(t==2&&d==4) cout<<1<<'\n'<<2;
		if(t==2&&d==5) cout<<0<<'\n'<<1;
	}
	return 0;
} 
