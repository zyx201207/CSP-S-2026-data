#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int main()
{	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x,y,num,sum;
	cin >> x >> num >> y >> sum;
	bool s1,s2,s3,s4;
	char a=num[2],b=sum[2],c=num[1],d=sum[1];
	if(x != y)
	{
		s1 = 0;
		s2 = 0;
		s3 = 0;
		s4 = 0;
	}
	else
	{
		if(c == d)
		{
			if(a == 'A' && b == 'B')
			{
				s1=1;
				s2=1;
				s3=1;
				s4=1;
			}
			else if(a == 'B' && b == 'A')
			{
				s1=1;
				s2=1;
				s3=1;
				s4=1;
			}
			else if(a == 'B' && b == 'C') 
			{
				s1=1;
				s2=1;
				s3=1;
				s4=1;
			}
			else if(a == 'C' && b == 'B')
			{
				s1=1;
				s2=1;
				s3=1;
				s4=1;
			}
			else if (a == 'D' && b == 'F')
			{
				s1=1;
				s2=1;
				s3=1;
				s4=1;
			}
			else if (a == 'F' && b == 'D')
			{
				s1=1;
				s2=1;
				s3=1;
				s4=1;
			}
			else
			{
				if(a == 'A' && b=='C')
				{
					s1 = 1;
					s2 = 1;
					s3 = 1;
				}
				else if(a == 'C' && b=='A')
				{
					s1 = 1;
					s2 = 1;
					s3 = 1;
				}
				else if(a == 'C' && b == 'D')
				{
					s1=1;
					s2=1;
				}
				else if(a == 'D' && b == 'C')
				{
					s1=1;
					s2=1;
				}
			}
		}
		else
		{
			s1=1;
		}	
		
	}
	cout << s1 << s2 << s3 << s4;
	return 0;
}