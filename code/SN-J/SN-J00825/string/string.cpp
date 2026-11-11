//王子政 SN-J00825 西安市益新中学
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	string aa;
	int c=0;
	for (int i=1;i<=n;i++)
	{
		int a;
		char b;
		cin >> a >> b;
		for (int j=1;j<=a;j++)
		{
			aa+=b;
		}
	}
	int j=aa.size()-1;
	for (int i=0;i<=j;i++)
	{
		if (aa[i]!=aa[j])
		{
			aa[j]=aa[i];
			c++;
		}
		j--;
	}
	cout << c;
	return 0;	
} 
