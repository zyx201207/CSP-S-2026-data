#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAXN = 500010;
int n, m;
long long a[MAXN];
bool checkA() {
    for (int i = 1; i <= n - 1; i++) {
        if (a[i] != a[i + 1]) return false;
    }
    return true;
}

bool checkB() {
    for (int i = 1; i <= n - 2; i++) {
        if (a[i + 1] - a[i] != a[i + 2] - a[i + 1]) return false;
    }
    return true;
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    if (checkA()) cout << n << endl;
    else if (checkB()) {
        sort(a + 1, a + n + 1, cmp);
        long long d = a[1] - a[2];
        long long biggest = a[1];
        long long cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (m - (biggest - a[i]) >= 0) {
            	m -= (biggest - a[i]);
                cnt++;
            }
        }  
        cout << cnt;
    } else {
    	vector<vector<long long>> diff(n + 1, vector<long long>(n + 1));
    	long long glo_cnt = 0;
    	for (int i = 1; i <= n; i++) {
    		for (int j = 1; j <= n; j++) {
    			diff[i][j] = a[i] - a[j];
			}
			sort(diff[i].begin() + 1, diff[i].end());
			
			int cur = m;
			long long cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (cur < 0) break;
				if (diff[i][j] >= 0) {
					cur -= diff[i][j];
					cnt++;
				}
			}
			glo_cnt = max(cnt, glo_cnt);
		}
		cout << glo_cnt;
	}
    return 0;
}