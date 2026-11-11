#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int e[5];
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		e[1]=1;
		if(b[0]==d[0]&&b[1]==d[1])
		{
			e[2]=1;
			if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='F'))|((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='D'||b[2]=='F')))
			{
				e[3]=0;
				e[4]=0;
			}
			else 
			{
				e[3]=1;
				if(b[2]==d[2]+1||d[2]==b[2]+1)
				{
					e[4]=1;
				}
				else e[4]=0;
			}
		}
		else 
		{
			e[2]=0;
			e[3]=0;
			e[4]=0;
		}
	}
	else 
	{
		e[1]=0;
		e[2]=0;
		e[3]=0;
		e[4]=0;
	}
	cout<<e[1]<<e[2]<<e[3]<<e[4];
	return 0;
}



