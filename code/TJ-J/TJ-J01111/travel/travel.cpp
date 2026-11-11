#include<bits/stdc++.h>

using namespace std;

string c,s,cc,ss;

bool check(string a,string b){
	int resA=0,resB=0,resC=0,resD=0;
	resA=(int)(a[0]-'0')*10+(int)(a[1]-'0'),resB=(int)(b[0]-'0')*10+(int)(b[1]-'0');
	resC=int(a[2]-'A'),resD=int(b[2]-'A');
	if((resA==resB)&&(abs(resC-resD)==1))return 1;
	if((abs(resA-resB)==1)&&(resC==resD))return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc)cout<<1;
	else cout<<0;
	if(c==cc&&s[0]==ss[0]&&s[1]==ss[1])cout<<1;
	else cout<<0;
	if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]&&((s[2]<='C'&&ss[2]<='C')||(s[2]>'C'&&ss[2]>'C')))cout<<1;
	else cout<<0;
	if(c==cc&&s[0]==ss[0]&&s[1]==ss[1]&&((s[2]<='C'&&ss[2]<='C')||(s[2]>'C'&&ss[2]>'C'))&&check(s,ss))cout<<1;
	else cout<<0;
	return 0;
}













