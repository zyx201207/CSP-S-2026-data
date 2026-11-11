#include<bits/stdc++.h>
using namespace std;
const int N = 500005;
int n;
long long m , a[N];
int nxt[N];
int main ()
{
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen("1.txt" , "r" , stdin);
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	sort(a + 1 , a + 1 + n);
	reverse(a + 1 , a + 1 + n);
	long long sum = 0 , maxx = a[1];
	for(int i = 1 ; i <= n ; i++)
		sum += maxx - a[i];
	if(sum <= m)
	{
		cout << n;
		return 0;	
	} 
	int lst_pos = 1 , pos = 2;
	while(pos <= n)
	{
		while(a[pos] == a[lst_pos] && pos <= n)  pos++;
		if(pos > n)  nxt[lst_pos] = n + 1;
		else  nxt[lst_pos] = pos , lst_pos = pos , pos++;
	}
	if(nxt[n] != nxt[n - 1])  nxt[n] = n + 1;
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		if(nxt[i] == 0)  continue;
		long long rest = m;
		int j = i , cnt = 0;
		while(rest && j <= n && j)
		{
			int equ = nxt[j] - j;
			if(rest >= 1ll * equ * (a[i] - a[j]))
			{
				rest -= 1ll * equ * (a[i] - a[j]);
				cnt += equ;
				j = nxt[j];
			}
			else
			{
				cnt += rest / (a[i] - a[j]);
				break;
			}
		}
		ans = max(ans , cnt);
	}
	cout << ans;
} 