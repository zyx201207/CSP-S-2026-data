#include<bits/stdc++.h> /*_*/
using namespace std;
// T1-crystal

#define int long long
const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int a[N], s[N];
int sub[N];

//Ьиад 
bool A = 1, B = 1;
int subB;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if(i > 1 && a[i] != a[i - 1]) A = 0;
		if(i == 2) subB = a[i] - a[i - 1];
		else if(i > 2 && a[i] - a[i - 1] != subB) B = 0;
	}
	if(A)
	{
		cout << n << endl;
		return 0;
	}
	if(B)
	{
		int i;
		for(i = 1; i <= n && m - i * subB >= 0; i ++)
			m -= i * subB;
		cout << i << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	
	int maxv = 0;
	for(int i = 1; i <= n; i ++)
	{
		for(int j = 1; j <= i; j ++)
			sub[j] = a[i] - a[j];
		sort(sub + 1, sub + i + 1);
		
		int tmp = m, cnt = 0;
		for(int j = 1; j <= i && tmp - sub[j] >= 0; j ++)
			tmp -= sub[j], cnt ++;
		maxv = max(maxv, cnt);
	}
	cout << maxv << endl;
	
	return 0;
}
/*
5 5
1 2 4 8 9

Oct31==Dec25?
*/
