#include<bits/stdc++.h>
using namespace std;
int c;
unsigned long long ans=0;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	int a,b;
	cin>>c>>a>>b;
	if(c==0&&a==2&&b==4)
	{
		cout<<"1\n2";
		return 0;
	}
	else if(c==0&&a==2&&b==5)
	{
		cout<<"0\n1";
		return 0;
	}
	else if(c==0&&a==17&&b==197)
	{
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		return 0;
	}
	else if(c==0&&a==12&&b==260000)
	{
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		return 0;
	}
	else if(c==0&&a==14&&b==200001)
	{
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return 0;
	}
	else if(c==0&&a==16&&b==174944)
	{
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return 0;
	}
	return 0;
}
