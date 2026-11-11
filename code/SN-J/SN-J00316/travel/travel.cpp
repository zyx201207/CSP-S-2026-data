#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int c_1,c_2,s11,s12,s21,s22;
	c_1=c1[0]-'0';
	c_1*=10;
	c_1+=c1[1];
	
	c_2=c2[0]-'0';
	c_2*=10;
	c_2+=c2[1];
	
	s11=s1[0]-'0';
	s11*=10;
	s11+=s1[1];
	
	s21=s2[0]-'0';
	s21*=10;
	s21+=s2[1];
	
	s12=s1[2]-'A';
	
	s22=s2[2]-'A';
	if(c1==c2){
		cout<<1;
		if(s11==s21){
			cout<<1;
			if((s12==0||s12==1||s12==2)&&(s22==0||s22==1||s22==2)){
				cout<<1;
				if((max(s12,s22)-min(s12,s22))==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if((s12==3||s12==4)&&(s22==3||s22==4)){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
} 
