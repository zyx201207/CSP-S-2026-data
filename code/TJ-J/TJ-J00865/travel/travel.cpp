#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string ans;
int i,j;
char a[7]={'A','B','C','Z','D','F'};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		ans+="1";
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			ans+="1";
			for(i=0;i<6;i++)
			{
				if(a[i]==s1[2])
				{
					break;
				}
			}
			for(j=0;j<6;j++)
			{
				if(a[j]==s2[2])
				{
					break;
				}
			}
			if(i<3&&j<3)
			{
				ans+="1";
				if(abs(i-j)==1)
				{
					ans+="1";
				}
				else
				{
					ans+="0";
				}
			}
			else if(i>3&&j>3)
			{
				ans+="11";
			}
			else
			{
				ans+="00";
			}
		}
		else
		{
			ans+="000";
		}
	}
	else
	{
		ans+="0000";
	}
	cout << ans;
	return 0;
}
