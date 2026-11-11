#include <bits/stdc++.h>
using namespace std;
long long a[200010];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,num=0;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1; i<m; i++)
	{
		if(a[i] & a[i+1] > num)
		{
			num = a[i] & a[i+1];
		}
	}
	cout << num;
	return 0;
}
