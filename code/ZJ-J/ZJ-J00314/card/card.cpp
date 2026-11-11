#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const int M = 3e5+5;
struct node{
	int vis=0, id;
}q[M];
int n, m, a[N], b[M], c[M];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
	}
	for(int nn = 1; nn <= n; nn ++){
		int k = 0;
		for(int i = 1; i <= m; i ++){
			q[i].vis = 0;
		}
		for(int i = nn; i <= n; i ++){
			if(q[a[i]].vis == 0){
				b[++k] = a[i];
				q[a[i]].vis = 1;
				q[a[i]].id = k;
			}
			else{
				int kk = k;
				k = q[a[i]].id - 1;
				for(int j = q[a[i]].id; j <= kk; j ++){
					q[b[j]].vis = 0;
					q[a[i]].id = 0;
				}
				b[++k] = a[i];
				q[a[i]].vis = 1;
				q[a[i]].id = k;
			}
		}
		for(int i = 1; i <= k; i ++){
			c[b[i]] ++;
		}
	}
	for(int i = 1; i <= m; i ++){
		cout << c[i] << " ";
	}
	return 0;
}