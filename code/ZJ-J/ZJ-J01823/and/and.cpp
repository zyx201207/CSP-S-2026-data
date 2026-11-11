#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum;
vector <long long> cnt[45];
bool vis[45];
int main () {
	freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
	cin >> n >> m;
	for (long long i = 1;i <= n;i ++) {
		cin >> a[i];
		for (long long j = 0;j <= 39 && (1 << j) <= a[i] ;j ++)
			if ((a[i] >> j) & 1)
				cnt[j].push_back (a[i]);
	}	
	long long bj = -2;
	while (bj != -1) {
		bj = -1;
		for (long long i = 39;i >= 0;i --) {
			if (cnt[i].size () >= m && !vis[i]) {
				bj = i;
				break;
			}
		}
		if (bj == -1)break;	
		vis[bj] = 1;	
		sum |= (1 << bj);
		vector <long long> v;
		long long len = cnt[bj].size ();
		for (long long i = 0;i < len;i ++)
			v.push_back (cnt[bj][i]);
		for (long long i = 0;i <= 39;i ++)
			cnt[i].clear ();
		len = v.size ();
		for (long long i = 0;i < len;i ++)
			for (long long j = 0;(1 << j) <= v[i];j ++)
			if ((v[i] >> j) & 1)
				cnt[j].push_back (v[i]);		
	}
	cout << sum;
	return 0;
}
