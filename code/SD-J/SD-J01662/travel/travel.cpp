#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin),freopen("travel.out","W",stdout);
	string c1,s1,c2,s2;
	char a,b;
	cin>>c1>>s1>>c2>>s2;
	
	if(!(c1[0]==c2[0]&&c1[1]==c2[1])){cout<<"0000";return 0;}cout<<1;
    
	if(!(s1[0]==s2[0]&&s1[1]==s2[1])){cout<<"000";return 0;}cout<<1;
	
	a=s1[2];b=s2[2];
	
	if(a=='D'||a=='F'){  if(b=='D'||b=='F'){cout<<"11";return 0;}  }
	
	if(a=='A'||a=='B'||a=='C')	
		{if(!(b=='A'||b=='B'||b=='C')){cout<<"00";return 0;}}cout<<1;
	if(a+1==b||a-1==b)cout<<'1';	 
	else cout<<0;
		
	
	
	
	
	
	
		
	
	
	return 0;
}
