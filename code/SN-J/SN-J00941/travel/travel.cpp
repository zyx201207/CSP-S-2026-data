#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,s1,s2,s3;
	cin>>s>>s1>>s2>>s3;
	if(s==s2)
	{
		cout<<"1";	
		if(s1[0]==s3[0]&&s1[1]==s3[1])
	{
		cout<<"1";	
		if(s1[2]+s3[2]<=133||s1[2]+s3[2]==138)
		{
				cout<<"1";
				if(s1[2]-1==s3[2]||s1[2]+1==s3[2])
				{
					cout<<"1";
				}
				else
				cout<<"0";
		}
		else
		cout<<"0"<<"0";
	}
	else
	cout<<"0"<<"0"<<"0";
	}
	else
	cout<<"0"<<"0"<<"0"<<"0";
return 0;
}
