#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;
int n,m,ans = -1;
int c[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i <= n; i++)
	{
		cin>>c[i];
	}
	sort(c + 1,c + n + 1);
	for(int i = n; i >= 1; i--)
	{
			
		int total = 0,temp_ans = 0;
		for(int j = i; j >= 1; j--)
		{
			if(m >= total + abs(c[i] - c[j]))
			{
				temp_ans++;
				total += abs(i - j);
			}
			else
				break;
		}
		ans = max(ans,temp_ans);
	}
	cout<<ans<<'\n';
	/*	
	for(int i = 1;i <= n; i++)
	{
		int between[n + 1],total = -1;
		int temp_ans = 0;
		for(int j = 1;j <= i; j++)
		{
			between[j] = abs(c[j] - c[i]);
		}
		sort(between + 1,between + n + 1);
		if(m >= between[1])
		{
			total = between[1];
			temp_ans++;
		}
		for(int j = 2;j <= n; j++)
		{
			if(m >= total + between[j])
			{
				total += between[j];
				temp_ans++;
			}
			else
				break;
		}
		ans = max(ans,temp_ans);
	}
	cout<<ans<<'\n';
	*/
	return 0;
}
