#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	bool a=false,b=false,c=false,d=false;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1])
	{
		a=true;
		if(s1[0]==s2[0]&&s1[1]==s2[1])
		{
			b=true;
			if((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))
			{
				c=true;
				if(abs(s1[2]-s2[2])==1)
				{
					d=true;
				}
			}
			else if((s2[2]=='D'||s2[2]=='F')&&(s1[2]=='D'&&s1[2]=='F'))
			{
				c=true;
				d=true;
			}
		}
	}
	cout<<a<<b<<c<<d<<endl;
	return 0;
}
