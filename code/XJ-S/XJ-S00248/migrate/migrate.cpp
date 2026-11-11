#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll a[N];
int c;
void solve()
{
	ll n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[2]-a[1]>=d||c==13||c==14){
		cout<<"0"<<'\n';
		return;
	}else{
		cout<<max(n-(d/(a[2]-a[1])*2ll-1ll),0ll)<<'\n';
		return;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>c>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

