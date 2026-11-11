#include<bits/stdc++.h>
//#define int long long
using namespace std;
int c1,c2;//车厢号 
string st1,st2;
int s1,s2;//第几排
int p1,p2;//几号位 
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>st1>>c2>>st2;
	s1=(st1[0]-'0')*10+(st1[1]-'0');
	s2=(st2[0]-'0')*10+(st2[1]-'0');
	p1=st1[2]-'A';
	p2=st2[2]-'A';
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(s1!=s2)
	{
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((p1<=2)!=(p2<=2))
	{
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(abs(p1-p2)==1)
	{
		if(min(p1,p2)==2 && max(p1,p2)==3)
		{
			cout<<"0";
		}
		else
		{
			cout<<"1";
		}
	}
	else
	{
		cout<<"0";
	}
	return 0;
}

