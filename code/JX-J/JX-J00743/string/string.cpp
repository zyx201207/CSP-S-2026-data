#include<bits/stdc++.h>
using namespace std;
string a;
int n;
void pd(string x)
{
	int sum=0,x1=x.size();
	for (int i=0;i<x1/2;i++)
		if (x[i]!=x[x1-i-1]) sum++;
	cout << sum;
}
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		long long abc;
		char xyz;
		cin >> abc >> xyz;
		for (int i=1;i<=abc;i++) a+=xyz;
	}
	pd(a);
	return 0;
}
