#include <bits/stdc++.h>
using namespace std;
int n,a[500005];
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cout<<n;
	return 0;
}
