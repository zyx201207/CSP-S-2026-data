#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans=0,ans1=0;
	ans=(c1[0]-'0')*10+c1[1]-'0';
	ans1=(c2[0]-'0')*10+c2[1]-'0';
	if(ans==ans1)
	{
		ans=(s1[0]-'0')*10+s1[1]-'0';
		ans1=(s2[0]-'0')*10+s2[1]-'0';
		if(ans==ans1)
		{
			ans=s1[2]-'A';
			ans1=s2[2]-'A';
			if(ans<3&&ans1<3||ans>=3&&ans1>=3)
			{
				if(ans==0&&ans1==1||ans==1&&ans1==0||ans==1&&ans1==2||ans==2&&ans1==1||ans==3&&ans1==1||ans==1&&ans1==3)
				{
					cout<<"1111";
				}
				else
				{
					cout<<"1110";
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
	else
	{
		cout<<"0000";
		return 0;
	}
	return 0;
}
