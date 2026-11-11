#include <iostream>
#include <algorithm>
#define endl '\n'
#define ll long long
using namespace std;
const int N=2e6+5;
int n,c,t;
ll d,cnt,x[N];
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		int l=i,r=lower_bound(x+1,x+n+1,x[i]+d+1)-x;
		if(r>n)
			continue;
		if(d>n/2)
		{
			cout<<"0\n";
			return;
		}
		cnt++;
	}
	cout<<cnt<<"\n";
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--)
		solve();
	return 0;
}