#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[100005];
int f=0;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	int mx=INT_MIN;
	for (int i=1;i<=n;i++)
	{
		if(a[i]==a[i+1])
		{
			mx=max(mx,a[i]);
		}
	}
	cout << mx;
	return 0;
}
