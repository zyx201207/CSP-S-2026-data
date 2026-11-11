#include <bits//stdc++.h>
int main()
{
	std::string a[5];
	std::string c1,c2,a1,a2;
	for(int i=0;i<4;i++)
	{
		std::cin>>a[i];
	}
	c1=a[0];
	c2=a[1];
	a1=a[2];
	a2=a[3];
	bool s=false;
	bool d=false;
	bool sd=false;
	bool c=false,b=false;
	if(c1[0]==a1[0] && c1[1]==a1[1])
	{
		std::cout<<1;
		s=true;
	}
	else
	{
		std::cout<<0;
	}
	if(s==true)
	{
		if(c2[0]==a2[0] && c2[1]==a2[1])
		{
			std::cout<<1;
			d=true;
		}
	}
	else
	{
		std::cout<<0;
	}
		
	if(s==true && d==true)
	{
		if(c2[2]=='A' || c2[2]=='B' || c2[2]=='C')
		{
			if(a2[2]=='A' || a2[2]=='B' || a2[2]=='C')
			{
				std::cout<<1;
				sd=true;
				c=true;
			}
		}
		else if(c2[2]=='D' || c2[2]=='F')
		{
			if(a2[2]=='D' || a2[2]=='F')
			{
				std::cout<<1;
				sd=true;
				b=true;
			}
		}
	}
	else
	{
		std::cout<<0;
	}
	if(s==true && d==true && sd==true)
	{
		if(c==true)
		{
			if(c2[2]=='A'&& a2[2]=='B')
			{
				std::cout<<1;
			}
			else if(c2[2]=='B' && a2[2]=='C')
			{
				std::cout<<1;
			}
		}
		else if(b==true)
		{
			std::cout<<1;
		}
	}
	else
	{
		std::cout<<0;
	}
	return 0;
}
