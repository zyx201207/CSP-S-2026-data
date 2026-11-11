#include<bits/stdc++.h>
using namespace std;
const long long N = 2e5;
long long a[N+10],n,m,ans;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)    cin >> a[i];
	for(int bit = 30; bit >= 0; bit--)
	{
		long long cnt = 0;
		vector<long long> nums;
		for(int i = 1; i <= n; i++)
		{
			if((a[i]>>bit)&1)
			{
				cnt++;
				nums.push_back(a[i]);
			}    
		}
		if(cnt<m)    continue;
		n = nums.size();
		for(int i = 1; i <= n; i++)    a[i] = nums[i-1];
	}
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	ans = a[1];
	for(int i = 2; i <= m; i++)    ans = (ans&a[i]);
	cout << ans;
	return 0;
}
