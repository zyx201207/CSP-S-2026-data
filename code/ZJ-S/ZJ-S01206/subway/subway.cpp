#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
int c,n,m,d,q;
ll w[N];
struct Node {
	int x;
	ll y;
};
vector<Node> a[505];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for (int i=1;i<=m;i++) {
		scanf("%lld",&w[i]);
	}
	for (int i=1;i<=n;i++) {
		int k;
		scanf("%d",&k);
		for (int j=1;j<=k;j++) {
			int x;
			ll y;
			scanf("%d%lld",&x,&y);
			a[i].push_back({x,y});
		}
	}
	while (q--) {
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",w[x]+w[y]);
	}
	return 0;
}
