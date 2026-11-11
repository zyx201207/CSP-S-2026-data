#include<bits/stdc++.h>
using namespace std;
int main(){

	string c1,s1,c2,s2; 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(s1[2]=='A'||'B'||'C'&&s2[2]!='D'||'F'){
		cout<<"1";
	}
	else if(s2[2]=='D'||'F'&&s1[2]!='A'||'B'||'C'){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}