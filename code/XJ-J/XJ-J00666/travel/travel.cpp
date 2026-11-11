#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c;
	string b,d,x,y,n,m;
	cin>>a>>b>>c>>d;
	x=b[0]+b[1];
	y=d[0]+d[1];
	n=b[2];
	m=d[2];
	if(a==c)
	{
		if(x==y)
		{
			if((n=="A"&&n=="B")||(n=="B"&&m=="A")||(n=="A"&&m=="C")||(n=="C"&&m=="A")||(n=="B"&&m=="C")||(n=="C"&&m=="B")||(n=="D"&&m=="F")||(n=="F"&&m=="D"))
			{
				if((n=="A"&&m=="B")||(n=="B"&&m=="A")||(n=="D"&&m=="F")||(n=="F"&&m=="D"))
				{
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}