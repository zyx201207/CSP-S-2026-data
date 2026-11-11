#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if((c1[1]==c2[1])&&(c1[2]==c2[2]))cout<<"1";
	else {cout<<"0000";return 0;}
	if((s1[1]==s2[1])&&(s1[2]==s2[2]))cout<<"1";
	else {cout<<"000";return 0;}
	if(((s1[3]=='C')&&(s2[3]=='D'))||((s1[3]=='D')&&(s2[3]=='C'))){
		cout<<"00";return 0;}
	    else {cout<<"1";}
	if(s1[3]=='A'){
	    if(s2[3]=='B'){cout<<"1";return 0;}
	    else{cout<<"0";return 0;}
	}
	if(s1[3]=='B'){
		if((s2[3]=='C')||(s2[3]=='A')){cout<<"1";return 0;}
		else{cout<<"0";return 0;}
	}
	if(s1[3]=='c'){
		if(s2[3]=='B'){cout<<"1";return 0;}
		else{cout<<"0";return 0;}
	}
	if(s1[3]=='D'){
		if(s2[3]=='F'){cout<<"1";return 0;}
		else{cout<<"0";return 0;}
	}
	if(s2[3]=='F'){
		if(s2[3]=='D'){cout<<"1";return 0;}
		else{cout<<"0";return 0;}
	}
		
}
