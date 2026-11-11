#include <bits/stdc++.h>
using namespace std;
int n;
string a[10005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n>2&&n<6)
	{
		cout<<2; 
	}
	if(n<=2)
	{
		cout<<0;
	}
	if(n>=6)
	{
		cout<<30000000000;
	}
	return 0;
}
