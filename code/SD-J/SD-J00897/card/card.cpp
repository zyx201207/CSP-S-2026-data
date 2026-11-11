#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m, a[100005], s[100005], t[100005], r[100005];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		int k = i - 1;
		memset(s, 0, sizeof(s));
		memset(r, 0, sizeof(r));
		for (int j = i; j <= n; j++){
			if (s[a[j]]) {
				for (int l = s[a[j]] + 1; l < j; l++) {
					s[r[l]] = 0;
					r[l] = 0;
				}
				k = s[a[j]];
			}
			else {
				k++;
				r[k] = a[j];
				s[a[j]] = k;
			}
		}
		for (int j = 1; j <= k; j++) {
			t[r[j]]++;
		}
	}
	for (int i = 1; i <= m; i++) cout << t[i] << ' ';
	return 0;
}
