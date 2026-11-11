//郑博灏 西安辅轮中学  SN-J00719
#include<bits/stdc++.h>
using namespace std;


int main(){
	//freopen("t1.in","r",stdin);
	//freopen("t1.out","w",stdout);
	
	string s1,s2,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((char)s1[2]==67&&(char)s2[2]==68){
		cout<<"0";
	}else if((char)s2[2]==67&&(char)s1[2]==68){
		cout<<"0";
	}else{
		cout<<"1";
	}
	if((char)s1[2]==65&&(char)s2[2]==66){
		cout<<"1";
	}else if((char)s1[2]==66&&(char)s2[2]==67){
		cout<<"1";
	
	}else if((char)s1[2]==68&&(char)s2[2]==70){
		cout<<"1";
		
	}else if((char)s1[2]==67&&(char)s2[2]==68){
		cout<<"0";
	}
	swap(s1,s2);
	if((char)s1[2]==65&&(char)s2[2]==66){
		cout<<"1";
		
	}else if((char)s1[2]==66&&(char)s2[2]==67){
		cout<<"1";
		
	}else if((char)s1[2]==68&&(char)s2[2]==70){
		cout<<"1";
		
	}else if((char)s1[2]==67&&(char)s2[2]==68){
		cout<<"0";
	}
	return 0;
}

