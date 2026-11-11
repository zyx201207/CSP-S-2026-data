#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int a_2=(b[0]-'0')*10+(b[1]-'0');
	int c_2=(d[0]-'0')*10+(d[1]-'0');
	if(a==c)//same cart
	{
		cout<<"1";
		if(a_2==c_2)//same row
		{
			cout<<"1";
			if(('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C')||('D'<=b[2]&&b[2]<='F'&&'D'<=d[2]&&d[2]<='F'))//same col
			{
				cout<<"1";
				if(((b[2]-d[2])==1)||((d[2]-b[2])==1))// stick with
				{
					cout<<"1";
				}
				else
				{
					cout<<"0";
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
