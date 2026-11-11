#include<bits/stdc++.h>
using namespace std;
int main(){
	string c1,c2,s1,s2,s3,s4,s5,s6;
	cin>>c1>>s5>>c2>>s6;
	s5=s1+s3;
	s6=s2+s4;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s1==s2 && c1==c2){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(s3=="A" && s4=="B" && s1==s2 && c1==c2){
		cout<<"11";
	}else if(s3=="B" && s4=="A" && s1==s2 && c1==c2){
		cout<<"11";
	}else if(s3=="B" && s4=="C" && s1==s2 && c1==c2){
		cout<<"11";
	}else if(s3=="C" && s4=="B" && s1==s2 && c1==c2){
		cout<<"11";
	}else if(s3=="D" && s4=="F" && s1==s2 && c1==c2){
		cout<<"11";
	}else if(s3=="F" && s4=="D" && s1==s2 && c1==c2){
		cout<<"11";
	}else if(s3=="C" && s4=="A" && s1==s2 && c1==c2){
		cout<<"10";
	}else if(s3=="A" && s4=="C" && s1==s2 && c1==c2){
		cout<<"10";
	}else{
		cout<<"00";
	}
	return 0;
}