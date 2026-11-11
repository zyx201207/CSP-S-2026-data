#include <bits/stdc++.h>
using namespace std;
string r1,r2,x1,x2;
string s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>r2>>x1>>x2;
	if(r1==x1) s+='1';
	else{
		cout<<"0000";
		return 0;
	}
	int r=(r2[0]-48)*10+(r2[1]-48);
	int x=(x2[0]-48)*10+(x2[1]-48);
	if(r==x) s+='1';
	else{
		cout<<s<<"000";
		return 0;
	}
	if(r2[2]>='A'&&r2[2]<='C'&&x2[2]>='A'&&x2[2]<='C'||r2[2]>='D'&&r2[2]<='E'&&x2[2]>='D'&&x2[2]<='E'){
		s+='1';
		if(abs(r2[2]-x2[2])==1)s+='1';
		else s+='0';
	}	
	else{
		cout<<s<<"00";
		return 0;
	}
	cout<<s;
	return 0;
}