#include<iostream>
using namespace std;
char c3[10],c4[10],c[15];
int c1,c2,i,flag=0,flag1=0;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	for(i=1;i<=2;i++){
		cin>>c1;
	}
	for(i=1;i<=3;i++){
		cin>>c3[i];
	}
	for(i=1;i<=2;i++){
		cin>>c2;
	}
	for(i=1;i<=3;i++){
		cin>>c4[i];
	}
	c[1]='A';
	c[2]='B';
	c[3]='C';
	c[4]='D';
	c[5]='F';
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(c3[1]==c4[1]&&c3[2]==c4[2]){
		cout<<"1";
	}
	else cout<<"0";
	if((c3[3]=='A'||c3[3]=='B'||c3[3]=='C')&&(c4[3]=='A'||c4[3]=='B'||c4[3]=='C')){
		flag=1;
	}
	else if((c3[3]=='D'||c3[3]=='F')&&(c4[3]=='D'||c4[3]=='F')){
		flag=1;
	}
	if(flag==1){
		cout<<"1";
	}
	else cout<<"0";
	for(i=1;i<=3;i++){
		if(c3[3]==c[i]){
			if(c[i+1]==c4[3]||c[i-1]==c4[3]){
				flag1=1;
			}
		}
	}
	if(flag1==1){
		cout<<"1";
	}
	else{
		for(i=4;i<=5;i++){
			if(c3[3]==c[i]){
				if(c[i+1]==c4[3]){
					cout<<"1";
					flag1=1;
				}
			}
		}
	}
	if(flag1!=1){
		cout<<"0";
	}
	return 0;
}