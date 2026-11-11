#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,cc,s,ss;
	cin>>c>>s>>cc>>ss;
	bool a=1,b=1;
	if(c==cc){
		cout<<1;
	}
	if(c!=cc){
		cout<<0;
		b=0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1]&&b==1){
		cout<<1;
	}
	if(s[0]!=ss[0]||s[1]!=ss[1]||b==0){
		cout<<0;
		a=0;
	}
	
	if((((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(ss[2]=='A'||ss[2]=='B'||ss[2]=='C'))||((s[2]=='D'||s[2]=='F')&&(ss[2]=='D'||ss[2]=='F')))&&a==1&&b==1){
		cout<<1;
	}
	else
		cout<<0;
		
	if(((s[2]=='A'&&ss[2]=='B')||(ss[2]=='A'&&s[2]=='B')||(s[2]=='B'&&ss[2]=='C')||(ss[2]=='B'&&s[2]=='C')||(s[2]=='D'&&ss[2]=='F')||(ss[2]=='D'&&s[2]=='F'))&&a==1&&b==1){
		cout<<1;
	}
	else
		cout<<0;
	return 0;
}
