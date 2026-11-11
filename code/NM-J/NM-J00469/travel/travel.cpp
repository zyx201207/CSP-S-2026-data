#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","w",stdin);
freopen("travel.out","r",stdout);

	string  c1,s1,c2,s2;
	int e=0,f=0,g=0,h=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		e=1;
	}
    else{
    	e=0;
    }
 	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		f=1;
	}
	else{
    	f=0;
}
	if(s1[2]=='D'&&s1[2]=='E'||s1[2]=='D'&&s1[2]=='E'&&s1[2]=='A'&&s1[2]=='B'||s1[2]=='C'||s2[2]=='A'&&s2[2]=='B'&&s2[2]=='C'){
		g=1;
	}
	else{
    	g=0;
	}
	if(s1[2]=='D'&&s1[2]=='E'||s1[2]=='D'&&s1[2]=='E'){
		h=1;
	}
	else if(s1[2]=='B'&&s1[2]=='A'||s1[2]=='B'&&s1[2]=='A'){
    	h=1;
	}
	else if(s1[2]=='B'&&s1[2]=='C'||s1[2]=='B'&&s1[2]=='C'){
    	h=1;
	}
	else{
    	h=0;
	}
	cout<<e<<f<<g<<h;
return 0;
}
