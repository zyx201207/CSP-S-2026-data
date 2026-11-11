#include<bits/stdc++.h>
using namespace std;
string a,s,d,f;
int z,x,c,v;
bool q=0,w=0,e=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>d>>f;
	z=(a[0]-'0')*10+(a[1]-'0');
	c=(d[0]-'0')*10+(d[1]-'0');
	if(z==c){cout<<1;e=1;}
	else cout<<0;
	x=(s[0]-'0')*10+(s[1]-'0');
	v=(f[0]-'0')*10+(f[1]-'0');
	if(e&&x==v){cout<<1;w=1;}
	else cout<<0;
	if(!w||(s[2]>='d'&&f[2]<='c')||(f[2]>='d'&&s[2]<='c'))cout<<0;
	else {
		cout<<1;
		if(abs(s[2]-f[2])==1)q=1;
	}
	cout<<q;
return 0;
}


