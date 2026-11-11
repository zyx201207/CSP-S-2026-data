#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500050], M;
int n, maxn=1;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>M;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	for(int j=1; j<n; j++)
	{
		ll m=M;
		for(int i=j+1; i<=n; i++)
		{
			m-=(i-1)*(a[i]-a[i-1]);
			if(m<0)
			{
				maxn=max(maxn, i-j);
				break;
			}
		}
	}
	cout<<maxn;
	return 0;
}
