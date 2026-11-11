#include<bits/stdc++.h> 
using namespace std;

	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a=0,b=0;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	cout<<1;
	if(a1[0]==b1[0]&&a1[1]==b1[1]) cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if((a1[2]=='A'&&b1[2]=='B')||(a1[2]=='B'&&b1[2]=='C')||(a1[2]=='A'&&b1[2]=='C')||(a1[2]=='D'&&b1[2]=='E')||(a1[2]=='B'&&b1[2]=='A')||(a1[2]=='C'&&b1[2]=='B')||(a1[2]=='C'&&b1[2]=='A')||(a1[2]=='E'&&b1[2]=='D'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((a1[2]=='A'&&b1[2]=='B')||(a1[2]=='B'&&b1[2]=='C')||(a1[2]=='D'&&b1[2]=='E')||(a1[2]=='B'&&b1[2]=='A')||(a1[2]=='C'&&b1[2]=='B')||(a1[2]=='E'&&b1[2]=='D')) cout<<1;
	else {
		cout<<"0";
		return 0;
	}
	return 0;
}
