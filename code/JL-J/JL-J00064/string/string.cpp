#include <bits//stdc++.h>
using namespace std;
int n, a[200005];
long long len;
char c[200005];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
		len += a[i];
	}
	int mid_id = 1;
	long long sum = 0, mid_d = (len + 1) / 2;
	while(sum < mid_d)
	{
		sum += a[mid_id++];
	}
	mid_id--;
	long long l = (len + 1) / 2, r = (len + 2) / 2;
	int t = a[mid_id];
	if(len % 2)
	{
		a[mid_id]--;
		l--;
		r++;
	}
	int cmp = min(l - sum + t, sum + 1 - r);
	l -= cmp;
	r += cmp;
	a[mid_id] -= cmp * 2;
	if(l == sum - t)
	{
		mid_id--;
	}
	sum = 0;
	l = mid_id, r = mid_id + 1;
	while(l != 1 || r != n || a[l] != 0 || a[r] != 0)
	{
		while(a[l] == 0)
			l--;
		while(a[r] == 0)
			r++;
		int ch = min(a[l], a[r]);
		if(c[l] != c[r])
		{
			sum += ch;
		}
		a[l] -= ch;
		a[r] -= ch;
	}
	cout << sum;
	return 0;
}
/*..... aaaaaa......a[min_id] = 6
 *         ^  
 * 
 * */
