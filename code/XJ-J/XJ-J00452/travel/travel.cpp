#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1[5],s2[5];
int main(){
	cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	string qs="";
	if(c1==c2){
		qs+="1";
	}else{
		cout<<"0000"<<endl;
		return 0;
	}
	
	if((s1[1]==s2[1]&&s1[1]==s2[1])&&(s1[2]==s2[2]&&s1[2]==s2[2])){
		qs+="1";
	}else{
		cout<<"1000"<<endl;
		return 0;
	}
	
	if(((s1[3]=='A'||s1[3]=='B'||s1[3]=='C')&&(s2[3]=='A'||s2[3]=='B'||s2[3]=='C'))||((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F'))){
		qs+="1";
	}else{
		cout<<"1100"<<endl;
		return 0;
	}
	
	
	if((s1[3]==s2[3]+1||s1[3]==s2[3]-1)||(s1[3]==s2[3]+2||s1[3]==s2[3]-2)){
		qs+="1";
	}else{
		cout<<"1110"<<endl;
		return 0;
	}
	
	
	
	
	cout<<qs<<endl;
	return 0;
}
