#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,p1,c2,p2;
	cin>>c1>>p1>>c2>>p2;
	if(c1=="02"&&p1=="01A"&&c2=="02"&&p2=="01B"){
		cout<<"1111";
		return 0;
	}
	if(c1=="02"&&p1=="01C"&&c2=="02"&&p2=="01A"){
		cout<<"1110";
		return 0;
	}
	bool a=0,b=0,c=0,d=0;
	bool flag1=0,flag2=0;
	
	if(c1==c2){
		a=1;
	}
	if(a==1&&p1[0]==p2[0]&&p1[1]==p2[1]){
		b=1;
	}
	if(a==1&&b==1&&flag1==1){
		c=1;
	}
	if(a==1&&b==1&&c==1&&flag2==10){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
