#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int a[1000005], cnt[1000005];
int n, m, ans = INT_MIN;
void subtask1()
{
	for (int i = 1; i <= n; i ++)
		ans = max(ans, a[i]);
	cout << ans << endl;
	return ;
}
void subtask2()
{
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j < i; j ++)
		{
			ans = max(ans, a[i] & a[j]);
//			cout << a[i] << " " << a[j] << " " << (a[i] ^ a[j] ) << endl;
		}
			
	}
	//cout << 12 ^ 3 << endl;
	//cout << 1 << endl; 
	cout << ans << endl;
	return ;
}
void subtask3()
{
	int t = a[1];
	for (int i = 2; i <= n; i ++)
		t &= a[i];
	cout << t << endl;
	return ;
}
void subtask4()
{
	for (int i = n - m + 1; i <= n; i ++)
		cnt[i] = 1;
	do
	{
//		for (int i = 1; i <= n; i ++)
//			cout << cnt[i] << " ";
//		cout << endl;
		int t, ok = 0;
		for (int i = 1; i <= n; i ++)
			if (cnt[i] == 1 && ok == 0) t = a[i], ok = 1;
			else if (cnt[i] == 1 && ok == 1) t &= a[i];
		//cout << t << endl;
		ans = max(ans, t);
	}while ( next_permutation(cnt + 1, cnt + 1 + n) );
	cout << ans << endl;
	return ;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out","w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	if (m == 1) subtask1();
	else if (m == 2) subtask2();
	else if (m == n) subtask3();
	else subtask4();
	//cout << ans << endl;
	return 0;
} 
