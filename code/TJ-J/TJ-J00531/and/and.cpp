#include <bits/stdc++.h>
using namespace std;
int a[1000007];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		if(i==n-1) cout << a[i];
	}
	return 0;
}
