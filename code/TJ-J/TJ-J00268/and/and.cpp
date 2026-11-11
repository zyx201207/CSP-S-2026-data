#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
string s[200005];
signed main()
{
	cin>>n>>m;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int temp=LLONG_MAX;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		temp=min(temp,a[i]);
	}
	cout<<temp;
	return 0;
}
