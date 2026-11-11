# include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	cout<<a[n-m+1];
	return 0;
}
 


