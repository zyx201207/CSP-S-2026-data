#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	char t1,t2;
	cin>>c1>>s1>>t1>>c2>>s2>>t2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1==s2)
		{
			cout<<"1";
			if(t1>='A'&&t1<='C'&&t2>='A'&&t2<='C')
			{
				cout<<"1";
				if(t1=='B'&&(t2=='A'||t2=='C'))
				{
					cout<<"1";
				}
				else if(t2=='B'&&(t1=='A'||t1=='C'))
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
				}
			}
			else if((t1=='D'||t1=='F')&&(t2=='D'||t2=='F'))
			{
				cout<<"11";
			}
			else
			{
				cout<<"00";
			}
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
