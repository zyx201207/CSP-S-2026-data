#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rc,xc;
	string rs,xs;
	cin >> rc >> rs >> xc >> xs;
	if(rc==xc)
	{
		cout<<"1";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	if(rs[0]==xs[0]&&rs[1]==xs[1])
	{
		cout << "1";
	}
	else
	{	
		cout << "000";
		return 0;
	}
	
	cout << "00";
	return 0;
}
