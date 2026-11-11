#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int a1,a2;
	a1=s1[0]*10+s1[1];
	a2=s2[0]*10+s2[1];
	
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	
	
	if(c1==c2){
		if(a1==a2){
			cout<<"1";
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	
	
	if(c1==c2){
		if(a1==a2){
			if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	
	
	if(c1==c2){
		if(a1==a2){
			if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C')){
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&s2[2]=='B')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else if((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F')){
				if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"0";
			}
		}else{
			cout<<"0";
		}
	}else{
		cout<<"0";
	}
	return 0;
}



