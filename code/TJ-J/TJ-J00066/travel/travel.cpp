#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s11,s22;
	string s111,s222;
	char s1,s2;
	cin>>c1>>s111>>c2>>s222;
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	s11=int(s111[0]-'0')*10+int(s111[1]-'0');
	s22=int(s222[0]-'0')*10+int(s222[1]-'0');
	s1=s111[2];
	s2=s222[2];
	if(s11==s22){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if(s1=='A'&&(s2=='B'||s2=='C')||(s1=='B'&&(s2=='A'||s2=='C'))||(s1=='C'&&(s2=='B'||s2=='A'))||(s1=='D'&&s2=='E')||(s1=='E'&&s2=='D')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(s1-s2)==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
