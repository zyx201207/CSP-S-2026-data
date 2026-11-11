#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4,c5,c6;
char c7,c8;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	c5=c5+c2[0];
	c5=c5+c2[1];
	c6=c6+c4[0];
	c6=c6+c4[1];
	if(c5!=c6){
		cout<<"000";
		return 0;
	}else{
		cout<<1;
	}
	c7=c2[2];
	c8=c4[2];
	if((c7=='D'&&c8=='F')||(c7=='F'&&c8=='D')||(c7=='A'&&(c8=='B'||c8=='C'))||(c7=='B'&&(c8=='A'||c8=='C'))||(c7=='C'&&(c8=='B'||c8=='A'))){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if((c7=='D'&&c8=='F')||(c7=='F'&&c8=='D')){
		cout<<1;
	}else if(c7!='B'&&c8!='B'){
		cout<<0;
	}else{
		cout<<1;
	}
	return 0;
}
