#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int c, n, m, d, q, k;
ll w[500005];
ll a[505][500005];
ll t[505][500005];
int s1[100005], s2[100005];

int main(){
	//freopen("subway.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	
	cin>>c>>n>>m>>d>>q;
	for(int i = 0; i < m; i++){
		cin>>w[i];
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		for(int j = 0; j < k; j++){
			scanf("%lld%lld", &a[i][j], &t[i][j]);
		}
	}
	for(int i = 0; i < q; i++){
		scanf("%d%d", &s1[i], &s2[i]);
	}
	
	return 0;
}
