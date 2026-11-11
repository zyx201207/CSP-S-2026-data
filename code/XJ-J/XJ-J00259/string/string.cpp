#include <bits/stdc++.h>
using namespace std;
int n,a;
char c;
string l="";
long long sum=0;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>a>>c;
		for (int i=0;i<a;i++)
		{
			l+=c;
		}
	}
	long long ls=l.size();
	for (int i=0;i<=ls/2;i++)
	{
		if(l[i]!=l[ls-i])
		{
			sum++;
		}
	}
	cout<<sum;
	return 0;
}