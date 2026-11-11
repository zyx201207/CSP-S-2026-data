#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){cout<<1;}
	else{cout<<"0000";return 0;}
	if(a2.substr(0,2)==b2.substr(0,2)){cout<<1;}
	else{cout<<"000";return 0;}
	if((a2[2]<='C'&&b2[2]<='C') or (a2[2]>='D'&&b2[2]>='D')){cout<<1;}
	else{cout<<"00";return 0;}
	if(((a2[2]<='C'&&b2[2]<='C')&&abs(a2[2]-b2[2])==1) or (a2[2]>='D'&&b2[2]>='D')){cout<<1;}
	else cout<<0;
	return 0;
}
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen//freopen
/*
fcc uoy kcuf
luogu uid=2070765
rp++rp++rp++rp++
*/
