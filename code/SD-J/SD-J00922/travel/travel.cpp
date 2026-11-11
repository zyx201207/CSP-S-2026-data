#include<bits/stdc++.h>
using namespace std;

char c1[5],s1[5],c2[5],s2[5];

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
		cout<<"1";
	else
	{
		cout<<"0000";
		return 0;
	}	
	int cnt=0;
	for(int i=0;i<=1;i++)
	{
		if(s1[i]==s2[i])
			cnt++;
		if(i==1)
		{
			if(cnt==2)
				cout<<"1";
			else
			{
				cout<<"000";
				return 0;
			}		
		}
	}
	if(s1[2]<='F'&&s1[2]>='D'&&s2[2]>='D'&&s2[2]<='F')
	{
		cout<<"11";
		return 0;
	}	
	if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
		cout<<"1";
	else
	{
		cout<<"00";
		return 0;
	}
	if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
		cout<<"1";
	else 
		cout<<"0";	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
