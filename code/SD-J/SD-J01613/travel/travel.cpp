#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int s1,s2;
int main() 
{
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else {cout<<"0000";return 0;}
	if(b[0]==d[0]&&b[1]==d[1])cout<<1;
	else {cout<<"000";return 0;}
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')s1=1;
	else s1=10;
	if(d[2]=='D'||d[2]=='F')s2=10;
	else s2=1;
	if(s1-s2==0)cout<<1;
	else {cout<<"00";return 0;}
	int x=b[2],y=d[2];
	if(abs(x-y)==1)cout<<1;
	else cout<<0;
	return 0;
}
