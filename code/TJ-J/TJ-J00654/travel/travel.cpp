#include<bits/stdc++.h>
using namespace std;
int x,y,a,b;
string s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s>>y>>t;
	a=(s[0]-'0')*10+(s[1]-'0');
	b=(t[0]-'0')*10+(t[1]-'0');
	if(x==y)printf("1");
	else printf("0");
	if(x==y&&a==b)printf("1");
	else printf("0");
	if(x==y&&a==b){
		if(s[2]=='A'&&t[2]=='B'||s[2]=='A'&&t[2]=='C'||s[2]=='B'&&t[2]=='C'||s[2]=='D'&&t[2]=='F')printf("1");
		else if(t[2]=='A'&&s[2]=='B'||t[2]=='A'&&s[2]=='C'||t[2]=='B'&&s[2]=='C'||t[2]=='D'&&s[2]=='F')printf("1");
		else printf("0"); 
	}
	else printf("0");
	if(x==y&&a==b){
		if(s[2]=='A'&&t[2]=='B'||s[2]=='B'&&t[2]=='C'||s[2]=='D'&&t[2]=='F')printf("1");
		else if(t[2]=='A'&&s[2]=='B'||t[2]=='B'&&s[2]=='C'||t[2]=='D'&&s[2]=='F')printf("1");
		else printf("0"); 
	}
	else printf("0");
	return 0;
}


