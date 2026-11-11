#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long n;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	for(int i=2;i<16;i++)
	{
		if(c1==c2)
		{
			cout<<"1000";
			return  0;
		}
		if(s1!=s2)
		{
			cout<<"1100";
		}
	}
	return 0;
}
