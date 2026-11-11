#include<bits/stdc++.h>
#define F10 ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	F10
	string a1,a2,b1,b2;
	std::cin>>a1>>a2>>b1>>b2;
	bool s=1;
	for(int i=0;i<2;i++)
	{
		if(a1[i]!=b1[i])
		{
			std::cout<<"0000";
			return 0;
		}
	}
	std::cout<<"1";
	for(int i=0;i<2;i++)
	{
		if(a2[i]!=b2[i])
		{
			std::cout<<"000";
			return 0;
		}
	}
	std::cout<<"1";
	if(a2[2]<='C'&&b2[2]<='C'||a2[2]>='D'&&b2[2]>='D')
	{
		std::cout<<"1";
	}
	else
	{
		std::cout<<"00";
		return 0;
	}
	if(abs(a2[2]-b2[2])==1)
	{
		std::cout<<"1";
	}
	else
	{
		std::cout<<"0";
	}
	return 0;
}
