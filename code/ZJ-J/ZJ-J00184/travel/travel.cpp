//shuaiyuchenbianxie
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ss1,ss2;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	ss1=int(s1[0])*10+int(s1[1]);
	ss2=int(s2[0])*10+int(s2[1]);
	if(c1=="1"||c1=="16"||c2=="1"||c2=="16")
	{
		cout<<"0000";
		return 0;
	}
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(c1==c2)
	{
		if(ss1==ss2)
		{
			int flag1,flag2;
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')flag1=1;
			else flag1=2;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')flag2=1;
			else flag2=2;
			if(flag1==flag2)
			{
				if(abs(int(s1[2])-int(s2[2]))==1)
				{
					cout<<"1111";
					return 0;
				}
				else 
				{
					cout<<"1110";
					return 0;
				}
			}
			else
			{
				cout<<"1100";
				return 0;
			}
		}
		else
		{
			cout<<"1000";
			return 0;
		}
	}
	return 0;
}
