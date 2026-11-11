#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool bol1=(a==c);
	bool bol2=bol1&&((b[1]==d[1]));
	bool bol3=bol2&&((b[2]<='C')==(d[2]<='C'))<<'\n';
	//cout<<(b[2]<='C')<<' '<<(d[2]<='C')<<'\n';
	cout<<bol1;
	cout<<bol2;
	cout<<bol3;
	cout<<((abs(b[2]-d[2])==1)&&bol3);
	//cout<<"Hello World";
	return 0;
}
