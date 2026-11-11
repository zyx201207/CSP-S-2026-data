#include<bits/stdc++.h>
using namespace std;
int main()
{
	//姚元辰 SN-J00829 延安职业技术学院附属中学 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,d;
	string s,f;
	cin>>a>>s>>d>>f;
	if(a==d)
	{
		cout<<"1";
		if(s[0]!=f[0]||s[1]!=f[1])
		{
			cout<<"000"	;
			return 0;
		}
		if(s[0]==f[0]||s[1]==f[1])
		{
			cout<<"1";
		}
		else
		{
			cout<<"00";
			return 0;
		}
		if((s[2]<=99&&f[2]>=100)||(s[2]<=99&&f[2]>=100))
		{
			cout<<"00";
			return 0;
		}
		if((s[2]<=99&&f[2]<=99)||(s[2]>=100&&f[2]>=100))
		{
			cout<<"1";
			if((s[2]==97||s[2]==98)&&(f[2]==97||f[2]==98))
			{
				cout<<"1";
				return 0;
			}
			if((s[2]==100||s[2]==102)&&(f[2]==100||f[2]==102))
			{
				cout<<"1";
				return 0;
			}
			else
			{
				cout<<"0";
				return 0;
			}
		}
	}
	else
	{
		cout<<"0000";
		return 0;
	}
}
