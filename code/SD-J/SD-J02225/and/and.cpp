#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll M = 2e5+10;
ll n,k;
ll a[M];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[k];
	return 0;
}
