#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char s[7]={"000000"};
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	if(a==c) {
		s[1]='1';
		if((b[0]-48)*10+(b[1]-48)==(d[0]-48)*10+(d[1]-48)) {
			s[2]='1';
			if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')) s[3]='1';
			if(b[2]+1==d[2]&&b[2]!='C') s[4]='1';
			if(b[2]-1==d[2]&&b[2]!='D') s[4]='1';
			if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D')) s[4]='1';
		}
	}
	for(int i=1;i<=4;i++) cout<<s[i];
	return 0;
} 
