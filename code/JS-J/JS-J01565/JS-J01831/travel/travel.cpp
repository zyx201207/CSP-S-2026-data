#include <bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int aa(char zf){
	if(zf=='A')return 1;
	if(zf=='B')return 1;
	if(zf=='C')return 1;
	if(zf=='D')return 2;
	if(zf=='E')return 2;
}
int bb(char zf){
	if(zf=='A')return 1;
	if(zf=='B')return 2;
	if(zf=='C')return 3;
	if(zf=='D')return 4;
	if(zf=='E')return 5;
}
int main(){
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
	cout<<1;
	}else{cout<<"0000";return 0;}
	if(b1[0]==b2[0]&&b1[1]==b2[1]){
	cout<<1;
	}else{cout<<"000";return 0;}
	if(aa(b1[2])==aa(b2[2])){
	cout<<1;
	}else{cout<<"00";return 0;}
	if(bb(b1[2])-bb(b2[2])==1||bb(b2[2])-bb(b1[2])==1){
	cout<<1;
	}else{cout<<"0";}
	return 0;
}
