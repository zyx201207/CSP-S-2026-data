#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define x first
#define y second
#define V vector
#define pb push_back
#define INF (int)1e18
using namespace std;

const int maxn = 2e6;

int n;
int x[maxn+5];
int to[maxn+5];
int dis[maxn+5];
int cnt[maxn+5];

int TT = 0;

int solveb()
{
	int d;
	cin >> n >> d;
	for(int i = 1; i <= n; ++i)
		cin >> x[i];
	for(int i = 1; i <= n; ++i)
		to[i] = lower_bound(x+1, x+n+1, x[i]+d+1)-x-1;
//	cin >> n;
//	for(int i = 1; i <= n; ++i)
//		cin >> to[i];

	if(to[1] <= 2)
		return cout << "0\n", 0;
	int fst = (to[1]-1) * 2;
//	for(int i = 1; i <= n; ++i)
//		cout << ' ' << to[i]; cout << '\n';
	int ans = 0;
	for(int s = 1; s <= n; ++s)
	{
		ans += (n-s+1 >= fst);
//		cout << ' ' << sum << '\n';
//		break;
	}
//	int cc = 0;
//	for(int s = 1; s <= n; ++s)
//	{
//		for(int i = 0; i <= n; ++i)
//			dis[i] = INF, cnt[i] = 0;
//		cnt[s] = 1, dis[s] = 0;
//		int d = 0;
//		for(int i = s; i <= n; ++i)
//		{
////			dis[i] = d++;
//			for(int j = i+1; j <= to[i]; ++j)
//			{
//				if(dis[j] > dis[i]+1)
//					dis[j] = dis[i]+1, cnt[j] = 0;
//				if(dis[j] == dis[i]+1)
//					cnt[j] += cnt[i];
//	//			else assert(0);
//			}
//		}
//		
//		for(int i = s; i <= n; ++i)
//			if(cnt[i] == 2)
//				++cc;
////		for(int i = s; i <= n; ++i)
////			cout << dis[i] << " \n"[i==n];
////		for(int i = s; i <= n; ++i)
////			cout << cnt[i] << " \n"[i==n];
////		cout << '\n';
//	}
//	++TT;
//	cout << TT << ' ';
//	cout << cc << ' ';
	cout << ans << '\n';
//	assert(cc == ans);
	
	return 0;
}

int solve()
{
	int d;
	cin >> n >> d;
	for(int i = 1; i <= n; ++i)
		cin >> x[i];
	for(int i = 1; i <= n; ++i)
		to[i] = lower_bound(x+1, x+n+1, x[i]+d+1)-x-1;
//	cin >> n;
//	for(int i = 1; i <= n; ++i)
//		cin >> to[i];

//	for(int i = 1; i <= n; ++i)
//		cout << ' ' << to[i]; cout << '\n';
	int ans = 0;
	for(int s = 1; s <= n; ++s)
	{
		int lst = s-1;
		int sum = 0, num = 1, num2 = 1;
		for(int i = s; i <= n && lst != i; lst = i, i = to[i])
		{
//			cout << "  " << i << ' ' << lst << ' ' << sum << ' ' << nu. << '\n';
//			printf("[%d, %d]: cnt[%d]=%d cnt[%d-1]=%d, sum = %d\n", lst+1, i, i, num, i, num2, sum);
			if(num > 2) break;
			if(num == 1)
			{
				if(i-lst == 1)
					;
				else if(i-lst == 2)
				{
					if(num2 == 1)
						sum += to[i-1]-i;
				}
				else if(i-lst >= 3)
				{
					if(num2 == 1)
						sum += to[i-1]-to[i-2];
				}
				if(i-lst >= 2 && to[i] == to[i-1]) num = (to[i-1] == to[i-2] ? 3 : num2+1);
				if(i-lst >= 2 && to[i-1] == to[i]-1) num2 = 2;
				else if(to[i]-1 == i) num2 = num;
				else num2 = 1;
			}
			else
			{
				if(i-lst == 1)
				{
					sum += to[i]-i;
				}
				else if(i-lst >= 2)
				{
					sum += to[i]-to[i-1];
				}
				if(to[i] == to[i-1]) break;
			}
		}
		ans += sum;
//		cout << ' ' << sum << '\n';
//		break;
	}
//	int cc = 0;
//	for(int s = 1; s <= n; ++s)
//	{
//		for(int i = 0; i <= n; ++i)
//			dis[i] = INF, cnt[i] = 0;
//		cnt[s] = 1, dis[s] = 0;
//		int d = 0;
//		for(int i = s; i <= n; ++i)
//		{
////			dis[i] = d++;
//			for(int j = i+1; j <= to[i]; ++j)
//			{
//				if(dis[j] > dis[i]+1)
//					dis[j] = dis[i]+1, cnt[j] = 0;
//				if(dis[j] == dis[i]+1)
//					cnt[j] += cnt[i];
//	//			else assert(0);
//			}
//		}
//		
////		for(int i = s; i <= n; ++i)
////			if(cnt[i] == 2)
////				++cc;
//		for(int i = s; i <= n; ++i)
//			cout << dis[i] << " \n"[i==n];
//		for(int i = s; i <= n; ++i)
//			cout << cnt[i] << " \n"[i==n];
//		cout << '\n';
//		break;
//	}
//	for(int i = 1; i <= n; ++i)
//		if(cnt[i] == 2)
//			cout << i << '\n';
//	++TT;
//	cout << TT << ' ';
//	cout << cc << ' ';
	cout << ans << '\n';
//	assert(cc == ans);
	
	return 0;
}

/*
0 1
7
3 4 5 6 6 7 7

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
7
3 4 5 6 7 7 7

0 1
20
3 4 6 7 8 8 9 11 13 13 13 15 16 17 17 18 20 20 20 20
*/

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	int c, T; cin >> c >> T;
	while(~--T)
		if(c >= 11 && c <= 12) solveb();
		else solve();

	return 0;
}
/*
migrate.exe < migrate1.in > migrate1.out
migrate.exe < migrate2.in > migrate2.out
migrate.exe < migrate3.in > migrate3.out
migrate.exe < migrate4.in > migrate4.out
migrate.exe < migrate5.in > migrate5.out

fc migrate1.out migrate1.ans
fc migrate2.out migrate2.ans
fc migrate3.out migrate3.ans
fc migrate4.out migrate4.ans
fc migrate5.out migrate5.ans
*/