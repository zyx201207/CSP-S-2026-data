#include <bits/stdc++.h>
using namespace std;
string c,s,tc,ts;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>tc>>ts;
	if(c==tc)cout<<1;
	else {cout<<"0000";return 0;}
	if(s[0]==ts[0]&&s[1]==ts[1])cout<<1;
	else {cout<<"000";return 0;}
	if(s[2]=='D'||s[2]=='F'){
		if(ts[2]=='D'||ts[2]=='F'){cout<<11;return 0;}
		else {cout<<"00";return 0;}
	}
	else {
		if(ts[2]=='A'||ts[2]=='B'||ts[2]=='C')cout<<1;
		else {cout<<"00";return 0;}
	}
	if((s[2]=='A'&&ts[2]=='B')||s[2]=='B'||(s[2]=='C'&&ts[2]=='B'))cout<<1;
	else cout<<0;
	return 0;
}
