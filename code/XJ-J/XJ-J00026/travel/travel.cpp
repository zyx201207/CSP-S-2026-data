#include<bits/stdc++.h>
using namespace std;
int c,cc;
char s[3],ss[3];
int main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc)cout<<1;
	else {
		cout<<0<<0<<0<<0;return 0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1])cout<<1;
	else {
		cout<<0<<0<<0;
		return 0;
	}
	if((((s[2]=='A'||s[2]=='B')||s[2]=='C')&&((ss[2]=='A'||ss[2]=='B')||ss[2]=='C'))||((s[2]=='D'||s[2]=='F')&&(ss[2]=='D'||ss[2]=='F'))){
		cout<<1;
	}
	else {
		cout<<0<<0;return 0;
	}
	if((s[2]=='D'||s[2]=='F')&&(ss[2]=='D'||ss[2]=='F'))cout<<1;
	else if(((s[2]=='A'||s[2]=='B')&&(ss[2]=='A'||ss[2]=='B'))||((s[2]=='B'||s[2]=='C')&&(ss[2]=='B'||ss[2]=='C')))cout<<1;
	else cout<<0;
	return 0;
}
