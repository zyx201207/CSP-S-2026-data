#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<"1";
	else cout<<"0";
	if(a==c&&(b[0]-'0')*10+b[1]-'0'==(d[0]-'0')*10+d[1]-'0')cout<<"1";
	else cout<<"0";
	if(a==c&&(b[0]-'0')*10+b[1]-'0'==(d[0]-'0')*10+d[1]-'0'&&'A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C'||'D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F')cout<<"1";
	else cout<<"0";
	if(a==c&&(b[0]-'0')*10+b[1]-'0'==(d[0]-'0')*10+d[1]-'0'&&(abs(d[2]-b[2])==1&&!(b[2]=='C'&&d[2]=='D'||d[2]=='C'&&b[2]=='D')||((b[2]=='F'&&d[2]=='D'||d[2]=='F'&&b[2]=='D'))))cout<<"1";
	else cout<<"0";
	return 0; 
 } 
