#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2);
	bool b=0,a=0,d=0;
	
	if(c1==c2)
		{if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			b=1;
		}
		if(b)
		{
			if(s1[2]>'C'&&s2[2]>'C')
			{
				a=1;d=1;
			}
			if(s1[2]<='C'&&s2[2]<='C')
			{
				a=1;
				if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
				{
					d=1;
				}
			}
		}
	}
	cout<<b;
	cout<<a<<d;
	return 0;
}
