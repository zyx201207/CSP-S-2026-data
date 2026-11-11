#include<bits/stdc++.h>
using namespace std;
string a1,b1,a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)cout<<1;
	else{
		cout<<"0000\n";
		return 0;
	}
	if(a2.substr(0,2)==b2.substr(0,2))cout<<1;
	else{
		cout<<"000\n";
		return 0;
	}
	if((a2[2]=='A'||a2[2]=='B'||a2[2]=='C')&&b2[2]!='D'&&b2[2]!='E')cout<<1;
	else if((a2[2]=='D'||a2[2]=='E')&&(b2[2]=='D'||b2[2]=='E'))cout<<1;
	else{
		cout<<"00\n";
		return 0;
	}
	if(abs((int)a2[2]-(int)b2[2])==1)cout<<1;
	else cout<<0;
	return 0;
}
