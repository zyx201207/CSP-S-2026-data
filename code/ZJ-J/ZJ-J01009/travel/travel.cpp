#include<bits/stdc++.h>
using namespace std;
int c,cc,a,b;
string s,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if (c!=cc){
		cout<<"0000";
		return 0;
	}
	else 
		cout<<1;
	if (s[0]==ss[0]&&s[1]==ss[1])
		cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if (s[2]=='A'||s[2]=='B'||s[2]=='C')
		a=1;
	else 
		a=2;
	if (ss[2]=='A'||ss[2]=='B'||ss[2]=='C')
		b=1;
	else 
		b=2;
	if (a==b)
		cout<<1;
	else 
		cout<<0;
	if (a==1&&b==1&&abs(s[2]-ss[2])==1)
		cout<<1;
	else if (a==2&&b==2&&abs(s[2]-ss[2])==2)
		cout<<1;
	else 
		cout<<0;
	return 0;
} 