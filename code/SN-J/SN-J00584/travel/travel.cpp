#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,s1,s2;
	cin>>a1>>s1>>a2>>s2;
	bool bu[4];
	bu[0]=false;
	bu[1]=false;
	bu[2]=false;
	bu[3]=false;
	if(a1[0]==a2[0]&&a1[1]==a2[1])
	{
		bu[0]=true;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			bu[1]=true;
			if(s1[2]<=67&&s2[2]<=67||s1[2]>=68&&s2[2]>=68)
			{
				bu[2]=true;
				if(s1[2]-s2[2]==-1||s2[2]-s1[2]==-1)
				bu[3]=true;
			}
		}
	}
	cout<<bu[0]<<bu[1]<<bu[2]<<bu[3];
	return 0;
}
