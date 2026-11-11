#include<bits/stdc++.h>
using namespace std;
string sa,sb,sc,sd;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sa>>sb>>sc>>sd;
	if(sa==sc)
	{
		if(sb[0]==sd[0]&&sb[1]==sd[1])
		{
			if((sb[2]>='A'&&sb[2]<='C'&&sd[2]>='A'&&sd[2]<='C')||(sb[2]>='D'&&sb[2]<='E'&&sd[2]>='D'&&sd[2]<='E'))
			{
				if(abs(sb[2]-sd[2])==1)
				cout<<"1111";
				else
				cout<<"1110";
			}
			else
			cout<<"1100";
		}
		else
		cout<<"1000";
	}
	else
	cout<<"0000";
	return 0;
}
