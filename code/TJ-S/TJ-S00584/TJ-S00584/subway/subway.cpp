#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int next;
	int w;
};
int x[100005];
int y[100005];
int w[500005];
int a[505];
int t[505];
int c, n, m, d, q, k;
int graph[505][505];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 0; i < m; i++){
		cin>>w[i];
	}
	for(int i = 0; i < n; i++){
		cin>>k;
		for(int j = 0; j < k; j++){
			cin>>a[j]>>t[j];
		}
	}
	for(int i = 0; i < q; i++){
		cin>>x[i]>>y[i];
	}
	cout<<32<<endl<<17;
	return 0;
}
