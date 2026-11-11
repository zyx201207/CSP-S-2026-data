#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,b,x,y;
	cin>>s>>b>>x>>y;
	if(s==x)
	{
		cout<<'1';
		if(b[0]==y[0]&&b[1]==y[1])
		{
			cout<<'1';
			if((b[2]<'D'&&y[2]<'D')||(b[2]>'C'&&y[2]>'C'))
			{
				cout<<'1';
				if((char(b[2]+1)==y[2])||char(y[2]+1)==b[2])
				{
					cout<<'1';
				}
				else
				{
					cout<<'0';
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
	fclose(stdin);
	fclose(stdout);
	return 0;
}