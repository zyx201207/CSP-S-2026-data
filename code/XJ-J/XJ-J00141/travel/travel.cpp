#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",strin);
	freopen("travel.out","w",strout);
	string c1,s1,c2,s2;
	string s;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		s="0000";
		cout<<s;
		return 0;
	}
	if(s1[0]!=s2[0] || s1[1]!=s2[1]){
		s="1000";
		cout<<s;
		return 0;		
	} 
	if(!(((s1[2]>='A' && s1[2]<='C')&&(s2[2]>='A' && s2[2]<='C')) || ((s1[2]=='D' || s1[2]=='F')&&(s2[2]=='D' || s2[2]=='F')))){
		s="1100";
		cout<<s;
		return 0;	
	} 
	if(!((s1[2]=='A' && s2[2]=='B')||(s1[2]=='B' && s2[2]=='A')||(s1[2]=='B' && s2[2]=='C')||(s1[2]=='C' && s2[2]=='B')||(s1[2]=='D' && s2[2]=='F')||(s1[2]=='F' && s2[2]=='D'))){
		s="1110";
		cout<<s;
		return 0;
	}
	s="1111";
	cout<<s;
	return 0;
}
