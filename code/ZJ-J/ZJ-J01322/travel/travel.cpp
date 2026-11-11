#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string a,b,aa,bb;
	cin>>a>>b>>aa>>bb;
	if(a==aa) cout<<1;
	else cout<<0;
	if((b[0]-'0')*10+(b[1]-'0')==(bb[0]-'0')*10+(bb[1]-'0')&&a==aa) cout<<1;
	else cout<<0;
	if((b[0]-'0')*10+(b[1]-'0')==(bb[0]-'0')*10+(bb[1]-'0')&&a==aa){
		if(b[2]=='D'&&bb[2]=='E') cout<<1;
		else if(bb[2]=='D'&&b[2]=='E') cout<<1;
		else if(b[2]=='A'&&bb[2]=='B') cout<<1;
		else if(b[2]=='B'&&bb[2]=='A') cout<<1;
		else if(b[2]=='A'&&bb[2]=='C') cout<<1;
		else if(b[2]=='C'&&bb[2]=='A') cout<<1;
		else if(b[2]=='C'&&bb[2]=='B') cout<<1;
		else if(b[2]=='B'&&bb[2]=='C') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if((b[0]-'0')*10+(b[1]-'0')==(bb[0]-'0')*10+(bb[1]-'0')&&a==aa){
		if(b[2]=='D'&&bb[2]=='E') cout<<1;
		else if(bb[2]=='D'&&b[2]=='E') cout<<1;
		else if(b[2]=='A'&&bb[2]=='B') cout<<1;
		else if(b[2]=='B'&&bb[2]=='A') cout<<1;
		else if(b[2]=='C'&&bb[2]=='B') cout<<1;
		else if(b[2]=='B'&&bb[2]=='C') cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
