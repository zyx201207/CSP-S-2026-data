#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int x1,z1,x2,z2;
	x1=(c1[0]-'0')*10+(c1[1]-'0');
	z1=(s1[0]-'0')*10+(s1[1]-'0');
	x2=(c2[0]-'0')*10+(c2[1]-'0');
	z2=(s2[0]-'0')*10+(s2[1]-'0');
	if(x1==x2)
	{
		cout<<1;
		if(z1==z2)	
		{
			cout<<1;
			if(s1[2]<='C' && s2[2]<='C')	
			{
				cout<<1;
				if(s1[2]=='B' || s2[2]=='B')	cout<<1;
				else	cout<<0;
			}
			else if(s1[2]>='D' && s2[2]>='D')
			{
				cout<<"11";
			}
			else cout<<"00";
		}
		else 	cout<<"000";	
	}	
	else	cout<<"0000";
	return 0;
}
