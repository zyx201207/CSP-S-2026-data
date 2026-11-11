#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,sum,ans,j;
ll a[500005];           
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++)
		cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i ++)
	{
		sum += (a[i] - a[i - 1]) * (i - j - 1);
		if(sum <= m)
			ans = max(ans,i - j);
		else 
		{
			while(sum > m)
			{
				j ++;
				sum -= a[i] - a[j];
				ans = max(ans,i - j);
			}
			
		}
	}
	cout << ans << endl;
	return 0;
 } 
