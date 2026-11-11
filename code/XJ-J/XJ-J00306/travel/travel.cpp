#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool ans[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		ans[0]=1;	
	}
	else
	{
		ans[0]=0;
	}
	bool flag=false;
	for(int i=0;i<=1;i++)
	{
		if(s1[i]==s2[i])
		{
			flag=true;
		}
		else
		{
			flag=false;
		}
	}
	if(flag==true)
	{
		ans[1]=1;
	}
	else
	{
		ans[1]=0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'c'&&s2[2]>'c')&&flag==true)
	{
		ans[2]=1;
	}
	else
	{
		ans[2]=0;
	}
	if((abs(s1[2]-s2[2])==1)&&(s1[2]<='C'&&s2[2]<='C')||(s1[2]>'c'&&s2[2]>'c')&&flag==true)
	{
		ans[3]=1;
	}
	else
	{
		ans[3]=0;
	}
	for(int i=0;i<=3;i++)
	{
		cout<<ans[i];
	}

	return 0;
 } 
