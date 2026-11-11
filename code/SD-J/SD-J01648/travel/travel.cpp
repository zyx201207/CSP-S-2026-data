#include<bits/stdc++.h>
using namespace std;
string a,b,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>a>>b>>a2>>b2;
	if(b[2]=='F'){
		b[2]='E';
	}
	if(b2[2]=='F'){
		b2[2]='E';
	}
	if((a[0]==a2[0])&&(a[1]==a2[1])) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	//02 02B 02 01A
	if((b[0]==b2[0])&&(b[1]==b2[1])) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((abs(b[2]-b2[2])<=2)&&!((b2[2]=='C'&&b[2]=='D')||(b2[2]=='D'&&b[2]=='C'))) cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((abs(b[2]-b2[2])==1)&&!((b2[2]=='C'&&b[2]=='D')||(b2[2]=='D'&&b[2]=='C'))) cout<<1;
	else{
		cout<<"0";
	}
	return 0;
}
