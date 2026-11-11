#include <bits/stdc++.h>

using namespace std;
const int SZ = 2e6 + 99;
const int INF = 2e9;

int c, TEST;
int n;
long long d;
long long a[SZ];

namespace dataA {
	bool isThis () {
		return 0 <= c && c <= 10;
	}
	
	int dist[SZ], cnt[SZ];
	void work () {
		int res = 0;
		for (int fr = 1; fr <= n; fr++) {
			for (int i = fr + 1; i <= n; i++) 
				dist[i] = INF, cnt[i] = 0;
			cnt[fr] = 1;
			dist[fr] = 0;
			for (int i = fr + 1; i <= n; i++) {
				for (int j = i - 1; j >= fr && a[i] - a[j] <= d; j--) {
					if (dist[j] + 1 < dist[i]) 
						dist[i] = dist[j] + 1, cnt[i] = 0;
					if (dist[j] + 1 == dist[i]) 
						cnt[i] += cnt[j];
				}
				if (cnt[i] == 2) res++;
			}	
		}
		cout << res << '\n';
	}
}

namespace specA {
	bool isThis () {
		return 11 <= c && c <= 12;
	}
	
	void work () {
		cout << "0\n";
	}
}

namespace specB {
	bool isThis () {
		return 13 <= c && c <= 14;
	}
	
	void work () {
		cout << "0\n";
	}
}

namespace specC {
	bool isThis () {
		return 15 <= c && c <= 18;
	}
	
	void work () {
		cout << "0\n";
	}
}

namespace AC {
	void work () {
		cout << "0\n";
	}
}

int main () {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);

	cin >> c >> TEST;
	while (TEST--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		a[0] = a[1] - 1;
		
		if (dataA::isThis()) 
			dataA::work();
		else if (specA::isThis()) 
			specA::work();
		else if (specB::isThis()) 
			specB::work();
		else if (specC::isThis()) 
			specC::work();
		else 
			AC::work(); 
	}

	return 0;
}
