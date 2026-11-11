#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans1,ans2,ans3,ans4;
char a[105][1005],b[105][1005];
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a[1][1]>>a[1][2]>>a[2][1]>>a[2][2]>>a[2][3];
	cin>>b[1][1]>>b[1][2]>>b[2][1]>>b[2][2]>>b[2][3];
	if(a[1][1]==b[1][1]&&a[1][2]==b[1][2])
	{
		ans1=1;
		if(a[2][1]==b[2][1]&&a[2][2]==b[2][2])
		{
			ans2=1;
			if((a[2][3]>='D'&&a[2][3]<='F'&&b[2][3]>='D'&&b[2][3]<='F')||(a[2][3]>='A'&&a[2][3]<='C'&&b[2][3]>='A'&&b[2][3]<='C'))
			{
				ans3=1;
				if((a[2][3]=='A'&&b[2][3]=='B')||(a[2][3]=='B'&&b[2][3]=='A')||(a[2][3]=='B'&&b[2][3]=='C')||(a[2][3]=='C'&&b[2][3]=='B')||(a[2][3]=='D'&&b[2][3]=='F')||(a[2][3]=='F'&&b[2][3]=='D'))
				{
					ans4=1;
				}
				else
				{
					ans4=0;
				}
			}
			else
			{
				ans3=0;
				ans4=0;
			}
		}
		else
		{
			ans2=0;
			ans3=0;
			ans4=0;
		}
	}
	else
	{
		ans1=0;
		ans2=0;
		ans3=0;
		ans4=0;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
