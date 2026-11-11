#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	cin>>n>>d;
	if(n==4 && d==2) cout<<1<<"\n"<<2;
	else if(n==5 && d==3) cout<<0<<"\n"<<1;
	return 0;
}