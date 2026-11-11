#include <bits/stdc++.h>
using namespace std;
struct s{
	int h;
	string se;
};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	s s1,s2;
	cin>>s1.h>>s1.se>>s2.h>>s2.se;
	if(s1.h==s2.h)
	{
		cout<<1;
		if(s1.se[0]+s1.se[1]==s2.se[0]+s2.se[1])
		{
			cout<<1;
			if((s1.se[2]<'D'&&s2.se[2]<'D')||(s1.se[2]>'C'&&s2.se[2]>'C'))
			{
				cout<<1;
				if((s1.se[2]=='B'||s2.se[2]=='B')||(s1.se[2]=='D'||s2.se[2]=='D'))
				{
					cout<<1;
					return 0;
				}
				else
				{
					cout<<"0";
					return 0;
				}
			
			}
			cout<<"00";
			return 0;
		}
		cout<<"000";
		return 0;
	}
	cout<<"0000";
	return 0;
}
