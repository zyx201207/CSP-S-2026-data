#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
int n,m,a[N],b[N],c[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			b[i] += abs(a[i] - a[j]);
	int minn = INT_MAX,pos;
	for(int i = 1;i <= n;i++){
		if(b[i] < minn)
		{
			minn = b[i];
			pos = i;
		}
	}
	for(int i = 1;i <= n;i++)
	{
		if(a[i] == a[pos]) continue;
		else c[i] = abs(a[i] - a[pos]);
	}
	sort(c + 1,c + n + 1);
	int ans = 1;
	for(int i = 2;i <= n;i++)
	{
		if(m <= 0) break;
		else
		{
			m -= c[i];
			ans++;
		}
	}
	cout << ans;	
	return 0;
} 
