#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	if((s1[0]==s2[0])&&(c1[0]==c2[0])){
		cout<<"1";
	}else{
		cout<<"0";
	}
		if(s1[1]=='A'&& s2[1]=='A')||(c1[0]==c2[0]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
		if(s1[1]=='B'&& s2[1]=='B')||(c1[0]==c2[0]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
		if(s1[1]=='C'&& s2[1]=='C')||(c1[0]==c2[0]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
		if(s1[1]=='D'&& s2[1]=='D')||(c1[0]==c2[0]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
		if(s1[1]=='F'&& s2[1]=='F')||(c1[0]==c2[0]){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	return 0;
}

