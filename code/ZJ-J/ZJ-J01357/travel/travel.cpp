#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,a2,b1,b2;
	char c1,c2;
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if(c1=='F') c1='E';
	if(c2=='F') c2='E';
	if(a1==a2){
		cout<<"1";
		if(b1==b2){
			cout<<"1";
			if((c1<='C'&&c2<='C')||(c1>='D'&&c2>='D')){
				cout<<"1";
				int x=c1-c2;
				if(x==1||x==-1){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}	
		else cout<<"000";		
	}
	else cout<<"0000";
	return 0;
}