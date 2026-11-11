#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool tc(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C')return 1;
		else return 0;
	}else{
		if(b=='D'||b=='F')return 1;
		else return 0;
	}
}
bool xl(char a,char b){
	if(a=='A'&&b=='B')return 1;
	else if(a=='B'&&(b=='A'||b=='C'))return 1;
	else if(a=='C'&&b=='B')return 1;
	else if(a=='D'&&b=='F')return 1;
	else if(a=='F'&&b=='D')return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else if(s1[0]!=s2[0]||s1[1]!=s2[1])cout<<"1000";
	else if(!tc(s1[2],s2[2]))cout<<"1100";
	else if(!xl(s1[2],s2[2]))cout<<"1110";
	else cout<<"1111";
	return 0;
}
