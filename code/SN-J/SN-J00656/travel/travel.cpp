//张宸轩 西安市第八中学 SN-J00656 
#include <bits/stdc++.h>
using namespace std;
#define int long long 
string c1,c2;
string s1,s2;
signed main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int da[10]={0,0,0,0,0,0,0,0,0,0};
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		da[1]=1;
		if (s1[0]+s1[1]==s2[0]+s2[1])
		{
			da[2]=1;
			if (s1[2]=='A' || s1[2]=='B' || s1[2]=='C') 
				if (s2[2]=='A' || s2[2]=='B' || s2[2]=='c')da[3]=1;
			else if (s1[2]=='D' || s1[2]=='F')
				if (s2[2]=='D' || s2[2]=='F') da[3]=1; 
		}
	}
	if (c1==c2) 
	{
		if (s1[2]=='A' || s1[2]=='B' || s1[2]=='C') 
		{
			if (s2[2]=='A' || s2[2]=='B' || s2[2]=='c')
			{
				if (s1[2]+1==s2[2] || s2[2]+1==s1[2])
				{
					if (s1[0]+s1[1]==s2[0]+s2[1])
					{
						da[4]=1;
					}
				}
				if (s1[2]==s2[2])
				{
					if (s1[0]+s1[1]==s2[0]+s2[1])
					{
						da[4]=1;
					}
				}
			}
		}
		else if (s1[2]=='D' || s1[2]=='F')
		{
			if (s2[2]=='D' || s2[2]=='F')
			{
				if (s2[2]=='A' || s2[2]=='B' || s2[2]=='c')
				{
					if (s1[2]+1==s2[2] || s2[2]+1==s1[2])
					{
						if (s1[0]+s1[1]==s2[0]+s2[1])
						{
							da[4]=1;
						}
					}
					if (s1[2]==s2[2])
					{
						if (s1[0]+s1[1]==s2[0]+s2[1])
						{
							da[4]=1;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<da[i];
	}
	return 0;
}
