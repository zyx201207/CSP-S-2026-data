#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			char a1=s1[2],a2=s2[2];
			if(a1<=67&&a2<=67||a1>=68&&a2>=68)
			{
				if((a1+1==a2||a1-1==a2)||((a1==68&&a2==70)||(a2==68&&a1==70)))
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
				}
			}
			else
			{
				cout<<"1100";
			}
		}
		else
		{
			cout<<"1000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
