#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	int a=0,b=0,c=0;
	char a1,a2,a3,b1,b2,b3;
	cin>>a>>a1>>a2>>a3>>b>>b1>>b2>>b3;
	if(a==b){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(a1==b1&&a2==b2){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	c=int(a3)-int(b3);
	c*=c;
	c=sqrt(c);
	if(int(a3)>=100&&int(b3)>=100){
		cout<<"11";
		return 0;
	}
	else if(int(a3)>=100||int(b3)>=100){
		cout<<"00";
		return 0;
	}
	else if(c==2){
		cout<<"10";
		return 0;
	}
	else{
		cout<<"11";
		return 0;
	}
	
	return 0;
}
