#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3) printf("1");
	else printf("0");
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]) printf("1");
	else printf("0");
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		if(s2[2]=='A'&&(s4[2]=='B'||s4[2]=='C')) printf("1");
		else if(s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C')) printf("1");
		else if(s2[2]=='C'&&(s4[2]=='A'||s4[2]=='B')) printf("1");
		else if(s2[2]=='D'&&s4[2]=='F') printf("1");
		else if(s2[2]=='F'&&s4[2]=='D') printf("1");
		else printf("0");
	}else printf("0");
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		if(s2[2]=='A'&&s4[2]=='B') printf("1");
		else if(s2[2]=='B'&&(s4[2]=='A'||s4[3]=='C')) printf("1");
		else if(s2[2]=='C'&&s4[2]=='B') printf("1");
		else if(s2[2]=='D'&&s4[2]=='F') printf("1");
		else if(s2[2]=='F'&&s4[2]=='D') printf("1");
		else printf("0");
	}else printf("0");
	return 0;
} 
