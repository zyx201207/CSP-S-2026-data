#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	string e="1";
	if(a[0]!=c[0]||a[1]!=c[1]){
		cout<<"0000";
		return 0;
	}
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"1000";
		return 0;}
	if(b[0]==d[0]&&b[1]==d[1])
		e+='1';
		else
		e+='0';
	if(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')
		e+='1';
		else
		e+='0';
	
	if(b[2]<='C'&&d[2]<='C'){
	if(d[2]-b[2]==1||b[2]-d[2]==1)
	e+='1';
	else
	e+='0';
}
	if(b[2]>='C'&&d[2]>='C'){
	 if(b[2]<'C'||d[2]<'C')
		e+='0';
	else{
	e+='1';
}
}	if(e.length()<4)
		cout<<e+'0';
	else
		cout<<e;
	return 0;
}
