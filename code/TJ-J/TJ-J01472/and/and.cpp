#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	} 
	sort(a + 1,a + n + 1,greater<int>());
	int cnt = 0;
	long long mx = 0;
	for(int i = 1; i <= n; i++)
	{
		cnt++;
		if(cnt == m)
		{
			cout<<a[i];
			return 0;
		}
	}
	
	return 0;	
}
