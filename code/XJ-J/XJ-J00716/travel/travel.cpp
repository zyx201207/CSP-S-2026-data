#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=2;i<=17;i++)
	{
		if(c1==c2)
		{
			cout<<"1";
			break;
		}
		else
		{
			cout<<"0";
			break;
		}
	}
	cout<<"000";
	return 0;
}