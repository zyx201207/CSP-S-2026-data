#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("trvael.in","r",stdin);
	freopen("trvael.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&c1[0]==c2[0]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(((s1[0]==s2[0])&&(s1[1]==s2[1]))&&(c1[0]==c2[0])){
		if(s2[2]<="C"&&s1[2]<="C"){
			cout<<"1";
		}
		else if((s2[2]=="D"&&s1[2]=="F")||(s2[2]=="F"&&s1[2]=="D")){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	if((s1[0]==s2[0]&&s1[1]==s2[1])&&c1[0]==c2[0]){
		if((s2[2]<="C"&&s1[2]<="C")&&(int(s2[2]-s1[2])==1)){
		cout<<"1";
		}
		else if((s2[2]=="D"&&s1[2]=="F")||(s2[2]=="F"&&s1[2]=="D")){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	
	retrun 0;
} 
