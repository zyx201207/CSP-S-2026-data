#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,cnt=0;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=1&&c1!=16)
	{
		if(c2!=1&&c2!=16)
		cout<<1;
		else
		cout<<0;
	}
	else
	cout<<0;
	
	if(c1==c2)
	cout<<1;
	else
	cout<<0;
	
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		if('A'<=s1[2]&&s1[2]<='C')
		{
			if('A'<=s2[2]&&s2[2]<='C')
			{
				cout<<1;
				cnt=1;
			}
			else
			cout<<0;
		}
		if('D'==s1[2]||s1[2]=='F')
		{
			if('D'==s2[2]||s2[2]=='F')
			{
				cout<<1;
				cnt=1;
			}
			else
			cout<<0;
		}
	}
	else
	cout<<0;
	
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
	{
		if(cnt==1)
		cout<<1;
		else
		cout<<0;
	}
	else
	cout<<0;
	return 0;
}
	
