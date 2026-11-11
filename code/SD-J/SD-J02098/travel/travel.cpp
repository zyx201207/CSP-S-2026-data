#include<iostream>
#include<string>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		if(s1[1]==s2[1]&&s1[0]==s2[0])
		{
			int x1=s1[2]-'A',x2=s2[2]-'A';
			if((x1<=2&&x2<=2)||(x1>2&&x2>2))
			{
				if(abs(x1-x2)==1)
				{
					cout<<"1111"<<endl;
				}
				else
				{
					cout<<"1110"<<endl;
				}
			}
			else
			{
				cout<<"1100"<<endl;
			}
		}
		else
		{
			cout<<"1000"<<endl;
		}
	}
	else
	{
		cout<<"0000"<<endl;
	}
	return 0;
}
