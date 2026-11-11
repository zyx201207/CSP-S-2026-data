#include<bits/stdc++.h>
using namespace std;
string c[10],s[10];
bool a[10];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2])
	{
		a[1]=1;
		if(s[1][0]==s[2][0]&&s[1][1]==s[2][1])
		{
			a[2]=1;
			if(s[1][2]>='A'&&s[1][2]<='C')
			{
				if(s[2][2]>='A'&&s[2][2]<='C')
				{
					a[3]=1;
					if(s[1][2]=='B'||s[2][2]=='B')
					{
						a[4]=1;
					}
				}
			}
			else if(s[1][2]=='D'||s[1][2]=='F')
			{
				if(s[2][2]=='D'||s[2][2]=='F')
				{
					a[3]=1;
					a[4]=1;
				}
			}
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}
