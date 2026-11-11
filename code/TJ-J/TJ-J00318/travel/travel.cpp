#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]) {
		cout<<"1";
	}
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) {
		cout<<"1";
	}
	else  {
		cout<<"000";
		return 0;
	}
	int a=s1[2]-'0';
	int b=s2[2]-'0';
	if(a<=19&&b<=19){
		cout<<"1";
	}
	else if(a>=20&&b>=20) {
		cout<<"1";
	}
	else {
		cout<<"00";
		return 0;
	}
	if((a-b)==1||(b-a)==1){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
} 
