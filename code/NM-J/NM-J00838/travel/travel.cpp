#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool b1=0,b2=0,b3=0,b4=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) b1=1;
	if(b1==1){
		if(s2[0]==s4[0]&&s2[1]==s4[1]) b2=1;
	}
	if(b2==1){
		if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='A'&&s4[2]=='C')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='B'&&s4[2]=='A')||(s2[2]=='C'&&s4[2]=='A')||(s2[2]=='C'&&s4[2]=='B')||(s2[2]=='F'&&s4[2]=='D')) b3=1;
	}
	if(b3==1){
		if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='F')||(s2[2]=='B'&&s4[2]=='A')||(s2[2]=='C'&&s4[2]=='B')||(s2[2]=='F'&&s4[2]=='D')) b4=1;
	}
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
