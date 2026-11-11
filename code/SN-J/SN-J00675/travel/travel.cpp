//钟林希 西安翱翔中学 SN-J00675 
#include<bits/stdc++.h>
using namespace std;
string s[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	if(s[1]==s[3])
	{
		cout<<1;
		if(s[2][0]==s[4][0]&&s[2][1]==s[4][1])
		{
			cout<<1;
			if(s[2][2]<='C'&&s[4][2]<='C')cout<<1;
			else if(s[2][2]>'C'&&s[4][2]>'C')cout<<1;
			else
			{
				cout<<"00";
				return 0;
			}
			if(abs(s[2][2]-s[4][2])==1)cout<<1;
			else cout<<0;
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
