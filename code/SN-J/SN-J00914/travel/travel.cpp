#include<bits/stdc++.h>
using namespace std;
bool xiang=false,pai=false,ce=false,lin=false;
int shuchu(){
	if(xiang==true){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(pai==true){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(ce==true){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(lin==true){
		cout<<"1";
	}else{
		cout<<"0";
	}
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		xiang=true;
	}else{
		shuchu();
		return 0;
	}
	if(s1[1]==s2[1]&&s1[0]==s2[0]) {
		pai=true;
	}else{
		shuchu();
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') {
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') {
			ce=true;
		}
	} else if(s1[2]=='D'||s1[2]=='F') {
		if(s2[2]=='D'||s2[2]=='F') {
			ce=true;
		}
	}else{
		shuchu();
		return 0;
	}
	if(s1[2]=='A') {
		if(s2[2]=='B') {
			lin=true;
		}
	} else if(s1[2]=='B') {
		if(s2[2]=='A'||s2[3]=='C') {
			lin=true;
		}
	} else if(s1[2]=='C') {
		if(s2[2]=='B') {
			lin=true;
		}
	} else if(s1[2]=='D') {
		if(s2[2]=='F') {
			lin=true;
		}
	} else if(s1[2]=='F') {
		if(s2[2]=='D') {
			lin=true;
		}
	}else{
		shuchu();
		return 0;
	}
	shuchu();
	return 0;
}
