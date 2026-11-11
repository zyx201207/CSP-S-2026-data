#include<bits/stdc++.h>
using namespace std;
int a[200022];
vector<int>bt[33];
bool cmp(int A,int B)
{
	return A > B;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i = 1;i <= n;i++)
	{
		int t = a[i],cnt = 30;
		while(t)
		{
			if(t&1)bt[cnt].push_back(i);
			t >>= 1; cnt--;
		}
	}
	for(int i = 0;i <= 30;i++)
	{
		if(bt[i].size() >= m)
		{
			int cnt = 0,ans = a[bt[i][0]];
			for(int t:bt[i])
			{
				ans = (ans & a[t]);
				cnt++;
				if(cnt == m)
				{
					cout << ans << "\n";
					return 0;
				}
			}
		}
	}
	cout << "0\n";
	return 0;
}//and
