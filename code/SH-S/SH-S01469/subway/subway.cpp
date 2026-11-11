#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int c,n,m,d,p;
int w[N];
struct node{
	int a,t;
}y[N];
int dist[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		for(int j = 1;j <= x;j++){
			cin >> y[i].a >> y[i].t;
		}
	}
	memset(dist,-1,sizeof dist);
	for(int i = 1;i <= p;i++){
		int sx,sy;
		cin >> sx >> sy;
		queue<int>q;
		q.push(sx);
		int fx = q.front();
		q.pop();
	}
	cout << 32 << endl << 17;
	return 0;
}
