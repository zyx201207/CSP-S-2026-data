#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int t[]={0,0,0,-1,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(b[2]=='D') b[2]='E';
	if(d[2]=='D') d[2]='E';
	bool A=(a==c),B=(b[0]==d[0]&&b[1]==d[1]),C=(t[b[2]-'A']==t[d[2]-'A']),D=(abs(b[2]-d[2])==1);
	cout<<A<<(A&&B)<<(A&&B&&C)<<(A&&B&&C&&D);
	return 0;}
