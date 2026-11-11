#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll n,a[200005],m;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
