#include <iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freoepn("travel.out","w",stdout);
//
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	long long chexiang1 = (c1[0]-'0')*10+(c1[1]-'0');
	long long chexiang2 = (c2[0]-'0')*10+(c2[2]-'0');
	//车厢号 
	if(chexiang1 == chexiang2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	long long pai1 = (s1[0]-'0')*10+(s1[1]-'0');
	long long pai2 = (s2[0]-'0')*10+(s2[1]-'0');
	//排号 
	if(chexiang1 == chexiang2&&pai1 == pai2)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	//同一侧
	char a = s1[2];
	char b = s2[2];
	if(chexiang1 == chexiang2&&pai1 == pai2&&((a=='A'&&b!='D'&&b!='F') ||(b=='A'&&a!='D'&&a!='F')||(a=='D'&&b=='F')||(b=='D'&&a=='F')))
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	//相邻 
	if(chexiang1 == chexiang2&&pai1 == pai2&&((a=='A'&&b!='D'&&b!='F') ||(b=='A'&&a!='D'&&a!='F')||(a=='D'&&b=='F')||(b=='D'&&a=='F')))
	{
		if(a == 'A'&&b == 'B')
		{
			cout<<1;
		} 
		else if(a == 'B'&&b == 'C')
		{
	 		cout<<1;
		}
		else if(a == 'D'&&b == 'F')
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
		cout<<0;
	}
	return 0;
}
