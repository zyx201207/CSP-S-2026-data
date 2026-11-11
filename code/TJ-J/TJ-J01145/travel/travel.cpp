#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b,c,d;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("treval.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2)
	{
		a=1;
		
		if (s1[0]==s2[0] && s1[1]==s2[1])
	{
		b=1;
		if ((s1[2]>='D'&&s2[2]>='D') || (s1[2]<'D' && s2[2]<'D'))
		{
			c=1;
			if ((s1[2]-'0')-(s2[2]-'0')==1 || (s1[2]-'0')-(s2[2]-'0')==-1)
			{
			d=1;
			}
		}
	}
	}

	
	cout<<a<<b<<c<<d;
	
	
	
	return 0;
}
