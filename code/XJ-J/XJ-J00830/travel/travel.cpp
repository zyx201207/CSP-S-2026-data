#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
    freopen("rravel.out","w",stdout);
	int xx;
	int yy;
	int b;
	char a;
	int c;
	char d;
	cin>>xx>>b>>a>>yy>>c>>d;
	int x=(int)a;
	int y=(int)d;
    int j=0;
	int s=0;
	int h=0;
	int q=0;
	if(xx==yy)
	{
		j=1;
	}
	if(xx==yy && b==c)
	{
		s=1;
	}
	if(y>=68)              
	{
		if(x>=68 && s==1)
		{
			h=1;
		}
	}
	else
	{
		if(x<68 && xx==yy && b==c)
		{
			h=1;
		}
	}
	if(j==1 && s==1 && h==1)
	{
		if(y-x==1 || x-y==1)	
		{
			q=1;
		}
	}
	cout<<j<<s<<h<<q;
	fclose(stdin);
	fclose(stdout);
	return 0;
}