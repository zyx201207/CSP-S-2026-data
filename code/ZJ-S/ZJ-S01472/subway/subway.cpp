#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10

int w[N];
struct str{
	int a,b;
};
vector<str> a[512];
int l[N],t[N][512];

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for (int i = 1;i <= n;i++){
		int k;
		cin >> k;
		for (int j = 1;j <= k;j++){
			int x,y;
			cin >> x >> y;
			l[x] = i;
			a[i].push_back({x,y});
		}
	}
	return 0;
}

