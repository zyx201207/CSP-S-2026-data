#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,s3,s4;
int ans1,ans2,ans3,ans4;
int getnum(char ch)
{
	if(ch=='A') return 1;
	if(ch=='B') return 2;
	if(ch=='C') return 3;
	if(ch=='D') return 4;
	return 5;
}
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	ans1=0;
	ans2=0;
	ans3=0;
	ans4=0;
	if(s1==s3) 
	{
		ans1=1;
		if((s2[0]==s4[0])&&(s2[1]==s4[1]))
		{
			ans2=1;
			int p1=getnum(s2[2]),p2=getnum(s4[2]);
			if(((p1>=1)&&(p1<=3))&&((p2>=1)&&(p2<=3)))
			{
				ans3=1;
				if((p1-p2==1)||(p2-p1==1))
				{
					ans4=1;
				}
			}
			else
			{
				if(((p1>=4)&&(p1<=5))&&((p2>=4)&&(p2<=5)))
				{
					ans3=1;
					ans4=1;
				}
			}
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
