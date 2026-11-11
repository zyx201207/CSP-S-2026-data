#include <iostream>
using namespace std;
int main ()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,s;
	int d,f;
	cin >>d;
	cin >>a;
	cin >>f;
	cin >>s;
	int z=0;
	if (d==f)
	{
		cout <<"1111";
		z=1;
	}
	else
	{
		cout <<"0";
	}
	if (z=0)
	{
		cout <<"000";
		return 0;
	}
}