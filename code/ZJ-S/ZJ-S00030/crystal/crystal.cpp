#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],ps[N],ans=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		ps[i]=ps[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		if((i-1)*a[i]-ps[i-1]<=m)
			ans=i;
	}
	cout<<ans;
	return 0;
}
