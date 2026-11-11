#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long a[N], n, r, ansd[35], d[35], ans = 0, lsd[35];
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	for(int i = 0; i <= 30; i++) d[i] = pow(2, i);
	cin >> n >> r;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++)
	{
		long long l, r, mid, x = a[i];
		if(a[i] == 0) continue;
		while(x)
		{
			l = 0;
			r = 30;
			mid = (l + r) / 2;
			while((d[mid] <= x && (d[mid + 1] > x || mid == 30)) == 0)
			{
				mid = (l + r) / 2;
				if(d[mid]>  x) r = mid - 1;
				if(d[mid] <= x && d[mid + 1] <= x) l = mid + 1;
			}
			x -= d[mid];
			ansd[mid]++;
		}
	}
	for(int i = 0; i <= 30; i++) if(ansd[i] >= r) lsd[ansd[i]] += d[i];
	for(int i = 0; i <= 30; i++) ans = max(ans, lsd[i]);
	cout << ans;
	return 0;
} 
