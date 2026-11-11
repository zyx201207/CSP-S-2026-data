#include<bits/stdc++.h>
using namespace std;
int main(){
	string co,so,ct,st;
	char a,b;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>co>>so>>ct>>st;
	for (int i=0;i<2;i++){
		if(co[i]!=ct[i]){
			cout<<"0000";
			return 0;
		}
	}
	for (int i=0;i<2;i++){
		if(so[i]!=st[i]){
			cout<<"1000";
			return 0;
		}
	}
	a=so[2];
	b=st[2];
	if((a<=67&&a>=65)&&(b=='D'||b=='F')){
		cout<<"1100";
		return 0;
	}	
	if((a=='D'||a=='F')&&(b<=67&&b>=65)){
		cout<<"1100";
		return 0;
	}
	if((a=='A'&&b=='C')||(a=='C'&&b=='A')){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
