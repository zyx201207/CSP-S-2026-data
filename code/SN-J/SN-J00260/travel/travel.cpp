#include<bits/stdc++.h>
using namespace std;
int a,b;
string a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b && 1<a&&17>a && 1<b&&17>b && a!=16 && b!=16)cout<<"1";
	else {
	    cout<<"0000";
	    return 0;
	}
	if(a1[0]==b1[0] && a1[1]==b1[1] && 1<=(a1[0]-'0')*10+(a1[1]-'0') &&18>=(a1[0]-'0')*10+(a1[1]-'0'))cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((a1[2]=='A'&&(b1[2]=='B'||b1[2]=='C')) || (a1[2]=='B'&&(b1[2]=='A'||b1[2]=='C')) || (a1[2]=='C'&&(b1[2]=='B'||b1[2]=='A')) || (a1[2]=='D'&&b1[2]=='F') || (a1[2]=='F'&&b1[2]=='D'))cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if((b1[2]-a1[2]==1) || (a1[2]-b1[2]==1) || (a1[2]=='D'&&b1[2]=='F') || (a1[2]=='F'&&b1[2]=='D'))cout<<"1";
	else cout<<"0";
	
	return 0;
} 
