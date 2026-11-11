#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f[5];
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		f[1]=1;
		bool flag=1;
		for(int i=0;i<2;++i)
			if(s1[i]!=s2[i])flag=0;
		f[2]=flag;
		if(flag)
		{
			if((s1[2]=='A'&&s2[2]=='B')||
			(s1[2]=='A'&&s2[2]=='C')||
			(s1[2]=='B'&&s2[2]=='C')||
			(s2[2]=='A'&&s1[2]=='B')||
			(s2[2]=='A'&&s1[2]=='C')||
			(s2[2]=='B'&&s1[2]=='C')||
			(s2[2]=='D'&&s1[2]=='F')||
			(s2[2]=='F'&&s1[2]=='D'))
			{
				f[3]=1;
				if((s1[2]=='A'&&s2[2]=='B')||
				(s1[2]=='B'&&s2[2]=='C')||
				(s2[2]=='A'&&s1[2]=='B')||
				(s2[2]=='B'&&s1[2]=='C')||
				(s2[2]=='D'&&s1[2]=='F')||
				(s2[2]=='F'&&s1[2]=='D'))f[4]=1;
			}
		}
	}
	cout<<f[1]<<f[2]<<f[3]<<f[4];
	return 0;
}
