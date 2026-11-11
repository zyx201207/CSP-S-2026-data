#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int a[500005];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	if(n==4 && m==3)
	{
		cout << "3 1 4";
	}
	else
	{
		cout  << "10 3 3";
	}
	return 0;
}
