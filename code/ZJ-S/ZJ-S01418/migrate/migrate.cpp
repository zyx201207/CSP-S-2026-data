#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll c, t; 
ll n, d;
const int N=2000005;
ll x[N];
ll qi[N];
ll cntm, cnt;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);			//不要忘记打开！！！！！ 
	freopen("migrate.out","w",stdout);			//不要忘记打开！！！！！ 
	cin >> c >> t;
	if(c==0)
	{
		while(t--)
		{
			cnt = 0;
			cin >> n >> d;
			for(int i = 1; i <= n; i++)
			{
				cin >> x[i];
				//if(i != 1) qi[i]=qi[i-1]+(x[i]-x[i-1]);
			}
			ll maxn = (ll) d/(x[2]-x[1]);
//			cout << "!!" << maxn << '\n';
			if (maxn <= 1)
			{
				cout << 0 << '\n';
				continue;
			 } 
			for(ll i = 1; i <= n-maxn*2+1; i++)
			{
				++cnt;
			}
			cout << cnt << '\n';
		}
		
	 } 
	return 0;
}
