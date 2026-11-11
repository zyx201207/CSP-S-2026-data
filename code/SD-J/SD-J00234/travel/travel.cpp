#include <bits/stdc++.h>
using namespace std;
int ac,bc,az,bz;
string a,b; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ac>>a>>bc>>b;
	int a1=10*(a[0]-'0')+a[1]-'0';
	int b1=10*(b[0]-'0')+b[1]-'0';
	if(ac!=bc)
	{
		cout<<"0000";
		return 0;
	}
	else 
	{
		cout<<"1";
		if(a1!=b1)
		{
			cout<<"000";
			return 0;
		}
		else
		{
			cout<<"1";
			if((a[2]<='C'&&b[2]>='D')||(b[2]<='C'&&a[2]>='D'))
			{
				cout<<"00";
				return 0;
			}
			else
			{
				cout<<"1";
				int c=a[2]-'A';
				int d=b[2]-'A';
				if(abs(c-d)!=1)
				{
					cout<<"0";
				}
				else
				{
					cout<<"1";
				}
				return 0;
			}
		}
	}
}
