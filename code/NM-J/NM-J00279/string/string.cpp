#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin)
	freopen("string.out","w",stdout)
	int n;
	cin >> n;
	int a[100000];
	string x[100000],s;
	bool y;
	for(int i = 1;i<=n;i++)
	{
		cin >> a[i] >> x[i];
		for(int j = 1;j<=a[i];j++)
		{
			s+=x[i];
		}
	}
	for(int i = 0;i<s.length();i++)
	{
		if(s[s.length()-i]==s[i])
		{
			y=1;
		}
		else
		{
			y=0;
			break;
		}
	}
	if(y==0)
	{
		cout << "0";
	}
}
