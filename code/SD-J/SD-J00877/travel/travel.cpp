#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x=0,p=0,c=0,l=0;
	if(c1==c2)
	{
		x++;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			p++;
			int s3,s4;
			if(s1[2]>='A'&&s1[2]<='C') s3=1;
			else s3=2;
			if(s2[2]>='A'&&s2[2]<='C') s4=1;
			else s4=2;
			if(s3==s4)
			{
				c++;
				if(s3==2) l++;
				else
				{
					if(s1[2]=='B'||s2[2]=='B') l++;
				}
			}
		}
	}
	cout<<x<<p<<c<<l;
	return 0;
} 
