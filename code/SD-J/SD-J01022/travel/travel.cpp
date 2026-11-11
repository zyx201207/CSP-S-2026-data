#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,cc,ss;
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(s[0]+s[1]==ss[0]+ss[1]&&c==cc)
	{
		cout<<1;
		
	}
	else
	{
		cout<<0;
	}
	if(s[0]+s[1]==ss[0]+ss[1]&&c==cc&&((s[2]<='C'&&ss[2]<='C')||s[2]>='D'&&ss[2]>='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	if(abs(s[2]-ss[2])==1&&s[0]+s[1]==ss[0]+ss[1]&&c==cc&&((s[2]<='C'&&ss[2]<='C')||s[2]>='D'&&ss[2]>='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
