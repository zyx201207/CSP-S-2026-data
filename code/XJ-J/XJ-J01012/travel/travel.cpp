#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if (a==b)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if (c[1]==d[1])
	{
		cout<<"1";
		if (c[3]=="A" && d[3]=="B" || c[3]=="A" && d[3]=="C")
		{
			cout<<"1";
		}
		else if (c[2]=="B" && d[2]=="A" || c[2]=="B" && d[2]=="C")
		{
			cout<<"1";
		}
		else if (c[2]=="C" && d[2]=="A" || c[2]=="C" && d[2]=="B")
		{
			cout<<"1";
		}
		else if (c[2]=="E" && d[2]=="F" || c[2]=="F" && d[2]=="E")
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
		if (c[2]-d[2]==1 || d[2]-c[2]==1)
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
		cout<<"000";
		return 0;
	}

	return 0;
}