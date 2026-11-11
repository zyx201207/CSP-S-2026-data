#include<bits/stdc++.h>
#define PI "travel"
#define FI freopen(PI".in","r",stdin)
#define FO freopen(PI".out","w",stdout)
using namespace std;
string cr,sr,cx,sx,ans="";
int sti(string s)
{
	int x;
	x=(int(s[0])-48)*10+(int(s[1])-48);
	return x;
}
bool check(string ss,string sc)
{
	if((ss[2]=='A' && sc[2]=='B') || (ss[2]=='A' && sc[2]=='C') || (ss[2]=='B' && sc[2]=='C') || (ss[2]=='D' && sc[2]=='F'))
	{
		return true;
	}
	if((sc[2]=='A' && ss[2]=='B') || (sc[2]=='A' && ss[2]=='C') || (sc[2]=='B' && ss[2]=='C') || (sc[2]=='D' && ss[2]=='F'))
	{
		return true;
	}
	return false;
}
bool checkn(string ss,string sc)
{
	if((ss[2]=='A' && sc[2]=='B') || (ss[2]=='B' && sc[2]=='C') || (ss[2]=='D' && sc[2]=='F'))
	{
		return true;
	}
	if((sc[2]=='A' && ss[2]=='B') || (sc[2]=='B' && ss[2]=='C') || (sc[2]=='D' && ss[2]=='F'))
	{
		return true;
	}
	return false;
}
int main()
{
	FI;FO;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx)										ans+='1';
	else											ans+='0';
	
	if(sti(sr)==sti(sx) && ans[0]=='1')				ans+='1';
	else											ans+='0';
	
	if(check(sr,sx) && ans[1]=='1')					ans+='1';
	else											ans+='0';
	
	if(checkn(sr,sx) && ans[0]=='1' && ans[1]=='1')	ans+='1';
	else											ans+='0';
	
	cout<<ans<<endl;
	return 0;
}
