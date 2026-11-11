#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool f,f1=false,f2=false,f3=false;
	f=true;
	for(int i=0;i<2;i++)
	{
		if(c1[i]!=c2[i])
		{
			cout<<0;
			f=false;
			break;
		}
	}
	if(f==true)
	{
		cout<<1;
		f1=true;
	}
	f=true;
	if(f1==true)
	{
		for(int i=0;i<2;i++)
		{
			if(s1[i]!=s2[i])
			{
				cout<<0;
				f=false;
				break;
			}
		}
		if(f==true)
		{
			cout<<1;
			f2=true;
		}
		f=true;
	}
	else
	{
		cout<<0;
	}
	if(f1==true&&f2==true)
	{
		if(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'&&s1[2]!=s2[2])||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	if(f1==true&&f2==true)
	{
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		cout<<0;
	}
	cout<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
