#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in" "r" stdin);
	freopen("travel.out" "w" stdout);
	int s;
    int c1,s1,c2,s2;
    cin >>c1>>s1>>c2>>s2>>s;
    if(c1==c2){
    	s[0]=1;
	}
	else{
		s[0]=1;
	}
	if(s1[0][1]==s2[0][1]){
		s[1][2]=1;
	}
	else{
		s[1][2]=0;
	}
	
	if(s1[2]="A" || s2[2]="B")
	{
	    s[3]=1;
	}
	if(s1[2]="B"|| s2[2]=="C")
	{
		s[3]=1;
	}
	if(s1[2]="D" || s2[2]=="E"){
		s[2]=1;
	}
	else{
		s[3]=0''
	}
	cout<<s;
}