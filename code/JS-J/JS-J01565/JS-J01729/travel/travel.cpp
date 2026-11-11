#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	char zuo1,zuo2;
	zuo1=b[2];
	zuo2=d[2];
	if(a!=c){
		cout<<"0000";
	}
	else if((b[0]!=d[0])||(b[1]!=d[0])){
		cout<<"1000";
	}
	else if((zuo1=='A'&&(zuo2=='B'||zuo2=='C'))||(zuo1=='B'&&(zuo2=='A'||zuo2=='C'))||(zuo1=='C'&&(zuo2=='A'||zuo2=='B'))||(zuo1=='D'&&zuo2=='F')||(zuo1=='F'&&zuo2=='D')){
		if((zuo1=='A'&&zuo2=='B')||(zuo1=='B'&&(zuo2=='A'||zuo2=='C'))||(zuo1=='C'&&zuo2=='B')||(zuo1=='D')||(zuo1=='F')){
			cout<<"1111";
		}
		else{
			cout<<"1110";
		}
	}
	else{
		cout<<"1100";
	}
	return 0;
}
