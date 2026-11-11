#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n, m;
long long a[200005], maxn = -1, s;
int qwq(long long a, long long b)
{
	string a1 = "", b1 = "";
	long long ans = 0;
	while (a||b)
	{
		if (a==1) 
		{
			a1+='1';
			a = 0;
		}
		if (b==1) 
		{
			b1+='1';
			b = 0;
		}
		if (a%2==1) 
		{
			a1+='1';
			a/=2;
		}
		else
		{
			a1+='0';
			a/=2;
		}
		if (b%2==1) 
		{
			b1+='1';
			b/=2;
		}
		else
		{
			b1+='0';
			b/=2;
		}
	}
	for (int i = 0;i<min(a1.size(), b1.size());i++)
	{
		if (a1[i]==b1[i]&&a1[i]!='0') ans+=pow(2, i);
	}
	return ans;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin>>n>>m;

	return 0;
}
