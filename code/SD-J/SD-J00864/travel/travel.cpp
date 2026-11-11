#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx,rp,xp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	rp+=sr[0]+sr[1];
	xp+=sx[0]+sx[1];
	if(rp==xp){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	char a,b;
	a=sr[2],b=sx[2];
	if((a<='C' && b<='C') || (a>'C' && b>'C')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(a==b+1 || b==a+1 || a=='D' || a=='F'){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}
