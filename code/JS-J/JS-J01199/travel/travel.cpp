#include<bits/stdc++.h>
using namespace std;
char c1[2],c2[2],s1[3],s2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}if(s1[0]!=s2[0] && s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}else{
		cout<<"1";
	}if(s1[2]=='D' && s2[2]=='F'){
		cout<<"11";
		return 0;
	}else if(s2[2]=='D' && s1[2]=='F'){
		cout<<"11";
		return 0;
	}else if(s1[2]=='D' || s1[2]=='F'){
		cout<<"00";
		return 0;
	}else if(s2[2]=='D' || s2[2]=='F'){
		cout<<"00";
		return 0;
	}else{
		cout<<"1";
	}if(s1[2]=='A' && s2[2]=='C'){
		cout<<"0";
	}else if(s1[2]=='C' && s2[2]=='A'){
		cout<<"0";
	}else{
		cout<<"1";
	}return 0;
}
