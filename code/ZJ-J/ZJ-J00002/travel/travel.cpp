#include<bits/stdc++.h>
using namespace std;
int c,a,cc,aa;
char s[5],ss[5];
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s+1>>cc>>ss+1;
	a=(s[1]-'0')*10+(s[2]-'0');
	aa=(ss[1]-'0')*10+(ss[2]-'0');
	if(c==cc){
		if(a==aa){
			if((s[3]=='A'||s[3]=='B'||s[3]=='C')&&(ss[3]=='A'||ss[3]=='B'||ss[3]=='C')){
				if(s[3]+1==ss[3]||ss[3]+1==s[3]) cout<<1111;
				else cout<<1110;
			}
			else if((s[3]=='D'||s[3]=='F')&&(ss[3]=='D'||ss[3]=='F')) cout<<1111;
			else cout<<1100;
		}
		else cout<<1000;
	}
	else cout<<0000;
	cout<<c;
	return 0;
}
