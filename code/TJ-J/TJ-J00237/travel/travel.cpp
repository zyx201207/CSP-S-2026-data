#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen(travel.in,"r",stdin);
	freopen(travel.out,"w",stdout);
	string ans;
	string C1;
	string S1;
	string C2;
	string S2;
	if(C1==C2)
	{
		ans=='1000';
	}
	else
	{
		ans=='0000';
	}
	if(ans=='1000'&&S1-'ABCDF'==S2-'ABCDF')
	{
		ans=='1100';
	}
	if(ans=='1100'&&S1-'010203040506070809101112131415161718==S2-'010203040506070809101112131415161718')
	{
		ans=='1110';
	}
	cout<<ans<<end;
	return 0;
}
