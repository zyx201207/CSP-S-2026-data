#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			cout<<"1";
			bool b1=true,b2=true;
			if(s1[2]=='F'||s1[2]=='D') b1=false;
			if(s2[2]=='F'||s2[2]=='D') b2=false;
			if(b1==b2)
			{
				cout<<"1";
				if(abs(s1[2]-s2[2])==1)
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
