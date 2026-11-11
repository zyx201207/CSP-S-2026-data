#include<bits/stdc++.h>
using namespace std;
string s,aa,bb,cc;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>aa>>bb>>cc;
	if(s[0]==bb[0]&&s[1]==bb[1]) a=1;
	if(aa[0]==cc[0]&&aa[1]==cc[1]) b=1;
	if(cc[2]=='A'||cc[2]=='B'||cc[2]=='C')
		if(aa[2]=='A'||aa[2]=='B'||aa[2]=='C')
			c=1;
	if(cc[2]=='D'||cc[2]=='E')
		if(aa[2]=='D'||aa[2]=='E')
			c=1;
	if(cc[2]=='A')
		if(aa[2]=='B')
			d=1;
	if(cc[2]=='B')
		if(aa[2]=='A'||aa[2]=='C')
			d=1;
	if(cc[2]=='C')
		if(aa[2]=='B')
			d=1;
	if(cc[2]=='D')
		if(aa[2]=='E')
			d=1;
	if(cc[2]=='E')
		if(aa[2]=='D')
			d=1;
	if(a==1){
		cout<<"1";
		if(b==1){
			cout<<"1";
			if(c==1){
				cout<<"1";
				if(d==1)
					cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000"	;
	}
	else cout<<"0000";
	return 0;
	
	
}
