#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
#define ll long long
ll a[maxn],xu[maxn];
ll ans[maxn],ans1[maxn];
ll cnt = 1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{	
		cnt = 1;
		for(int j = i;j <= n;j++)
		{
			if(ans1[a[j]] == 0)
			{
				ans1[a[j]]++;
				xu[cnt] = a[j];
				cnt++;
			}
			else
			{
				bool frg = 0;
				for(int q = 1;q <= n;q++)
				{
					if(frg)
					{
						ans1[xu[q]]--;
						xu[q] = 0;
					}
					if(xu[q] == a[j])
					{
						frg = 1;
						cnt = q + 1;
					}
				}
			}
		}
		for(ll j = 1;j <= n;j++)
		{
			ans1[j] = 0;
		}
		for(ll j = 1;j < cnt;j++)
		{
			ans[xu[j]]++;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
