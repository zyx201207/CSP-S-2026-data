#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss,qly;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		qly+='1';
	}
	else
	{
		qly+='0';
	}
	if(c==cc&&s[0]+s[1]==ss[0]+ss[1])
	{
		qly+='1';
	}
	else
	{
		qly+='0';
	}
	if(c==cc&&s[0]+s[1]==ss[0]+ss[1]&&((s[2]=='F'&&ss[2]=='D')||(s[2]=='D'&&ss[2]=='F')||(s[2]=='A'&&ss[2]=='B')||(s[2]=='A'&&ss[2]=='C')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='C'&&ss[2]=='A')||(s[2]=='C'&&ss[2]=='B')))
	{
		qly+='1';
	}
	else
	{
		qly+='0';
	}
	if(c==cc&&s[0]+s[1]==ss[0]+ss[1]&&((s[2]=='F'&&ss[2]=='D')||(s[2]=='D'&&ss[2]=='F')||(s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='C'&&ss[2]=='B')))
	{
		qly+='1';
	}
	else
	{
		qly+='0';
	}
	cout<<qly;
	return 0;
}