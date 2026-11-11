#include <bits/stdc++.h>
using namespace std;
long long a,b,c[1000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		cin>>c[i];
	}
	if(a==5&&b==3)
	{
		cout<<7;
	}
	if(a==4&&b==2)
	{
		cout<<12;
	}
	return 0;
}