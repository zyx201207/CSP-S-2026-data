#include<bits/stdc++.h>
using namespace std;
char a[5];
int main()
{
	fropen("travel.in","r",stdin);
	fropen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		a[1]='1';
	}
	else 
	{
		a[1]='0';
		a[4]='0';
	}	
	if(s2[0]==s1[0]&&s2[1]==s1[1]&&a[1]=='1')
	{
		a[2]='1';
	}
	else a[2]='0';
	if((s1[2]-'A'+1==s2[2]-'A')||(s1[2]-'A'==s2[2]-'A'+1))
		{
			if(a[2]=='1')
			{
				a[3]='1';
				a[4]='1';
			}
			else 
			{
				a[3]='0';
				a[4]='0';
			}
			if((s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B'))
			{
				a[3]='0';
				a[4]='0';
			}
		}
	else 
	{
		a[3]='0';
		a[4]='0';
	}
	
	for(int i=1;i<=4;i++)
	{
		cout<<a[i];
	}
	return 0;
}
