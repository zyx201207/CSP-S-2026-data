#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string bb,bbb,dd,ddd;
char bx,dx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<'1';
	}else{
		cout<<"0000";
		return 0;
	}
	bb=b[0];
	bbb=b[1];
	bbb+=bb;
	bx=b[2];
	dd=d[0];
	ddd=d[1];
	ddd+=dd;
	dx=d[2];
	if(bb==dd&&bbb==ddd){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if((dx=='A'&&(bx=='B'||bx=='C'))||(dx=='B'&&(bx=='A'||bx=='C'))||(dx=='C'&&(bx=='A'||bx=='B'))||(dx=='D'&&bx=='F')||(dx=='F'&&bx=='D')){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if((dx=='A'&&bx=='B')||((bx=='C'||bx=='A')&&dx=='B')||(dx=='C'&&bx=='B')||(dx=='D'&&bx=='F')||(dx=='F'&&bx=='D')){
		cout<<'1';
	}else{
		cout<<'0';
		
	}
	return 0;
}
