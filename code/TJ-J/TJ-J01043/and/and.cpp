#include<cstdio>
const int MAXN = 200010;
int n, m, a[MAXN];
struct SET
{
	bool f[MAXN];
	SET() {for(int i = 1; i <= n; ++ i) f[i] = false;}
	int count() {int cnt = 0; for(int i = 1; i <= n; ++ i) cnt += f[i]; return cnt;}
};
SET And(const SET &s1, const SET &s2)
{
	SET s3;
	for(int i = 1; i <= n; ++ i) s3.f[i] = s1.f[i] & s2.f[i];
	return s3;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
	SET sand;
	for(int i = 1; i <= n; ++ i) sand.f[i] = true;
	int ans = 0;
	for(int i = 30; i >= 0; -- i)
	{
		SET newset;
		for(int j = 1; j <= n; ++ j) if(a[j] >> i & 1) newset.f[j] = true;
		SET andset = And(sand, newset);
		if(andset.count() >= m)
		{
			sand = andset;
			ans += (1 << i);
		}
	}
	printf("%d\n", ans);
	return 0;
}
