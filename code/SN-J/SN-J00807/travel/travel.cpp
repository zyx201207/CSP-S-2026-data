// SN-J00807  夏宇辰   西安市益新中学 
#include <bits/stdc++.h>
using namespace std;
int a,b,t=0,sbcnmaxcjbd=0;
char c[10],d[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a;
	for(int i=0;i<3;i++){
		cin>>c[i];
	}
	cin>>b;
	for(int i=0;i<3;i++){
		cin>>d[i];
	}
	if(a==b)
	sbcnmaxcjbd=0;
	else t=1;
	if(t==1){
	cout<<"0000";
	return 0;	
	}
	if(c[0]==d[0]&&c[1]==d[1])
    sbcnmaxcjbd=0;
    else t=2;
    if(t==2){
    cout<<"1000";
    return 0;
	}
	if((c[2]>='A'&&c[2]<='C'&&d[2]>='A'&&d[2]<='C')||(c[2]>='D'&&c[2]<='F'&&d[2]>='D'&&d[2]<='F'))
	sbcnmaxcjbd=0;
	else t=3;
	if(t==3){
	cout<<"1100";
	return 0;
	}
	if((c[2]=='A'&&d[2]=='B')||(d[2]=='A'&&c[2]=='B')||(c[2]=='B'&&d[2]=='C')||(d[2]=='B'&&c[2]=='C')||(c[2]=='D'&&d[2]=='F')||(d[2]=='D'&&c[2]=='F'))
	sbcnmaxcjbd=0;
	else t=4;
	if(t==4){
	cout<<"1110";
	return 0;
	}
	if(t==0)
	cout<<"1111";	
	return 0;
}
