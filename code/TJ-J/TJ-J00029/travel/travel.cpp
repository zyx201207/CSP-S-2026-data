#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	
	string r1="",r2="";
	r1=s1[0]+s1[1];
	r2=s2[0]+s2[1];
	if(r1==r2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	
	char n1,n2;
	n1=s1[2];
	n2=s2[2];
	int flag=0;
	if(n1>='A'&&n1<='C'&&n2>='A'&&n2<='C'){
		cout<<"1";
		flag=1;
	}
	if(n1>='D'&&n1<='F'&&n2>='D'&&n2<='F'){
		cout<<"11";
		flag=2;
	}
	if(!flag){
		cout<<"00";
		return 0;
	}
	if(flag==1&&abs(n1-n2)==1){
		cout<<"1";
	}
	else cout<<"0";
	return 0;
}




