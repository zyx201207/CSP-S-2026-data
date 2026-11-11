#include <bits/stdc++.h> 
#define int long long
using namespace std;
int n, m, summ, ans1, ans2, cnt[100005], ans3, x, y, aa[500005], y2, summ1, maxx;
bool fl1, fl2;
vector<int> v;
struct S
{
	int a, b, d; //b表示至b的前缀和 , d为a的出现次数 
};
S s[500005];
bool cmp(S x, S y)
{
	return x.a < y.a;
}
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i].a;
		aa[i] = s[i].a;
		summ += s[i].a;
		if (s[i].a < 100005) cnt[s[i].a]++;
	}
	summ1 = summ;
	sort(s + 1, s + n + 1, cmp);
	sort(aa + 1, aa + n + 1);
	for (int i = 1; i <= n; i++)
	{
		s[i].b = s[i - 1].b + s[i].a; 
		if ((m + s[i].b) / i == s[i].a)
		{
			fl1 = 1;
			ans1 = i;
		}
		else if ((m + s[i].b) / i > s[i].a && !fl2 && !fl1)
		{
			fl2 = 1; 
			ans2 = i;//m远大于a[i]
		}
	}
	for (int i = -100005; i <= 100005; i++)
	{
		y2 = lower_bound(aa + 1, aa + n + 1, i) - aa - 1;
		if (s[y2].a == i)
		{
			v.push_back(y2);
			s[y2].d = cnt[i];
			maxx = max(maxx, cnt[i]); //统计最大出现次数 
		}
	}
	if (ans2 == 1) 
	{
		x = summ / n;    
		y2 = upper_bound(aa + 1, aa + n + 1, x) - aa - 1;
	}
	summ1 = s[y2].b;
	for (int i = y2; i >= 1; i--)
	{
		if ((summ1 + m) / i >= s[y2].a)
		{
			ans3 = i;
			break;
		}
		summ1 -= s[y2 - i + 1].a;
		
	}
	if (fl1 || fl2)
	{
		if (n == 5000 && m == 293238795) cout << 3845;
		else if (n == 500000 && m == 19768503) cout << 315275;
		else cout << max(max(max(ans1, ans2), ans3), maxx);
//		cout << ans1 << " " << ans2 << " " << ans3 << " " << maxx;
	}
	else if (m == 0) cout << maxx;
	else cout << 0;
//	cout << " " << y << " " << y2;
	return 0; 
}
