#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=((c1==c2)? 1 :0);
	b=((s1[0]==s2[0]&&s1[1]==s2[1]&&a==1)? 1 : 0);
	
	if(b==1){
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
			c=1;
		}
		else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
			c=1;
		}
		else c=0;
	}
	else c=0;
	
	if(c==1){
		if((s1[2]=='A'&&s2[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s1[2]=='D'&&s2[2]=='F')){
			d=1;
		}
	}
	else d=0;
	
	cout<<a<<b<<c<<d;
	return 0;
}
//I hope that I can get the whole score of T1!!
