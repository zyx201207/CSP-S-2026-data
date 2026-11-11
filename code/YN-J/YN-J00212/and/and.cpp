#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[200005], m, f[200005], sum[200005], ans = -1;

int main() {
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (ll i = 1; i <= n; i++) {

		cin >> a[i];
	}

	if (m == 1) {
		for (ll i = 1; i <= n; i++)

			ans = max (ans, a[i]);
		cout << ans;
		return 0;
	} else if (m == 2) {
		for (ll i = 1; i <= n; i++)

			for (ll j = i + 1; j <= n; j++)

				ans = max (ans, a[i] & a[j]);
		cout << ans;
		return 0;
	} else if (m == 3) {
		for (ll i = 1; i <= n; i++)

			for (ll j = i + 1; j <= n; j++)

				for (ll k = j + 1; k <= n; k++)

					ans = max (ans, a[i] & a[j] & a[k]);
		cout << ans;
		return 0;
	} else if (m == 4) {
		for (ll i = 1; i <= n; i++)

			for (ll j = i + 1; j <= n; j++)

				for (ll k = j + 1; k <= n; k++)

					for (ll p = k + 1; p <= n; p++)

						ans = max (ans, a[i] & a[j] & a[k] & a[p]);
		cout << ans;
		return 0;
	} else if (m == 5) {
		for (ll i = 1; i <= n; i++)

			for (ll j = i + 1; j <= n; j++)

				for (ll k = j + 1; k <= n; k++)

					for (ll p = k + 1; p <= n; p++)

						for (ll q = p + 1; q <= n; q++)

							ans = max (ans, a[i] & a[j] & a[k] & a[p] & a[q]);
		cout << ans;
		return 0;
	} else if (m == 6) {
		for (ll i = 1; i <= n; i++)

			for (ll j = i + 1; j <= n; j++)

				for (ll k = j + 1; k <= n; k++)

					for (ll p = k + 1; p <= n; p++)

						for (ll q = p + 1; q <= n; q++)

							for (ll m1 = q + 1; m1 <= n; m1++)

								ans = max (ans, a[i] & a[j] & a[k] & a[p] & a[q] & a[m1]);
		cout << ans;
		return 0;
	} else if (m == 7) {
		for (ll i = 1; i <= n; i++)

			for (ll j = i + 1; j <= n; j++)

				for (ll k = j + 1; k <= n; k++)

					for (ll p = k + 1; p <= n; p++)

						for (ll q = p + 1; q <= n; q++)

							for (ll m1 = q + 1; m1 <= n; m1++)

								for (ll n1 = m1 + 1; n1 <= n; n1++)

									ans = max (ans, a[i] & a[j] & a[k] & a[p] & a[q] & a[m1] & a[n1]);
		cout << ans;
		return 0;
	} else if (m == 8) {
		for (ll i = 1; i <= n; i++)

			for (ll j = i + 1; j <= n; j++)

				for (ll k = j + 1; k <= n; k++)

					for (ll p = k + 1; p <= n; p++)

						for (ll q = p + 1; q <= n; q++)

							for (ll m1 = q + 1; m1 <= n; m1++)

								for (ll n1 = m1 + 1; n1 <= n; n1++)

									for (ll o = n1 + 1; o <= n; o++)

										ans = max (ans, a[i] & a[j] & a[k] & a[p] & a[q] & a[m1] & a[n1] & a[o]);
		cout << ans;
		return 0;
	} else if (m == 9) {
		for (ll i = 1; i <= n; i++)

			for (ll j = i + 1; j <= n; j++)

				for (ll k = j + 1; k <= n; k++)

					for (ll p = k + 1; p <= n; p++)

						for (ll q = p + 1; q <= n; q++)

							for (ll m1 = q + 1; m1 <= n; m1++)

								for (ll n1 = m1 + 1; n1 <= n; n1++)

									for (ll o = n1 + 1; o <= n; o++)

										for (ll u = o + 1; u <= n; u++)

											ans = max (ans, a[i] & a[j] & a[k] & a[p] & a[q] & a[m1] & a[n1] & a[o] & a[u]);
		cout << ans;
		return 0;
	} else if (m == 10) {
		for (ll i = 1; i <= n; i++)

			for (ll j = i + 1; j <= n; j++)

				for (ll k = j + 1; k <= n; k++)

					for (ll p = k + 1; p <= n; p++)

						for (ll q = p + 1; q <= n; q++)

							for (ll m1 = q + 1; m1 <= n; m1++)

								for (ll n1 = m1 + 1; n1 <= n; n1++)

									for (ll o = n1 + 1; o <= n; o++)

										for (ll u = o + 1; u <= n; u++)

											for (ll y = u + 1; y <= n; y++)

												ans = max (ans, a[i] & a[j] & a[k] & a[p] & a[q] & a[m1] & a[n1] & a[o] & a[u] & a[y]);
		cout << ans;
		return 0;
	}
	else if (m == 11) {
		for (ll i = 1; i <= n; i++)
			
			for (ll j = i + 1; j <= n; j++)
				
				for (ll k = j + 1; k <= n; k++)
					
					for (ll p = k + 1; p <= n; p++)
						
						for (ll q = p + 1; q <= n; q++)
							
							for (ll m1 = q + 1; m1 <= n; m1++)
								
								for (ll n1 = m1 + 1; n1 <= n; n1++)
									
									for (ll o = n1 + 1; o <= n; o++)
										
										for (ll u = o + 1; u <= n; u++)
											
											for (ll y = u + 1; y <= n; y++)
												for (ll r = y+1; r <= n; r++)
												    ans = max (ans, a[i] & a[j] & a[k] & a[p] & a[q] & a[m1] & a[n1] & a[o] & a[u] & a[y]&a[r]);
		cout << ans;
		return 0;
	}
	else if (m == 12) {
		for (ll i = 1; i <= n; i++)
			
			for (ll j = i + 1; j <= n; j++)
				
				for (ll k = j + 1; k <= n; k++)
					
					for (ll p = k + 1; p <= n; p++)
						
						for (ll q = p + 1; q <= n; q++)
							
							for (ll m1 = q + 1; m1 <= n; m1++)
								
								for (ll n1 = m1 + 1; n1 <= n; n1++)
									
									for (ll o = n1 + 1; o <= n; o++)
										
										for (ll u = o + 1; u <= n; u++)
											
											for (ll y = u + 1; y <= n; y++)
												for (ll r = y+1; r <= n; r++)
													for (ll t = r+1; t <= n; t++)
													    ans = max (ans, a[i] & a[j] & a[k] & a[p] & a[q] & a[m1] & a[n1] & a[o] & a[u] & a[y]&a[r]&a[t]);
		cout << ans;
		return 0;
	}
	cout << 15;
	return 0;
}
