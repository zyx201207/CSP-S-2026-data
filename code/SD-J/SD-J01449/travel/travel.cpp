#include<iostream>
using namespace std;
string s1,s2;
int flag=0,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;	
	s1=" "+s1;
	s2=" "+s2;
	if(c1==c2){
		cout<<1;	
		if(s1[2]==s2[2]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')){
				flag=1;
				cout<<1;
			}
			else if((s1[3]=='E'||s1[3]=='D')&&(s2[3]=='E'||s2[3]=='D')){
				flag=1;
				cout<<1;
			}
			else {
				cout<<0;
			}	
			if(((s1[3]==s2[3]+1)||(s1[3]+1==s2[3]))&&flag==1){
				cout<<1;
			}
			else {
				cout<<0;
			}
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
}
