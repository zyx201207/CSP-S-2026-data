#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int a[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s",c1);
	scanf("%s",s1);
	scanf("%s",c2);
	scanf("%s",s2);
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		a[1]=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&a[1]==1)
	{
		a[2]=1;
	}
	if(s1[2]<='C'&&s2[2]<='C'&&a[1]==1&&a[2]==1)
	{
		a[3]=1;
		if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
		{
			if(a[1]==1&&a[2]==1&&a[3]==1)
			{
				a[4]=1;
			}
		}
	}
	else
	{
		if(s1[2]>='D'&&s2[2]>='D'&&a[1]==1&&a[2]==1)
		{
			a[3]=1;
			a[4]=1;
		}
	}
	for(int i=1;i<=4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
