#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int a[n+5];
	string b[n+5];
	for(int i=0;i<=n-1;i++)
	{
		cin >> a[i] >> b[i];
	}
	if(n==1)
	{
		cout << "0";
		return 0;
	}
	if(b[0]!=b[1])
	{
		if(a[0]>a[1] and b[0]!=b[1])
		{
			cout << a[1];
		}
		else
		{
			cout << a[0];
		}
	}
	else
	{
		cout << "0";
	}
}
