#include<bits/stdc++.h>
using namespace std;
string c1,s1;
string c2,s2;
int sr,sx;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<"1";
	for(int i=0;i<=1;i++)
	{
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	sr=s1[2]-64;
	sx=s2[2]-64;
	if(sr<=3&&sx<=3)
	{
		cout<<"1";
	}
	else if(sr>3&&sx>3)
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if((sr==1&&sx==2)||(sx==1&&sr==2))
	{
		cout<<"1";
	}
	else if((sr==2&&sx==3)||(sx==3&&sr==2))
	{
		cout<<"1";
	}
	else if((sr==4&&sx==6)||(sx==6&&sr==4))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}



