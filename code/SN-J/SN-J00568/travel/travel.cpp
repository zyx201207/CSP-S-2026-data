#include<bits/stdc++.h.>
using namespace std;

int main()
{
	int a,c;
	string b,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		if(b[0]==d[0]&&b[1]==d[1])
		{
			if((b[2]-'A'<=3&&d[2]-'A'<=3)||(b[2]-'A'>3&&d[2]-'A'>3))
			{
				if(b[2]-d[2]==1||d[2]-b[2]==1)
				{
					cout<<1111;
				}
				else
				{
					cout<<1110;
				}
			}
			else
			{
				cout<<1100;
			}
		}
		else
		{
			cout<<1000;
		}
	}
	else
	{
		cout<<0000;
	}
	return 0;
}
