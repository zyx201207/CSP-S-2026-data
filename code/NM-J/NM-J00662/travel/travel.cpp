#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
//	freopen("string.in","r","stdin");
//	freopen("string.out","w","stdout");
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000" ;
	else{
		if(s1[1]!=s2[1]) cout<<1000;
		else{
			if(s1[2]=='A'&&s2[2]=='B' || s1[2]=='B'&&s2[2]=='C'  || s1[2]=='B'&&s2[2]=='A' || s1[2]=='C'&&s2[2]=='B' || s1[2]=='D'&&s2[2]=='F' || s1[2]=='F'&&s2[2]=='D' ) cout<<1111;
			else if( s1[2]=='A'&&s2[2]=='C'|| s1[2]=='C'&&s2[2]=='A' ) cout<<1110;
		
			
		}
	}
	return 0;
} 
