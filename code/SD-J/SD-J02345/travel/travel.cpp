#include<iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//A
		cout<<1;
	}
	else {
		cout<<0; 
	}
	bool fl=0;
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&s1!=s2){	//B
		cout<<1;
		fl=1; 
	}
	else {
		cout<<0;
	}
	bool l=0;
		if(s1[2]>='A'&&s2[2]<='C'){//C
			l=1;	
		}
		else if((s1[2]>='D'&&s2[2]<='F')){
			l=1;
		}
		if(fl==1&&l==1){
			cout<<1;
			if(s1[2]=='D'&&s2[2]=='F'){//D
				cout<<1;
			}	
			else if(s1[2]=='A'&&s2[2]=='B'){//AµÄÇé¿ö 
				cout<<1;
			}
			else if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')){//B 
				cout<<1;
			}
			else if(s1[2]=='C'&&s2[2]=='B'){//C
				cout<<1;
			}
			else {
				cout<<0;
				}
		}
		else {
			cout<<0<<0;
		}
	return 0;
	
} 
