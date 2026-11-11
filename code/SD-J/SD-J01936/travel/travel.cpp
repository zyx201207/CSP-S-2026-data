#include <bits/stdc++.h>
using namespace std;
string c,cc,z,zz;
bool is_p(char x,char y){
	if(((x<='C' && x>='A') && (y>='A' && y<='C')) || ((x<='F' && x>='E') && (y>='E' && y<='F'))){
		return 1;
	}
	return 0;
}
int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>c>>z>>cc>>zz;
	if (c==cc){
		cout<<1;
	}
	else {
		cout<<"0000";
		return 0;
	}
	string a,aa;
	char b,bb;
	a=z[0]+z[1];
	aa=zz[0]+zz[1];
	if (a==aa){
		cout<<1;
	}
	else {
		cout<<"000";
		return 0;
	}
	b=z[2];
	bb=zz[2];
	if (is_p(b,bb)){
		cout<<1;
	}
	else {
		cout<<"00";
		return 0;
	}
	if (b+1==bb || b-1==bb){
		if (is_p(b,bb)){
			cout<<1;
		}
		else {
			cout<<0;
		}
	}
	else {
		cout<<0;
	}
	return 0;
}
//(b<='C' && b>='A' && bb>='A' && bb<='C') || (b<='F' && b>='E' && bb>='F' && bb<='E')




//xueyibujing



































































