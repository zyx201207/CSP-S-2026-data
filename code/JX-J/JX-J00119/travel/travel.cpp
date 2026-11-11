#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1!=c3)
	{
		cout<<"0000";
		return 0;
	}
	if(c2[0]!=c4[0]||c2[1]!=c4[1])
	{
		cout<<"1000";
		return 0;
	}
	int a=int(c2[2]),b=int(c4[2]);
	if(a<=67&&b>=68 || a>=68&&b<=67)
	{
		cout<<"1100";
		return 0;
	}
	if((max(a,b)-min(a,b))!=1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
