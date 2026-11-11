#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans;
	int a1,a2,b1,b2;
	char ch1,ch2;
	cin>>c1>>s1>>c2>>s2;
	a1=(c1[0]-'0')*10+(c1[1]-'0');
	a2=(c2[0]-'0')*10+(c2[1]-'0');
	b1=(s1[0]-'0')*10+(s1[1]-'0');
	b2=(s2[0]-'0')*10+(s2[1]-'0');
	ch1=s1[2];
	ch2=s2[2];
	if(a1!=a2)
	{
		ans="0000";
	}
	else
	{
		if(b1!=b2)
		{
			ans="1000";
		}
		else
		{
			if('A'<=ch1&&ch1<='C'&&'A'<=ch2&&ch2<='C')
			{
				if(ch1>ch2)
				{
					swap(ch1,ch2);
				}
				if(ch2-ch1>1)
				{
					ans="1110";
				}
				else
				{
					ans="1111";
				}
			}
			else if('D'<=ch1&&ch1<='F'&&'D'<=ch2&&ch2<='F')
			{
				ans="1111";
			}
			else
			{
				ans="1100";
			}
		}
	}
	cout<<ans;
	return 0;
}