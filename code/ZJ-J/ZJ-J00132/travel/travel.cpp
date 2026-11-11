#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		a=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			b=1;
			bool ok1=(s1[2]=='A'||s1[2]=='B'||s1[2]=='C');
			bool ok2=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
			if(ok1==ok2)
			{
				c=1;
				if(abs(s1[2]-s2[2])==1)
				  d=1;
			}
		}
	}
	cout<<a<<b<<c<<d;
}