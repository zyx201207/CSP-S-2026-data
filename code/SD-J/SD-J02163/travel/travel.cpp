#include<bits/stdc++.h>
using namespace std;
string cr,zr,cx,zx;
int f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>zr>>cx>>zx;
	if(cr==cx) cout<<1;
	else{
		f=0;
		cout<<0;
	}
	if(zr[0]==zx[0]&&zr[1]==zx[1]&&f) cout<<1;
	else{
		f=0;
		cout<<0;
	}
	if(((zr[2]<='C'&&zx[2]<='C')||(zr[2]>'C'&&zx[2]>'C'))&&f) cout<<1;
	else{
		f=0;
		cout<<0;
	}
	if(f&&((zr[2]=='B'||zx[2]=='B')||(zr[2]>'C'&&zx[2]>'C'))) cout<<1;
	else{
		f=0;
		cout<<0;
	}
	return 0;
} 
