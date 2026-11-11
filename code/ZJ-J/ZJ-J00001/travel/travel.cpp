#include<bits/stdc++.h>
using namespace std;
string s[5];//score 100
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s[1]>>s[2]>>s[3]>>s[4];
	if(s[1]==s[3])
	{
		cout<<'1';
		if(s[2][0]==s[4][0]&&s[2][1]==s[4][1])
		{
			cout<<'1';
			if('A'<=s[2][2]&&s[2][2]<='C')
			{
				if('A'<=s[4][2]&&s[4][2]<='C')
				{
					cout<<'1';
					int nums=s[2][2]-'A';
					int nums2=s[4][2]-'A';
					if(abs(nums-nums2)==1)
					{
						cout<<'1';
					}
					else
					{
						cout<<'0';
					}
				}
				else
				{
					cout<<"00";
				}
			}
			else if('D'<=s[2][2]&&s[2][2]<='F')
			{
				if('D'<=s[4][2]&&s[4][2]<='F')
				{
					cout<<'1';
					int nums=s[2][2]-'A';
					int nums2=s[4][2]-'A';
					if(abs(nums-nums2)==1)
					{
						cout<<'1';
					}
					else
					{
						cout<<'0';
					}
				}
				else
				{
					cout<<"00";
				}				
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
