#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],t[505][500005],a[505][500005],need;
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin >> w[i];
    for(int i = 1;i <= n;i++) {
        cin >> k[i];
        for(int j = 1;j <= k[i];j++) {
            cin >> a[i][j] >> v[i][j];
        }
    }
    while(q--) {
        int x,y;
        cin >> x >> y;
        int need = w[x] + w[y] + t[x][x];
		cout << need << endl;
    }
    return 0;
}
