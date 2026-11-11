/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e4+14, M = 514;
int c, n, m, d, q, res=INT_MAX;
int w[N]; //µØÌú¿Úµ½Õ¾Ìü 
int k[M];
vector<pair<int, int> > trans[M];
struct xhy{
	vector<int> pos;
	int tm[M];
}sta[N];
bool vis[M];
void dfs(int now, int tar, int ans){
//	cout << res << '\n';
	bool flag = 0;
//	cout << now;
	for(int i = 0; i < sta[tar].pos.size(); i ++){
		if(now==sta[tar].pos[i]){
			flag = 1;
//			cout << 1;
			break;
		}
	}
	if(flag){
		ans += sta[tar].tm[now];
//		cout << ans << '\n';
		res = min(res, ans);
//		cout << res << '\n';
		return;
	}
	for(int i = 0; i < trans[now].size(); i ++){
		int nnow = trans[now][i].first;
		int tra = trans[now][i].second;
		if(vis[nnow]) continue;
		vis[nnow] = 1;
		ans += (sta[tra].tm[now]+sta[tra].tm[nnow]);
		dfs(nnow, tar, ans);
		vis[nnow] = 0;
	}
	return;
}
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++){
		int k;
		cin >> k;
		for(int j = 1; j <= k; j ++){
			int x, y;
			cin >> x >> y;
			sta[x].pos.push_back(i);
			sta[x].tm[i]=y;
		}
	}
	for(int i = 1; i <= m; i ++){
		if(sta[i].pos.size() > 1){
			for(int j = 0; j < sta[i].pos.size(); j ++){
				int tmp = sta[i].pos[j];
				for(int l = 0; l < sta[i].pos.size(); l ++){
					if(sta[i].pos[l] == tmp) continue;
					trans[tmp].push_back(make_pair(sta[i].pos[l], i));
				}
			}
		}
	}
	while(q --){
		res = INT_MAX;
		memset(vis, 0, sizeof vis);
		int x, y;
		cin >> x >> y;
		bool flag = 0;
		for(int i = 1; i <= n; i ++){
			if(sta[x].tm[i] && sta[y].tm[i]){
				flag = 1;
				cout << sta[x].tm[i]+sta[y].tm[i]+w[x]+w[y] << '\n';
				break;
			}
		}
		if(flag) continue;
		for(int i = 0; i < sta[x].pos.size(); i ++){
			int st = sta[x].pos[i];
//			cout << st << '\n';
			vis[st] = 1;
			dfs(st, y, sta[x].tm[st]+w[st]+w[y]);
//			cout << res << '\n';
		}
		cout << res << '\n';
	}
	return 0;
}
