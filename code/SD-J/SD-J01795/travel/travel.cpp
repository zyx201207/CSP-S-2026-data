#include<bits/stdc++.h>
using namespace std;
string cr,cx,sr,sx,s;
long long n;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long i,j;
	s[0]='0';
	s[1]='0';
	s[2]='0';
	s[3]='0';
	cin>>cr>>sr>>cx>>sx;
	if(cr[0]==cx[0]&&cr[1]==cx[1])
	{
		s[0]='1';
		if(sr[0]==sx[0]&&sr[1]==sx[1])
		{
			s[1]='1';
			if(sr[2]>='D'&&sx[2]>='D')
			{
				s[2]='1';
				s[3]='1';
			}	
			else if(sr[2]<='C'&&sx[2]<='C')
			{
				s[2]='1';
				if(sr[2]=='A'&&sx[2]=='C')
				{
					s[3]='0';
				}
				else if(sr[2]=='C'&&sx[2]=='A')
				{
					s[3]='0';
				}
				else
				{
					s[3]='1';
				}
			}
		}
	}
	
	for(i=0;i<=3;i++)
	{
		cout<<s[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
