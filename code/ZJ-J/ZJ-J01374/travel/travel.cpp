#include<bits/stdc++.h>
using namespace std;
string R1,R2,X1,X2;
bool flag=1;
bool check(char a,char b){
	if(a=='A'&&b=='B') return 1;
	if(a=='B'&&b=='C') return 1;
	if(a=='E'&&b=='F') return 1;
	return 0;
	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R1>>R2>>X1>>X2;
	if(R1==X1){
		cout<<1;
	}else{
		cout<<0;
		flag=0;
	}
	if(R2[0]==X2[0]&&R2[1]==X2[1]&&flag){
		cout<<1;
	}else{
		cout<<0;
		flag=0;
	}
	if(((R2[2]<='C'&&X2[2]<='C')||(R2[2]>='E'&&X2[2]>='E'))&&flag){
		cout<<1;
	}else{
		cout<<0;
		flag=0;
	}
	if(check(R2[2],X2[2])&&flag){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
