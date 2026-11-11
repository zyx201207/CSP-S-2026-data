#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
string c1,s1,c2,s2;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;cin>>s1;
	cin>>c2;cin>>s2;
	if(c1==c2) cout<<"1";
	else cout<<"0";
	if(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1])) cout<<"1";
	else cout<<"0";
	if(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1]))
	{
		if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='E'&&s1[2]<='F'&&s2[2]>='E'&&s2[2]<='F'))
			cout<<"1";
		else cout<<"0";
	}
	else cout<<"0";
	if(c1==c2&&(s1[0]==s2[0]&&s1[1]==s2[1]))
	{
		if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='E'&&s1[2]<='F'&&s2[2]>='E'&&s2[2]<='F'))
		{
			if(s1[2]=='A'&&s2[2]=='B') cout<<"1";
			else if(s1[2]=='B'&&s2[2]=='A') cout<<"1";
			else if(s1[2]=='B'&&s2[2]=='C') cout<<"1";
			else if(s1[2]=='C'&&s2[2]=='B') cout<<"1";
			else if(s1[2]=='E'&&s2[2]=='F') cout<<"1";
			else if(s1[2]=='F'&&s2[2]=='E') cout<<"1";
			else cout<<"0";
		}
		else cout<<"0";
	}
	else cout<<"0";
	return 0;
}
