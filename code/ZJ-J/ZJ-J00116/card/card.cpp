#include<bits/stdc++.h>
using namespace std;
int a[500055];
int pos[300033];
int d[500055];
int ans[300033];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	ans[a[n]] = n; pos[a[n]] = n;
	for(int i = n-1;i >= 1;i--)
	{
		if(pos[a[i]])d[i] = pos[a[i]];
		else pos[a[i]] = i;
		int t = i;
		while(t < n)
		{
			if(d[t])t = d[t];
			else
			{
				ans[a[t]]++;
				t++;
			}
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}//card
