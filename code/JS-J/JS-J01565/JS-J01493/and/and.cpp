#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
int a[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	int ans=a[n];
	for(int i=n-1;i>=n-m+1;i--)
	{
		ans&=a[i];
	}
	cout << ans;
    return 0;
}
