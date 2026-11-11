#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
void solve()
{
	cin>>n>>d;
	int a1,a2;
	cin>>a1>>a2;
	if (((n-1)-d/(a2-a1))%2==0)
		cout<<2;
	else
		cout<<0;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while (t--)
		solve();
	return 0;
}
//Oct31==Dec25?
