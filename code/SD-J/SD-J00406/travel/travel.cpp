#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string aa,bb,cc,dd;
	cin>>aa>>bb>>cc>>dd;
	if(aa==cc)
	{
		cout<<1;
		if(bb[0]==dd[0]&&bb[1]==dd[1])
		{
			cout<<1;
			if((bb[2]=='A'||bb[2]=='B'||bb[2]=='C')&&(dd[2]=='A'||dd[2]=='B'||dd[2]=='C'))
			{
				cout<<1;
				if(dd[2]-bb[2]==1||dd[2]-bb[2]==-1)
				{
					cout<<1;
				}
				else
				{
					cout<<0;
				}
			}
			else if((bb[2]=='D'||bb[2]=='E')&&(dd[2]=='D'||dd[2]=='E'))
			{
				cout<<1;
				if(dd[2]-bb[2]==1||dd[2]-bb[2]==-1)
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
				cout<<0<<0;
			}
		}
		else
		{
			cout<<0<<0<<0;
		}
	} 
	else
	{
		cout<<0<<0<<0<<0;
	}
	
	return 0;
} 
