#include <bits/stdc++.h>
using namespace std;
int a[2000010];
vector<int> v[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
		{
			cin>>a[i];
//			if (i>=2&&a[i]-a[i-1]<=d)
//			{
//				v[a[i-1]].push_back(v[a[i]]);
//			}
		}
		for (int i=1;i<=n;i++)
		{
			for (int j=i+1;j<=n;j++)
			{
				if (a[j]+a[i]<=d)
				{
					v[i].push_back(j);
				}
			}
		}
		cout<<0;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/

