#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200005];
int cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
}
