#include<bits/stdc++.h>
using namespace std;
char s1[5];
char s2[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	cin>>c1;
	for(int i=1;i<=3;i++)
	{
		cin>>s1[i];
	}
	cin>>c2;
	for(int i=1;i<=3;i++)
	{
		cin>>s2[i];
	}
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	
	if(s1[1]==s2[1]&&s1[2]==s2[2]&&c1==c2)
	{
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	
	if(s1[3]=='D'||s1[3]=='F')
	{
		if(s2[3]=='F'||s2[3]=='D')
		{	
				cout<<"1";		
		}
		else
		{
			cout<<"0";
		}
		if((s1[3]=='D'&&s2[3]=='F')||(s1[3]=='F'&&s1[3]=='D'))
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	else if(s1[3]=='A'||s1[3]=='B'||s1[3]=='C')
	{	
			if(s2[3]=='A'||s2[3]=='B'||s2[3]=='C')
		{
				cout<<"1";
		}
		else
		{
			cout<<"0";
		}	
		if((s1[3]+1==s2[3])||(s1[3]-1==s2[3]))
		{
		   if((s1[3]+1)!='D'&&(s1[3]-1)!='A')
		   {
		   	cout<<"1";
		   }
		   else
		   {
		   	cout<<"0";
		   }
		}
	}
	return 0;
}