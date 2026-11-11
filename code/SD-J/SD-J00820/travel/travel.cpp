#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int c,s,cc,ss;

int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	c=c1[1]-'0';
	if(c1[0]!='0'){
		c+=10;
	}
	cc=c2[1]-'0';
	if(c2[0]!='0'){
		cc+=10;
	}
	if(c==cc){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if((s1[0]==s2[0]) &&(s1[1]==s2[1])){
		cout<<1; 
	}else{
		cout<<"000";
		return 0;
	}
	s=s1[2]-'A';
	ss=s2[2]-'A';
	if(s<=2 && ss<=2){
		cout<<1;
	} else if(s>=3 && ss>=3){
		cout<<1;
	}else{
		cout<<"00";
	    return 0;
	}
	if(abs(s-ss)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
