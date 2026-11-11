#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
int main()
{
	int ans1=0,ans2=0,ans3=0,ans4=0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			ans2=1;
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
			{
				ans3=1;
				if(abs(s1[2]-s2[2])==1)
				{
					ans4=1;
				}
			}
			if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
			{
				ans3=1;
				if(abs(s1[2]-s2[2])==1)
				{
					ans4=1;
				}
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;	
} 
