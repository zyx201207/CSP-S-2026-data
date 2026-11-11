#include <bits/stdc++.h>
using namespace std;
int main()
{freopen("r","travel.in",stdin);
	freopen("w","travel.out",stdout);
	string c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	int rpai=c2[0]+c2[1];
	int xpai=c4[0]+c4[1];
	if(c1!=c3)
	{cout<<0000;
		};
	if(c1==c3)
	{cout<<1;
		if(rpai==xpai);
	{cout<<1;
		if(c2[2]=='A')
		{if(c4[2]==c2[2]+1||c4[2]==c2[2]+2)
			{cout<<1;
			if(c4[2]==c2[2]+2)
			{cout<<0;};
			if(c4[2]==c2[2]+1)
			{cout<<1;};		
				};
				
			}
			if(c2[2]=='B')
		{if(c4[2]==c2[2]+1||c4[2]==c2[2]-1)
			{cout<<1;};};
			if(c2[2]=='C')
		{if(c4[2]==c2[2]-1||c4[2]==c2[2]-2)
			{cout<<1;};
			if(c4[2]==c2[2]-2)
			{cout<<0;}
			if(c4[2]==c2[2]-1)
			{cout<<1;}		
				};
				
			};
			
			if(c2[2]=='D')
			{if(c2[2]+1==c4[2])
				{cout<<11;};
				if(c2[2]+1!=c4[2])
				{cout<<00;};
				}
				if(c2[2]=='E')
			{if(c2[2]-1==c4[2])
				{cout<<11;};
				if(c2[2]-1!=c4[2])
				{cout<<00;};
				}
		}
	if(rpai!=xpai)
	{cout<<000;};
		
	return 0;
		
	};
