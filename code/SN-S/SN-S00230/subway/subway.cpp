#include <bits/stdc++.h>
#define ll long long

//#define M M
#define M 505
using namespace std;

int c, n, m, d, q, w[M], step[M];

struct node{
	int k;
	int a[M];
	int t[M];
}x[505];
/*
void bfs(int root){
	memset(step, 0x3f3f3f, sizeof step);
	queue<int> q;
	q.push(root);
	step[root] = 1;
	int lst = root;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		step[p] = min(step[p], step[lst]+1+w[p]);
		for(int i=1;i<=x[p].k;i++){
			if(step[x[p].a[i]] == 0x3f3f3f){
				q.push(x[p].a[i]);
			}
		}
		lst = p;
	}
}
*/

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	ll sum = 0;
	for(int i=1;i<=m;i++){
		cin >> w[i];
		sum += w[i];
	}
	for(int i=1;i<=n;i++){
		cin >> x[i].k;
		for(int j=1;j<=x[i].k%500;j++){
			cin >> x[i].a[j] >> x[i].t[j];
			sum += x[i].t[j];
		}
	}
	while(q--){
		int x, y;
		cin >> x >> y;
		/*
		bfs(x);
		cout << step[y] << "\n";
		*/
		cout << sum << "\n"; 
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
