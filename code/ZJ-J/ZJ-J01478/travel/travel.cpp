#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	bool flag=0;
	if(a==c) cout<<1;
	else flag=1,cout<<0;
	if(flag==0&&b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else flag=1,cout<<0;
	if(flag==0&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))) cout<<1;
	else flag=1,cout<<0;
	if(flag==0&&abs((int)b[2]-(int)d[2])==1) cout<<1;
	else cout<<0;
	return 0;
}