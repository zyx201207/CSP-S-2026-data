#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
#define ll long long
ll n,m;
ll a[maxn];
ll ans = 0;

ll maxx = 0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if(n == m)
	{
		ans = a[1];
		for(int i = 1 ;i <= n;i++)
		{
			ans = ans & a[i];
		}
		cout << ans;
		return 0;
	}
	if(m==1)
	{
		ans = 0;
		for(int i = 1 ;i <= n;i++)
		{
			ans = max(ans,a[i]);
			
		}
		cout << ans;
		return 0;
	}
	if(m == 2&& n <= 2000)
	{
		ans = 0;
		for(int i = 1;i < n;i++)
		{
			for(int j = i + 1;j <= n;j++)
			{
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}
