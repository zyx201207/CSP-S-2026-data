#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int ca,cb,s1,s2;
	char ch1,ch2;
	scanf("%2d %2d%c %2d %2d%c",&ca,&s1,&ch1,&cb,&s2,&ch2);
	if(ca==cb) cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1==s2) cout<<"1";
	else
	{
		cout<<"000";
		return 0;
	}
	if((ch1<='C'&&ch2<='C')||(ch1>='D'&&ch2>='D'))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(int(ch1-ch2))==1)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}
