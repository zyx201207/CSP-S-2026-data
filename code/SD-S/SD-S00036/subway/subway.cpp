#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define fi first
#define se second
int c,n,m,d,Q;
int w[500005],k[505];
vector<PII> e[505];
vector<int> ct[500005];
struct node{
	int u,p,cst;
};
int bfs(int l,int r){
	queue<node> q;
	q.push({l,ct[l][0],w[l]});
	int ans = 0x3f3f3f3f;
	while(q.size()){
		int u = q.front().u;
		int p = q.front().p;
		int cst = q.front().cst;
		if(u == r){
			return cst + w[r];
		}
		q.pop();
		for(PII i : e[p]){
			int v = i.fi,pr = i.se;
			if(v == u){
				cst += pr;
				continue;
			}
			for(int to : ct[v]){
				q.push({v,to,cst + pr});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(nullptr),cout.tie(nullptr);
	ios::sync_with_stdio(false); 
	cin >> c >> n >> m >> d >> Q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1,x,y;j <= k[i];j++){
			cin >> x >> y;
			e[i].emplace_back(x,y);
			ct[x].push_back(i);
		}
	}
	while(Q--){
		int l,r;cin >> l >> r;
		cout << bfs(l,r) << '\n';
	}
}

/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
