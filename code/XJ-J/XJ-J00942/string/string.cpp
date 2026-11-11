#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s,sum=0;
	char ch;
	string x;
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> s;
		cin >> ch;
		for(int j=1;j<=s;j++)
		{
			x+=ch;
		}
	}
	int a=x.length();
	for(int i=0;i<a/2;i++)
	{
		if(x[i]!=x[a+1-i])
			sum++;
	}
	cout << sum;
	return 0;
}