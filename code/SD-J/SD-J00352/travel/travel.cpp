#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,x1,x2;
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++)
	{
		x1[i]=s1[i];
		x2[i]=s2[i];
    } 
	if(c1!=c2)
	{
		cout <<"0000";
	}
	else if(x1!=x2)
	{
		cout <<"1000";//02 02B 02 01A
	}
	else if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'))
	{
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'))
		{
			cout <<"1111";
		}
		else if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
		{
			cout <<"1111";
		}
		else
		{
			cout <<"1110";
	    }
	}
	else
	{
		cout <<"1100";
	}
	return 0;
 } 
