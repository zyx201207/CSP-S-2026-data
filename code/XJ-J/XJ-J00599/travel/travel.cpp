#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a,b,c,d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	
	if(s1==s3){
		a=1;
	}
	else{
		cout<<a<<b<<c<<d<<"\n";
		return 0;
	}
	
	if(s2[0]*10+s2[1]==s4[0]*10+s4[1]){
		b=1;
	}
	else{
		cout<<a<<b<<c<<d<<"\n";
		return 0;
	}

	if(((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'))||((s2[2]=='D'||s2[2]=='F')&&(s4[2]=='D'||s4[2]=='F'))){
		c=1;
	}
	else{
		cout<<a<<b<<c<<d<<"\n";
		return 0;
	}
	
	if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='A')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='B')||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='F'&&s4[2]=='D')){
		d=1;
	}
	else{
		cout<<a<<b<<c<<d<<"\n";
		return 0;
	}
	cout<<a<<b<<c<<d<<"\n";
	return 0;
}