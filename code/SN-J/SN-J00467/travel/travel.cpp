#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,c3,c4;
	char r,x;
	int R,X,num=0;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		cout<<"1";
	}
	else{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	for(int i=0;i<=2;i++){
		if(i<2)R=c2[i]-48;
		else{
			r=c2[i];
		}
	}
	for(int i=0;i<=2;i++){
		if(i<2)X=c4[i]-48;
		else{
			x=c4[i];
		}
	}
	if(R==X){
		cout<<'1';
	}
	else{
		cout<<'0'<<'0'<<'0';
		return 0;
	}
	if(r=='D'&&x=='F'||r=='F'&&x=='D'){
		cout<<'1';
	}
	else if(r=='A'&&x=='B'||r=='A'&&x=='C'||r=='B'&&x=='A'||r=='B'&&x=='C'||r=='C'&&x=='A'||r=='C'&&x=='B'){
		cout<<'1';
	}
	else{
		cout<<'0'<<'0';
		return 0;
	}
	if(r=='C'&&x=='D'&&r=='D'||x=='C'){
		cout<<'0';
		return 0;
	}
	if(x+1==r||r+1==x){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
}
