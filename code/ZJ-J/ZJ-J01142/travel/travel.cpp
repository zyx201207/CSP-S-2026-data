#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int da1,da2,da3,da4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) da1=1;
	else da1=0;
	
	if(da1==0) da2=0;
	else
	{
		if(s1[0]==s2[0]&&s1[1]==s2[1]) da2=1;
		else da2=0;
	}
	
	if(da2==0) da3=0;
	else
	{
		if('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C') da3=1;
		else if('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F') da3=1;
		else da3=0;	
	}
	if(da3==0) da4=0;
	else
	{
		if(s1[2]=='A')
		{
			if(s2[2]=='B') da4=1;
			else da4=0;
		}
		else if(s1[2]=='B')
		{
			if(s2[2]=='A'||s2[2]=='C') da4=1;
			else da4=0;
		}
		else if(s1[2]=='C')
		{
			if(s2[2]=='B') da4=1;
			else da4=0;
		}
		else if(s1[2]=='D')
		{
			if(s2[2]=='F') da4=1;
			else da4=0;
		}
		else if(s1[2]=='D')
		{
			if(s2[2]=='F') da4=1;
			else da4=0;
		}
	}
	cout<<da1<<da2<<da3<<da4;
	return 0;
}
