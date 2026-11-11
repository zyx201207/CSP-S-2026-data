#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2,ans;
int a,b,f1,f2,f3; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+="1";
		f1=1;	
	}
	else{
		ans="0";
		f1=0;	
	}
	if(s1[0]=='0') a=s1[1]-'0';
	else a=s1[1]-'0'+10;
	if(s2[0]=='0') b=s2[1]-'0';
	else b=s2[1]-'0'+10;
	if(a==b&&f1){
		ans+="1";
		f2=1;	
	}
	else{
		ans+="0";
		f2=0;	
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&f1&&f2){
		ans+="1";
		f3=1;	
	}
	else if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&f1&&f2){
		ans+="1";
		f3=1;	
	}
	else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')&&f1&&f2){
		ans+="1";	
		f3=1;
	}
	else if((s2[2]=='D'||s2[2]=='F')&&(s1[2]=='D'||s1[2]=='F')&&f1&&f2){
		ans+="1";
		f3=1;	
	}
	else{
		ans+="0";
		f3=0;	
	}
	if(s1[2]=='A'&&s2[2]=='B'&&f1&&f2&&f3) ans+="1";
	else if(s2[2]=='A'&&s1[2]=='B'&&f1&&f2&&f3) ans+="1";
	else if(s1[2]=='B'&&s2[2]=='C'&&f1&&f2&&f3) ans+="1";
	else if(s2[2]=='B'&&s1[2]=='C'&&f1&&f2&&f3) ans+="1";
	else if(s1[2]=='D'&&s2[2]=='F'&&f1&&f2&&f3) ans+="1";
	else if(s2[2]=='D'&&s1[2]=='F'&&f1&&f2&&f3) ans+="1";
	else ans+="0";
	cout<<ans;
	return 0;
}

