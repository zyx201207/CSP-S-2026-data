//½­ÓêÄ½Ìì SN-J00747 
#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r","stdin");
	//freopen("travel.out","w","stdout");
	string c1,c2;
	string s1,s2;
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	string s="";
	if(c1==c2){
		s+="1";
	}else{
		s+="0";
	}
	if(s1[0]==s2[0] && s1[1]==s2[1] && s1[2]!=s2[2]){
		s+="1";
	}else{
		s+="0";
	}
	if('A'<=s1[2]<='C' && 'A'<=s2[2]<='C' && s1[2]!=s2[2] && 'D'<=s1[2]<='F' && 'D'<=s2[2]<='F' ){
		s+="1";
	}else{
		s+="0"; 
	}
	if(s1[0]==s2[0] && s1[1]==s2[1] && s1[2]!=s2[2] && s1[2]+1==s2[2]+1-1 || s1[2]-1==s2[2]+1-1){
		s+="1";
	}else{
		s+="0";
	}
	cout<<s;
}
