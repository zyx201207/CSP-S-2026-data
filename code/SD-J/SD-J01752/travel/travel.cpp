#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
//Trick||Treat!
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1)cout<<1;
	else{
		cout<<"0000";return 0;
	}
	if(a2[0]==b2[0]&&a2[1]==b2[1])cout<<1;
	else {cout<<"000";return 0;}
	char i=a2[2],j=b2[2];
	if(i>j)swap(i,j);
	if((i=='A'&&j=='B')||(i=='B'&&j=='C')||(i=='A'&&j=='C'))cout<<1;
	else if(i=='D'&&j=='F') cout<<1;
	else{
		cout<<"00";return 0;
	}
	if((i=='A'&&j=='B')||(i=='B'&&j=='C')||(i=='D'&&j=='F'))cout<<1;
	else cout<<0;
	return 0;
}//Trick||Treat!
