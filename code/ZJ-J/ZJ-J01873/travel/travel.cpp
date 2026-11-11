#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
bool flag;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		for(int i=0;i<=1;i++)
			if(s1[i]!=s2[i])
				flag=1;
		if(flag)
			cout<<"000";
		else
		{
			cout<<"1";
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||
			(s1[2]>='D'&&s1[2]<='F'&&s1[2]!='E'&&s2[2]>='D'&&s2[2]<='F'&&s2[2]!='E'))
				cout<<"1";
			else
				cout<<"0";
			if(abs(s1[2]-s2[2])==1&&((s1[2]!='C'&&s2[2]!='D')||(s2[2]!='C'&&s1[2]!='D')))
				cout<<"1";
			else
				cout<<"0";
		}
	}
	else
		cout<<"0000";
	return 0;
}