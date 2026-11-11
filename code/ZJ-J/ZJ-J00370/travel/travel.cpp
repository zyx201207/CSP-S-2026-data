#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	a1=(a==c)?1:0;
	a2=(a1&&(b[0]==d[0]&&b[1]==d[1]))?1:0;
	a3=(a2&&((b[2]<='C'&&d[2]<='C')||(b[2]>'C'&&d[2]>'C')));
	a4=(a3&&(!((b[2]=='A'&&d[2]=='C')||(b[2]=='C'&&d[2]=='A'))));
	cout<<a1<<a2<<a3<<a4;
	return 0;
}