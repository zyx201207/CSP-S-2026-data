#include<bits/stdc++.h>
using namespace std;
string a,b,ab,bb;
int main(){
	freopen("travel.in ","r",stdin);
	freopen("travel.out ","w",stdout);
	cin>>a>>ab>>b>>bb;
	if(a==b) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	int na=(ab[0]-'0')*10+ab[1]-'0',nb=(bb[0]-'0')*10+bb[1]-'0';
	if(na==nb) cout<<"1";
	else {
		cout<<"000";
		return 0;
	}
	if((ab[2]<'D'&&bb[2]<'D')||(ab[2]>'C'&&bb[2]>'C')){
		cout<<"1";
	}
	else {
		cout<<"00";
		return 0;
	}
	if((ab[2]=='C'&&bb[2]=='A')||(ab[2]=='A'&&bb[2]=='C')){
		cout<<"0";
	}
	else cout<<"1";
	return 0;
} 
