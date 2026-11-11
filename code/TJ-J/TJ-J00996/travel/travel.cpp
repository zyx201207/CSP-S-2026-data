#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a;
int main(){
	cin>>c1>>s1>>c2>>s2;
	if((c1[0]==c2[0])&&(c1[1]==c1[1])){
		a[0]=1;
	}else{
		cout<<a; 
		return 0;
	}
	if(s1[1]==s2[1]){
		a[1]=1;
	}else{
		cout<<a;
		return 0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
	    a[2]=1;
	}
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		 a[2]=1;
		 a[3]=1;
	}
	if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'||s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')){
		a[3]=1;
	}
	cout<<a;
return 0;
}
