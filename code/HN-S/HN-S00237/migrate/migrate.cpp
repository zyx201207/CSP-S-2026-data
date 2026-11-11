#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6+5;
int data_point_type,T,n,k,a[N],ans,minlt[N],dis[N],cntpath[N],sum[N];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> data_point_type >> T;
	while(T--)
	{
		cin >> n >> k;
		for(int i = 1;i <= n;i++) cin >> a[i];
		if(n == 1)
		{
			cout << "0\n";
			continue;
		}else if(data_point_type == 11 || data_point_type == 12)
		{
			int cha = a[2]-a[1],jump = k/cha;
			if(jump <= 1)
			{
				cout << "0\n";
				continue;
			}
			ans = 0;
			for(int i = 1;i <= n;i++) ans += ((n-i) >= jump*2-1);
			cout << ans << '\n';
			continue;
		}
		minlt[0] = 1;
		for(int u = 1;u <= n;u++)
		{
			minlt[u] = minlt[u-1];
			while(a[minlt[u]]+k < a[u]) minlt[u]++;
		}
		ans = 0;
		for(int u = 1;u <= n;u++)
		{
			dis[u] = 0;
			sum[u-1] = 0;
			sum[u] = cntpath[u] = 1;
			int pt = u;
			for(int v = u+1;v <= n;v++)
			{
				if(minlt[v] == v) break;
				dis[v] = dis[max(u,minlt[v])]+1;
				while(dis[pt] < dis[v]) pt++;
				cntpath[v] = min(sum[pt-1]-sum[max(u,minlt[v])-1],3ll);
				sum[v] = sum[v-1]+cntpath[v];
				if(cntpath[v] == 2) ans++;
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
