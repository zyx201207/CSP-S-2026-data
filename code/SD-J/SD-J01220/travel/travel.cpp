#include<bits/stdc++.h>
using namespace std;
char can1[12][3]={{'A','B'},{'B','A'},{'A','C'},{'C','A'},{'C','B'},{'B','C'},{'D','F'},{'F','D'}};
char can2[10][3]={{'A','B'},{'B','A'},{'C','B'},{'B','C'},{'D','F'},{'F','D'}};
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char wei1,wei2;
	cin>>c1>>s1>>wei1>>c2>>s2>>wei2;
	if (c1==c2) cout<<1;
	else cout<<0;
	if (c1==c2 && s1==s2) cout<<1;
	else cout<<0;
	if (c1==c2 && s1==s2)
	{
		bool flag=0;
		for (int i=0;i<8;i++)
		{
			if (wei1==can1[i][0] && wei2==can1[i][1])
			{
				flag=1;
				break;
			}
		}
		if (flag) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if (c1==c2 && s1==s2)
	{
		bool flag=0;
		for (int i=0;i<6;i++)
		{
			if (wei1==can2[i][0] && wei2==can2[i][1])
			{
				flag=1;
				break;
			}
		}
		if (flag) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
