#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    bool chexiang=0,yipai=0,yice=0,xianglin=0;
    if(c1==c2)
    {
    	chexiang=1;
	}
	else
	{
		cout<<chexiang<<yipai<<yice<<xianglin;
		return 0;
	}
	if(s1[0]==s2[0])
	{
		if(s1[1]==s2[1])
		{
			yipai=1;
		}
	}
	else
	{
		cout<<chexiang<<yipai<<yice<<xianglin;
		return 0;
	}
	if(yipai==1)
	{
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C'))
		{
			yice=1;
		}
		else if((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C'))
		{
			yice=1;
		}
		else if((s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'))
		{
			yice=1;
		}
		else if(s1[2]=='D'&&s2[2]=='F')
		{
			yice=1;
		}
		else if(s1[2]=='F'&&s2[2]=='D')
		{
			yice=1;
		}
	}
	else
	{
		cout<<chexiang<<yipai<<yice<<xianglin;
		return 0;
	}
	if(yice==1)
	{
		if(s1[2]=='A'&&s2[2]=='B')
		{
			xianglin=1;
		}
		else if(s1[2]=='B'&&s2[2]=='A')
		{
			xianglin=1;
		}
		else if(s1[2]=='B'&&s2[2]=='C')
		{
			xianglin=1;
		}
		else if(s1[2]=='C'&&s2[2]=='B')
		{
			xianglin=1;
		}
		else if(s1[2]=='D'&&s2[2]=='F')
		{
			xianglin=1;
		}
		else if(s1[2]=='F'&&s2[2]=='D')
		{
			xianglin=1;
		}
	}
	else
	{
		cout<<chexiang<<yipai<<yice<<xianglin;
		return 0;
	}
	cout<<chexiang<<yipai<<yice<<xianglin;
    return 0;
}
