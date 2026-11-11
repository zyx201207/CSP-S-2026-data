#include<bits/stdc++.h>
using namespace std;
bool l(char a,char b){
	if((a=='A'&&b=='B')||(b=='A'&&a=='B')||(a=='A'&&b=='C')||(b=='A'&&a=='C')||(a=='B'&&b=='C')||(b=='B'&&a=='C'))return 1;
	if((a=='D'&&b=='F')||(b=='D'&&a=='F'))return 1;
	return 0;
}
bool n(char a,char b){
	if((a=='A'&&b=='B')||(b=='A'&&a=='B')||(a=='B'&&b=='C')||(b=='B'&&a=='C')||(a=='F'&&b=='D')||(b=='F'&&a=='D'))return 1;
	return 0;
}	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int aw,bw;
	aw=(a1[0]-'0')*10+a1[1]-'0';
	bw=(b1[0]-'0')*10+b1[1]-'0';
	
	if(aw!=bw){
	cout<<"0000";
	return 0;
	}
	int aq,bq;
	aq=(a2[0]-'0')*10+a2[1]-'0';
	bq=(b2[0]-'0')*10+b2[1]-'0';
	if(aq!=bq){
	cout<<1000;
	return 0;
	}
	char a,b;
	a=a2[2];
	b=b2[2];
	if(!l(a,b)){
		cout<<1100;
		return 0;
	}
	if(!n(a,b)){
		cout<<1110;
		return 0;
	}
	cout<<1111;
	return 0;
}
