#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int p1=0,p2=0,p3=0,p4=0;
	if(c1==c2)
	{
		p1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			p2=1;
			int si1=-1,si2=-1;
			if(s1[2]=='D'||s1[2]=='F')
				si1=1;
			else
				si1=0;
			if(s2[2]=='D'||s2[2]=='F')
				si2=1;
			else
				si2=0;
			if(si1==si2)
			{
				p3=1;
				if(si1==1)
				{
					if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))
					{
						p4=1;
					}
					
				}
				if(si1==0)
				{
					if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'))
					{
						p4=1;
					}
				}
				
			}
		}
	}
	
	cout<<p1<<p2<<p3<<p4;
	return 0;
}