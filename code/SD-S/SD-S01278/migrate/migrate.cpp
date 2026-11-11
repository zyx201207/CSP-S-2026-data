//track in time
//Yh0326 448917 in Luogu
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l;i <= r;++ i)
#define per(i, r, l) for(int i = r;i >= l;-- i)
using namespace std;
typedef long long ll;
inline ll read()
{
	ll s = 0, w = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-'){w = -1;}ch = getchar();}
	while(isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
	return s * w;
}
const int mod = 998244353;
inline int ksm(int a, int n)
{
	int ans = 1;
	while(n)
	{
		if(n & 1) ans = (ll)ans * a % mod;
		a = (ll)a * a % mod;
		n >>= 1;
	}
	return ans;
}
int c, T;
int n, cnt;
ll d;
ll a[2000003];
int l[2000003], r[2000003];
int f[5003];
ll s[5003];
inline void solve_n2()
{
	l[1] = 1;
	rep(i, 2, n)
		rep(j, l[i - 1], i)
			if(a[i] - a[j] <= d)
			{
				l[i] = j;
				break;
			}
	r[n] = n;
	per(i, n - 1, 1)
		per(j, r[i + 1], i)
			if(a[j] - a[i] <= d)
			{
				r[i] = j;
				break;
			}
	int L, R, ans = 0, stp;
	int le, ri, lst0, lst1;
	rep(i, 1, n)
	{
		f[i] = 0, s[i] = 1;
		rep(j, i + 1, r[i]) f[j] = s[j] = 1, s[j] += s[j - 1];
		lst1 = r[i], stp = 1;
		if(r[i] != i)
			rep(j, r[i] + 1, n)
			{
				if(j == l[j]) break;
				f[j] = f[l[j]] + 1;
				if(f[j] > stp)
				{
					stp = f[j];
					lst0 = lst1;
				}
				lst1 = j;
				s[j] = s[j - 1] + (s[lst0] - s[l[j] - 1]);
				ans += (s[lst0] - s[l[j] - 1] == 2);
			}
	}
	cout << ans << '\n';
}
inline void solveA()
{
	ll m = d / (a[2] - a[1]);
	m = min(m, (ll)n);
	if(m >= n - 1 || m <= 1) return (void)(puts("0"));
	cout << max(0ll, n + 1 - m * 2) << '\n';
}
inline void solveB()
{
	cnt = 0;
	int p, ans = 0;
	l[1] = 1;
	rep(i, 2, n)
		rep(j, l[i - 1], i)
			if(a[i] - a[j] <= d)
			{
				l[i] = j;
				break;
			}
	r[n] = n;
	per(i, n - 1, 1)
		per(j, r[i + 1], i)
			if(a[j] - a[i] <= d)
			{
				r[i] = j;
				break;
			}
	rep(i, 1, n)
		if(l[i] == 1 && r[i] == n) ++ cnt, p = i;
	if(cnt > 2) return (void)(puts("0"));
	if(cnt == 1)
	{
		rep(i, 1, p - 1)
			if(r[i] == p && l[p + 1] == p - 1) ++ ans;
			else if(r[i] == p + 1 && l[p + 2] == p) ++ ans;
		cout << ans << '\n';
	}
	else
	{
		rep(i, 1, p - 2)
			if(r[i] == p && l[p + 1] == p - 1) ++ ans;
		cout << ans << '\n';
	}
}
/*
0 1
7 3
-4 -2 0 1 2 3 5

6
*/
//inline void solveC()
//{
//	l[1] = 1;
//	rep(i, 2, n)
//		rep(j, l[i - 1], i)
//			if(a[i] - a[j] <= d)
//			{
//				l[i] = j;
//				break;
//			}
//	r[n] = n;
//	per(i, n - 1, 1)
//		per(j, r[i + 1], i)
//			if(a[j] - a[i] <= d)
//			{
//				r[i] = j;
//				break;
//			}
//	int L, R, mid, lst, lst0, lst1;
//	int ql, qr;
//	ll ans = 0;
//	rep(i, 1, n - 1)
//	{
//		lst = i;
//		lst0 = 0, lst1 = 1;
//		rep(j, 1, 10)
//		{
//			if(l[lst + 1] == lst + 1) break;
//			L = lst + 1, R = n;
//			while(L <= R)
//			{
//				mid = (L + R) >> 1;
//				if(a[mid] - a[i] <= (__int128)j * d) L = mid + 1;
//				else R = mid - 1;
//			}
//			ql = lst + 1, qr = L - 1;
//			//lst + 1 ~ L - 1;
//			if(lst0 == 0)
//			{
//				if(lst1 == 2) ans += qr - ql + 1;
//				if(ql != qr) lst0 = lst1;
//			}
//			else
//			{
//				if(ql == qr)
//				{
//					if(l[qr] < lst - 1) break;
//					if(l[qr] == lst - 1) lst1 = lst0 + lst1;
//					lst0 = 0;
//					if(lst1 > 2) break;
//					ans += (lst1 == 2);
//				}
//				else if(lst0 + lst1 == 2)
//				{
//					L = ql, R = qr;
//					while(L <= R)
//					{
//						mid = (L + R) >> 1;
//						if(l[mid] < lst - 1) L = mid + 1;
//						else R = mid - 1;
//					}
//					//R + 1
//					if(R == qr) break;
//					if(l[R + 1] == lst)
//					{
//						if(R + 1 <= qr - 1) lst0 = lst1;
//						else lst0 = 3;
//					}
//					else
//					{
//						cnt = R + 1;
//						L = cnt, R = qr;
//						while(L <= R)
//						{
//							mid = (L + R) >> 1;
//							if(l[mid] == lst - 1) L = mid + 1;
//							else R = mid - 1;
//						}
//						//cnt ~ L - 1
//						ans += L - cnt;
//						if(L - 1 < qr - 1) lst0 = lst1;
//						else if(L - 1 == qr - 1) lst0 = 2;
//						else lst0 = lst1 = 2;
//					}
//				}
//				else
//				{
//					L = ql, R = qr;
//					while(L <= R)
//					{
//						mid = (L + R) >> 1;
//						if(l[mid] <= lst - 1) L = mid + 1;
//						else R = mid - 1;
//					}
//					//R + 1 ~ qr
//					if(R == qr) break;
//					if(lst1 == 2) ans += qr - R;
//					if(R + 1 <= qr - 1) lst0 = lst1;
//					else lst0 = 3;
//				}
//			}
//			lst = qr;
//			if(qr == n) break;
//		}
//	}
//	cout << ans << '\n';
//}
inline void solve()
{
	n = read(), d = read();
	rep(i, 1, n) a[i] = read();
	if(n <= 5000) return (void)(solve_n2());
	if(c == 11 || c == 12) return (void)(solveA());
	if(c == 13 || c == 14) return (void)(solveB());
//	if(a[n] - a[1] <= (__int128)d * 10) return (void)(solveC());
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	c = read(), T = read();
	while(T --) solve();
	return 0;
}
/*

O(n^2) is easy to approach.

Let's warm up with this part.

*/
