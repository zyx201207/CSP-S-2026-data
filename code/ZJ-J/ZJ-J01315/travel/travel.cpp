#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]) cout<<"0000";
	else
	{
		if(s1[0]!=s2[0]||s1[1]!=s2[1]) cout<<"1000";
		else
		{
			if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>'C'&&s2[2]<='C')) cout<<"1100";
			else
			{
				char a=s1[2],b=s2[2];
				if(a=='F') a='E';
				if(b=='F') b='E';
				if(abs(a-b)!=1) cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	return 0;
}
