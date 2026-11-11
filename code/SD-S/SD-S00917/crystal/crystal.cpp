#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 5e5;

int n,m;
int ans = 0;
int a[maxn + 100];
int w[maxn + 100];

signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

//	freopen("crystal4.in","r",stdin);
//	freopen("crystal4.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);


	cin >> n >> m;
	for(int i = 1;i <= n;i ++) {
		cin >> a[i];
	}
	
	sort(a + 1,a + 1 + n);
	for(int i = 2;i <= n;i ++) {
		w[i] = a[i] - a[i - 1];
	}


	int cnt = 0;
	int k = 0;
	for(int i = n,j = n;i >= 1;i --) {
		while(j >= 1 && cnt + (a[i] - a[j]) <= m) {
			cnt += (a[i] - a[j]);
			j --;
		}
		int k = i - j;
		ans = max(ans,k);
		cnt -= (k - 1) * (a[i] - a[i - 1]);
		j = min(j,i);
	}

	cout << ans;

	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/

/*

15:15

*/ 
