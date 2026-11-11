#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0,cnt=0;
	int a[n];
	char b[n];
	string c;
	cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin  >> a[i] >> b[i];
		for (int j=1;j<=a[i];j++)
		{
			c+=b[i];
			
		}
		s+=a[i];
	}
	for (int i=0;i<=(s/2);i++)
	{
		if(c[i]!=c[s-i-1])
			cnt++;
	}
	cout << cnt;
	return 0;
	
}
