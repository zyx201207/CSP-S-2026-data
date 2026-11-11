#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 4e5+10;


ll n,a[MAXN],ans = 0;
char c[MAXN];



int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(ll i=1;i<=n;i++) cin >> a[i] >> c[i];
	ll lt = 1,rt = n;
	while(lt < rt)
	{
		if(c[lt] != c[rt])
		{
			if(a[lt] > a[rt])
			{
				a[lt] -= a[rt];
				ans += a[rt];
				a[rt] = 0;
				rt--;
			}
			else if(a[lt] < a[rt])
			{
				a[rt] -= a[lt];
				ans += a[lt];
				a[lt] = 0;
				lt++;
			}
			else if(a[lt] == a[rt])
			{
				ans += a[lt];
				a[rt] = 0;
				a[lt] = 0;
				lt++;
				rt--;
			}
		}
		else
		{
			if(a[lt] > a[rt])
			{
				a[lt] -= a[rt];
				a[rt] = 0;
				rt--;
			}
			else if(a[lt] < a[rt])
			{
				a[rt] -= a[lt];
				a[lt] = 0;
				lt++;
			}
			else if(a[lt] == a[rt])
			{
				a[rt] = 0;
				a[lt] = 0;
				lt++;
				rt--;
			}
		}
	}
	cout << ans;
	return 0;
}
