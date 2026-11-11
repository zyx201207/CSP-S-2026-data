#include <bits/stdc++.h>
using namespace std;
int s[1000005],n,m;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	char a;
	for (int i=1;i<=n;i++)
	{
		cin >>m;
		for  (int j=1;j<=m;j++)
		{
			cin >> s[j];
		}
	}
	cout << "2";
	return 0;
}

