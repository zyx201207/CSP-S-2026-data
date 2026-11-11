#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	int cxc1=c[0]*10+c[1],cxc2=cc[0]*10+cc[1];
	if(cxc1==cxc2)cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1])cout<<1;
	else
	{
		cout<<"000";
		return 0;
	}
	if((s[2]=='D' && ss[2]=='F') || (s[2]=='A' && ss[2]=='B') || (s[2]=='B' && ss[2]=='C') || (s[2]=='F' && ss[2]=='D') || (s[2]=='B' && ss[2]=='A') || (s[2]=='C' && ss[2]=='B'))cout<<11;
	else if((s[2]=='A' && ss[2]=='C') || (s[2]=='C'&& ss[2]=='A'))cout<<10;
	else cout<<"00";
	return 0;
}
//zr99 183699
