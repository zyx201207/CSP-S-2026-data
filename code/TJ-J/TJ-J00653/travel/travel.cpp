#include<bits/stdc++.h>
int c1, c2;
char s1[5], s2[5];
	
int main()
{
	std::freopen("travel.in", "r", stdin);
	std::freopen("travel.out", "w", stdout);
	
	std::cin>>c1>>s1>>c2>>s2;
	if(c1 == c2)
	{
		std::cout<<1;
		if(s1[0] == s2[0] && s1[1] == s2[1])
		{
			std::cout<<1;
			if(  ( (s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C') )  ||  ( (s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F') )   )
			{
				std::cout<<1;
				if(s1[2] - 1 == s2[2] || s1[2] + 1 == s2[2] || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'D' && s2[2] == 'F'))
				{
					std::cout<<1;
				}else
				{
					std::cout<<0;
				}
			}else
			{
				std::cout<<"00";
			}
		}else
		{
			std::cout<<"000";
		}
	}else
	{
		std::cout<<"0000";
	}
	
	return 0;
}
