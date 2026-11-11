#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int ca,cb;
	string sa,sb;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb)
	{
		cout<<1;
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(sa[sa.size()-3]==sb[sb.size()-3] && sa[sa.size()-2]==sb[sb.size()-2])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if(sa[sa.size()-1]=='A' && (sb[sb.size()-1]=='B' || sb[sb.size()-1]=='C'))
	{
		cout<<1;
	}
	else if(sa[sa.size()-1]=='B' && (sb[sb.size()-1]=='A' || sb[sb.size()-1]=='C'))
	{
		cout<<1;
	}
	else if(sa[sa.size()-1]=='C' && (sb[sb.size()-1]=='A' || sb[sb.size()-1]=='B'))
	{
		cout<<1;
	}
	else if(sa[sa.size()-1]=='D' && sb[sb.size()-1]=='F')
	{
		cout<<1;
	}
	else if(sa[sa.size()-1]=='F' && sb[sb.size()-1]=='D')
	{
		cout<<1;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((sa[sa.size()-1]=='A' && sb[sb.size()-1]=='B') || (sa[sa.size()-1]=='B' && sb[sb.size()-1]=='A'))
	{
		cout<<1;
	}
	else if((sa[sa.size()-1]=='B' && sb[sb.size()-1]=='C') || (sa[sa.size()-1]=='C' && sb[sb.size()-1]=='B'))
	{
		cout<<1;
	}
	else if((sa[sa.size()-1]=='D' && sb[sb.size()-1]=='F') || (sa[sa.size()-1]=='F' && sb[sb.size()-1]=='D'))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	return 0;
}

