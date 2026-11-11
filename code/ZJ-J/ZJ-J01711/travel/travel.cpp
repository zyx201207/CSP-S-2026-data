#include<bits/stdc++.h>
#define AKCSPJ ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
using namespace std;//100pts
signed main(){
	AKCSPJ;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<(a==c)<<((a==c)&&(b[1]==d[1])&&(b[0]==d[0]))<<((a==c)&&(b[1]==d[1])&&(b[0]==d[0])&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')))<<((a==c)&&(b[1]==d[1])&&(b[0]==d[0])&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C'))&&(abs((int)b[2]-(int)d[2])==1));
	
	return 0;
}
