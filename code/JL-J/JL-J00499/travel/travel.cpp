#include <bits/stdc++.h>
using namespace std;
string s,ss,t,tt;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>ss>>t>>tt;
	if(s==t)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	int cnt=0;
	for(int i=0;i<=1;i++)
	{
		if(ss[i]==tt[i])
		{
			cnt++;
		}
	}
	if(cnt==2)
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	char f=ss[2];
	char ff=tt[2];
	if(f>='A' && f<='C')
	{
		if(ff>='D' && ff<='F')
		{
			cout<<"00";
			return 0;
		}
	}
	else if(f>='D' && f<='F')
	{
		if(ff>='A' && ff<='C')
		{
			cout<<"00";
			return 0;
		}
	}
	cout<<1;
	if((f=='A' && ff=='B') || (f=='B' && ff=='A'))
	{
		cout<<1;
		return 0;
	}
	if((f=='B' && ff=='C') || (f=='C' && ff=='B'))
	{
		cout<<1;
		return 0;
	}
	if((f=='D' && ff=='F') || (f=='F') && (ff=='D'))
	{
		cout<<1;
		return 0;
	}
	cout<<0;
	return 0;
}
