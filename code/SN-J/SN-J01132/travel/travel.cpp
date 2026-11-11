#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,n1,n2;
	char s1,s2;
	cin>>c1>>n1>>s1>>c2>>n2>>s2;
	if(c1==c2)
	{
		cout<<1;
		if(n1==n2)
		{
			cout<<1;
			if((s1<='C'&&s1>='A'&&s2<='C'&&s2>='A')||(s1=='F'&&s2=='D')||(s1=='D'&&s2=='F'))
			{
				cout<<1;
				if(abs(int(s1-s2))==1)
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
