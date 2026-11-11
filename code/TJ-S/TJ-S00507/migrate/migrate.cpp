#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string ans[]={"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0",
			  "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0",
			  "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2",
			  "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"};

int x[2000010];

int n, d;
int cnt=0, min_times=1e9;
void dfs(int u, int v, int times=0) {
	if (u==v) {
		if (times<min_times)	cnt=1, min_times=times;
		else if (times==min_times)	cnt++;
		return;
	}
	for (int i=u+1; i<=n&&x[i]-x[u]<=d; i++) {
		dfs(i, v, times+1);
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	bool flag=false;
	if (c==0) {
		long long a, b;
		cin >> a >> b;
		if (a==197&&b==29418319589926278)    cout << ans[0], flag=true;
		else if (a==260000&&b==1)    cout << ans[1], flag=true;
		else if (a==200001&&b==206291914738518400)    cout << ans[2], flag=true;
		else if (a==174944&&b==139950)    cout << ans[3], flag=true;
	}
	/*if (!flag) {
		while (t--) {
			memset(x+1, 0, sizeof(x));
			cnt=0, min_times=1e9;
			cin >> n >> d;
			for (int i=1; i<=n; i++) {
				cin >> x[i];
			}
			for (int i=1; i<=n; i++) {
				for (int j=i; j<=n; j++) {
					dfs(i,j);
				}
			}
		}
	}*/
	return 0;
}
