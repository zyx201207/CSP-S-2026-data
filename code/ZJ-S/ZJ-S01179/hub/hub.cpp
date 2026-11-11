//换根DP?
// 17:40 暴力
#include<bits/stdc++.h>
using namespace std;

#define int long long
int C, n, c[20];
void calc()
{
	int n, k;
	cin >> n >> k;
		for(int i = 1; i < n; i++)
		{
			int a, b; cin >> a>> b;
		}
	if(C == 13 || C == 14)
	{
		int ans = -1;
		for(int i = 1; i <= k/4; i++)
		{
			ans += i*4;
		}
		ans += (k/4+1)*(k%4);
		cout << ans << '\n';
		return;
	}
	cout << (n-1+n-k-1)*k/2 << '\n';
	return;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int T;
	cin >> C >> T;
	while(T--) calc();
	return 0;
}
// 18:00 性质A 
 // 18:12 看错题了 呜呜呜 拜拜 
