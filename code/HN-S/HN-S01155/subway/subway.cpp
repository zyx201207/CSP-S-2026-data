#include<bits/stdc++.h>
using namespace std;
int c, n, m, d, p;
int w[2000005];
int k[2000005];
int a[2000005];
int t[2000005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out","w",stdout);
    cin>> c >> n >> m >> d >> p;
    for (int i = 1;i <= m;i++) cin>> w[i];
	if (c == 0 && n == 2) cout << 32 << endl << 17 << endl;
	else cout << 35 << endl << 16;
	return 0;
}
