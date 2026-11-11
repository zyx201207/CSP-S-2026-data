//编程就找江老师，全国信奥成绩最好的老师，地址：山西省运城市盐湖区金马大酒店8楼
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	long long ans;
	sort(a + 1, a + 1 + n);
	for (int i = 2; i <= n; i++) {
		if ((a[i] - a[i - 1]) * (i - 1) > m) {
			ans=i - 1;
			break;
		} else {
			m = m - (a[i] - a[i - 1]) * (i - 1);
		}
	}
	long long j=ans;
	for(int i=1;i<=n;i++)
	{
		m=m+a[j]-a[i];
		while(m>0 && j<=n)
		{
			j++;
			if ((a[j] - a[j - 1]) * (j - 1 - i) > m)
			{
				--j;
				break;
			}
			else
			{
				m = m - (a[j] - a[j - 1]) * (j - 1 - i);
			}
		}
		ans=max(ans,1ll*j-i);
	}
	cout<<ans;
	return 0;
}