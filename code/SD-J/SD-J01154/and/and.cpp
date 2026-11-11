#include <bits/stdc++.h>
#define ll long long
#define TIE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n,m,a[200005],ma = 0,x,g = 0;
bool t = true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	TIE
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != i - 1) t = false;
		ma = max(ma,a[i]);
	}
	if (m == 1) 
	{
		cout << ma;
		return 0;
	}
	if (t)
	{
		g = n - 1;
		m--;
		for (int i = n / 2; i > 0 && m > 0; i /= 2)
		{
			g &= (i - 1);
			m--;
		}
		if (m > 0) cout << 0;
		else cout << g;
		return 0;
	}
	sort(a + 1, a + n + 1);
	g = a[n];
	m--;
	for (int i = n - 1; i > 0 && m > 0; i--)
	{
		g &= a[i];
		m--;
	}
	cout << g;
	return 0;
} 
