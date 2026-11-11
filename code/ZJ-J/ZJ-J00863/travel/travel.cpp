#include<bits/stdc++.h>
using namespace std;
char bb,dd;
int a,b,c,d;
string s,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>c>>ss;
	b=(s[0]-48)*10+s[1]-48,d=(ss[0]-48)*10+ss[1]-48;
	bb=s[2],dd=ss[2];
	if(a==c){
		cout<<'1';
		if(b==d){
			cout<<'1';
			if((bb<='C'&&dd<='C')||(bb>='D'&&dd>='D')){
				cout<<'1';
				if((bb=='A'&&dd=='C')||(bb=='C'&&dd=='A'))
					cout<<'0';
				else
					cout<<'1';
			}
			else
				cout<<"00";
		}
		else
			cout<<"000";
	}
	else
		cout<<"0000";
	return 0;
}
