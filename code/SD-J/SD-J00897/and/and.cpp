#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool s[200007][35];
int n, m, a[200007], wei[200007], maxx = -999;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		int kl = a[i];
		while(kl) {
			wei[i]++;
			s[i][wei[i]] = kl % 2;
			kl /= 2;
		}
		maxx = max(maxx, wei[i]);
	}
	if (n == m) {
		int s = a[1];
		for (int i = 2; i <= n; i++) s &= a[i];
		cout << s;
		return 0;
	}
	if (m == 1) {
		int s = -99;
		for (int i = 1; i <= n; i++) s = max(s, a[i]);
		cout << s;
		return 0;
	}
	if (m == 2) {
		int s = -999;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				s = max(s, a[i]&a[j]);
		cout << s;
		return 0;
	}
	for (int i = maxx; i > 0; i--) {
		
	}
	return 0;
}

