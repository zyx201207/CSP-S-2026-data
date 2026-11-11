#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int num1,num2;
	char seat1[10],seat2[10];
	cin>>num1>>seat1>>num2>>seat2;
	if(num1==num2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(seat1[1]==seat2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(seat1[1]==seat2[1]&&(seat1[2]=='A'&&seat2[2]=='B'||seat1[2]=='A'&&seat2[2]=='C'||seat1[2]=='B'&&seat2[2]=='C'||seat1[2]=='C'&&seat2[2]=='B'||seat1[2]=='B'&&seat2[2]=='A'||seat1[2]=='C'&&seat2[2]=='A'||seat1[2]=='F'&&seat2[2]=='D'||seat1[2]=='D'&&seat2[2]=='F')){
		cout<<1;
	}else{
		cout<<0;
	}
	if(seat1[1]==seat2[1]&&(seat1[2]=='A'&&seat2[2]=='B'||seat1[2]=='B'&&seat2[2]=='A'||seat1[2]=='B'&&seat2[2]=='C'||seat1[2]=='C'&&seat2[2]=='B'||seat1[2]=='D'&&seat2[2]=='F'||seat1[2]=='F'&&seat2[2]=='D')){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

