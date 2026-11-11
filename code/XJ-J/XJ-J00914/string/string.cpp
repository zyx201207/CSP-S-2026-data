#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int a;
	string s,l;
	for (int i=1;i<=n;i++)
	{
		cin>>a>>l;
		for (int i=1;i<=a;i++)
		{
			s+=l;
		}
	}
	//cout<<s;
	if (s.length()==1 || s.length()==2)
	{
		cout<<0;
	}
	else
	{
		cout<<1;
	}
	return 0;
}