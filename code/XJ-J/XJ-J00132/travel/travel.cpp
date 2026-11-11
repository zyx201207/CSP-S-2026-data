#include<bits/stdc++.h>
using namespace std;
string c,s,ca,sa;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>ca>>sa;
	if(c==ca)cout<<1;
	else cout<<0;
	if(s[0]==sa[0]&&s[1]==sa[1]&&c==ca)cout<<1;
	else cout<<0;
	if(!(s[2]=='C'&&sa[2]=='D')&&!(s[2]=='D'&&sa[2]=='C')&&s[0]==sa[0]&&s[1]==sa[1]&&c==ca)cout<<1;
	else cout<<0;
	if(abs(int(s[2])-int(sa[2]))==1&&!(s[2]=='C'&&sa[2]=='D')&&!(s[2]=='D'&&sa[2]=='C')&&s[0]==sa[0]&&s[1]==sa[1]&&c==ca)cout<<1;
	else cout<<0;
	return 0;
} 
