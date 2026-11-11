#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int f=0;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
		f=1; 
	}
	int a1=((s1[0]-'0')*10)+(s1[1]-'0');
	int a2=((s2[0]-'0')*10)+(s2[1]-'0');
	if(f==0){
		if(a1==a2){
			cout<<"1";
		}
		else{
			cout<<"0";
			f=1;
		}
	}
	else{
		cout<<"0";
	}
	char b1=s1[2];
	char b2=s2[2];
	if(f==0){
		if((b1=='D'&&b2=='F')||(b1=='F'&&b2=='D')){
			cout<<"11";
		}
		else if((b1=='A'&&(b2=='B'||b2=='C'))||(b1=='B'&&(b2=='A'||b2=='C'))||(b1=='C'&&(b2=='A'||b2=='B'))){
			cout<<"1";
			if((b1=='A'&&b2=='B')||(b1=='B'&&b2=='C')){
				cout<<"1";
			}
			else{
				cout<<"0";
			}
		}
		else{
			cout<<"00";
		}
	}
	else{
		cout<<"00";
	}
	return 0;
} 
