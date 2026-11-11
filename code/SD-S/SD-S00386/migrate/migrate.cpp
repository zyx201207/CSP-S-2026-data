#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>

const int N = 2e6 + 2,kN = 5e3 + 2,inf = 1e18;
int a[N],book[kN][kN];
int n,d;

struct node{
	vector<int> v;
	int d = inf;
	int b = 0;
}pt[kN];

queue<int> bq;

/*
0 1
4 2
1 2 3 4
*/

int bfs(int x,int y){
	if(abs(a[y] - a[x]) <= d) return 0;
	for(int i = 1;i <= n;i++){
		pt[i].d = inf;
		pt[i].b = 0;
	}
	bq.push(x);
	pt[x].d = 0;
	pt[x].b = 1;
	int dist = inf;
	while(!bq.empty()){
		auto k = bq.front();
		bq.pop();
		if(pt[k].d >= dist) continue;
//		cout << k << ' ';
		for(int i : pt[k].v){
			if(i == y) dist = min(dist,pt[k].d + 1);
			if(!pt[i].b){
				pt[i].d = pt[k].d + 1;
				pt[i].b = pt[k].b;
				bq.push(i);
			}else if(pt[i].d == pt[k].d + 1) pt[i].b++;
		}
	}
//	cout << x << "->" << y << ":" << pt[y].b << "(" << dist << ")";
//    if(pt[y].b == 2) cout << x << '\\' << y << ' ';
	if(pt[y].b == 2) return 1;
	return 0;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin >> c >> T;
	while(T--){
		cin >> n >> d;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
		}
		if(c == 11||c == 12){
			int dq = a[n] - a[n - 1];
			if(dq * 2 > d){
				cout << 0 << '\n';
				continue;
			}
			int k = d / dq;
			cout << max(0LL,n - k * 2 + 1) << '\n';
		}else{
			memset(book,0,sizeof(book));
			for(int i = 1;i <= n;i++){
				pt[i].v.clear();
			}
			
			for(int i = 1;i <= n;i++){
				for(int j = i + 1;j <= n;j++){
					if(a[j] - a[i] > d) break;
					pt[i].v.emplace_back(j);
					pt[j].v.emplace_back(i);
				}
			}
			int ans = 0;
			for(int i = 1;i <= n;i++){
				for(int j = i + 2;j <= n;j++){
					ans += bfs(i,j);
				}
			}
			cout << ans << '\n';
		}		
	}
	return 0;
}
