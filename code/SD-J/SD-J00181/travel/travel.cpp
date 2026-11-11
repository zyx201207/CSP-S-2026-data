#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin&&cout.tie(0);
	string s,st,str,stri,c,cc;
	char a,b;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>st>>str>>stri;
	c+=st[0],c+=st[1];
	cc+=stri[0],cc+=stri[1];
	a=st[2],b=stri[2];
	if(s==str) cout<<1;
	else cout<<0;
	if(c==cc&&s==str) cout<<1;
	else cout<<0;
	if(s==str&&c==cc&&((a=='A'&&b=='B'||b=='C')||(a=='B'&&b=='A'||b=='C')||(a=='C'&&b=='B'||b=='A')||(a=='D'&&b=='F')||(a=='F'&&b=='D'))) cout<<1;
	else cout<<0;
	if(s==str&&c==cc&&(((a==b-1)&&(((a!='C'&&b!='D')||((a==b+1)))&&(b!='C'&&a!='D'))))) cout<<1;
	else cout<<0;
	return 0;
}


