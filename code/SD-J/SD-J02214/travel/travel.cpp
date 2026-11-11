#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,l,r;
char x,y;
bool flagx,flagy;
string ans="";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	x=s1[2],y=s2[2];
	l=(s1[0]-'0')+(s1[1]-'0');
	r=(s2[0]-'0')+(s2[1]-'0');
	if(c1==c2)
	{
		ans+='1';
		if(l==r)
		{
			ans+='1';
			if(x=='A'||x=='B'||x=='C')
				flagx=true;
			else
				flagx=false;
			if(y=='A'||y=='B'||y=='C')
				flagy=true;
			else
				flagy=false;
			if((flagx==true&&flagy==true)||(flagx==false&&flagy==false))
			{
				ans+='1';
				int k=((x-'0')-(y-'0'));
				if(abs(k)==1)
					ans+='1';
				else
					ans+='0';
			}
			else
				ans+="00";
		}
		else
			ans+="000";
	}
	else
		ans="0000";
	cout<<ans;
	return 0;
}
