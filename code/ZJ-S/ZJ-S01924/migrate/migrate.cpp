#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int c,T,n;
ll d,a[N],dp[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		ll x=n*(n+1)>>2;
		cout<<x-1<<"\n";
	}
	return 0;
}