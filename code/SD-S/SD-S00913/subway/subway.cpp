#include <bits/stdc++.h>
using namespace std;

const int N = 5e5, M = 2e6;
vector <pair<long long, long long>> v[M + 5];
long long w[N + 5], a[N + 5], t[N + 5], dis[M + 5], k[N + 5];
long long c, n, m, d, q;
set <pair<long long, long long>> s; 
void dj(long long st){
	s.clear();
	for(int i = 1;i <= 2 * m;i++) dis[i] = 2e18;
	for(int i = M;i >= M - n + 1;i--) dis[i] = 2e18;
	dis[st] = 0;
	s.insert(make_pair(0, st));
	while(s.empty() == 0){
		pair<long long, long long> ss = *s.begin();
		long long u = ss.second;
//		cout << "u: " << u << " " << dis[u] << endl;
		s.erase(*s.begin());
		for(int i = 0;i < v[u].size();i++){
			int sn = v[u][i].first;
			long long sw = v[u][i].second;
//			cout << "snsw: " << sn << " " << sw << " " << dis[u] << " " << dis[sn] << endl; 
			if(dis[sn] > dis[u] + sw){
//				cout << "YES" << endl;
				if(dis[sn] == 2e18){
//					cout << "YES" << endl;
					s.insert(make_pair(dis[u] + sw, sn));
				}
				else{
					s.erase(make_pair(dis[sn], sn));
					s.insert(make_pair(dis[u] + sw, sn));
				}
				dis[sn] = dis[u] + sw;
			}
		}
	}
	return;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
		v[i].push_back(make_pair(i + m, w[i]));
		v[i + m].push_back(make_pair(i, w[i]));
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[j] >> t[j];
			v[a[j] + m].push_back(make_pair(M - n + i, t[j]));
			v[M - n + i].push_back(make_pair(a[j] + m, t[j]));
		}
	}
	for(int i = 1;i <= q;i++){
		long long st, ed;
		cin >> st >> ed;
		dj(st);
		cout << dis[ed] << endl;
	}
	return 0;
}
