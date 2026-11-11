#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;
int c,cc;string s,ss;bool flag=true;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c>>s>>cc>>ss;
	if(c==cc)
	{
		cout<<"1";
		for(int i=0;i<max(s.length(),ss.length());i++)
		{
			if(s[i]>='0'&&s[i]<='9'&&ss[i]>='0'&&ss[i]<='9')
			{
				if(s[i]!=ss[i])
				{
					cout<<"000";
					flag=false;
					return 0;
				}	
				else	continue;
			}
		}
		if(flag)
		{
			cout<<"1";
			if((s[s.length()-1]>='A'&&s[s.length()-1]<='C'&&ss[ss.length()-1]>='A'&&ss[ss.length()-1]<='C')||(s[s.length()-1]>='D'&&s[s.length()-1]<='F'&&ss[ss.length()-1]>='D'&&ss[ss.length()-1]<='F'))
			{
				cout<<"1";
				if(max(s[s.length()-1]-'0',ss[ss.length()-1]-'0')-min(s[s.length()-1]-'0',ss[ss.length()-1]-'0')==1)	cout<<"1";
				else 	cout<<"0";
			}
			else
			{
				cout<<"00";
				return 0;
			}	
		}
	}
	else	cout<<"0000";
	return 0;
 } 
