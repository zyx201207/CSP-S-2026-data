#include<bits/stdc++.h>
using namespace std;


long long n, m, c, d, q, k[500], t[505][505];
int w[500005], lenof[500005];
vector<pair<int, int> > ti[500005];

void input(){
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++){
		cin >> w[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> k[i];
		for(int j = 1; j <= k[i]; j++){
			int a, tmp; 
			cin >> a >> tmp;
			pair<int, int> tmp1;
			tmp1.first = i, tmp1.second = tmp;
			ti[a].push_back(tmp1);
			lenof[a]++;
		}
	}
	return ;
}

void init(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			t[i][j] = 1000000000000000005;
		}
	}
	for(int i = 1; i <= n; i++){
		t[i][i] = 0;
	}
	for(int z = 1; z <= m; z++){
		int len = lenof[z];
		for(int i = 0; i < len; i++){
			for(int j = i + 1; j < len; j++){
				int val = (long long)(ti[z][i].second) + ti[z][j].second;
				t[ti[z][i].first][ti[z][j].first] = min((long long)val, t[ti[z][i].first][ti[z][j].first]);
				t[ti[z][j].first][ti[z][i].first] = min((long long)val, t[ti[z][j].first][ti[z][i].first]);
			}
		}
	}
	return ;
}

void flid(){
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(i != j) t[i][j] = min(t[i][k] + t[k][j], t[i][j]);
			}
		}
	}
	return ;
}

void ans(){
	while(q--){
		int x, y;
		cin >> x >> y;
		int xlen = lenof[x], ylen = lenof[y];
		long long min_ = 1000000000000000005;
		for(int i = 0; i < xlen; i++){
			for(int j = 0; j < ylen; j++){
				long long tmp = t[ti[x][i].first][ti[y][j].first];
				tmp += ti[x][i].second + ti[y][j].second;
				min_ = min(min_, tmp);
			}
		}
		cout << min_ + w[x] + w[y] << '\n';
	}
	return ;
}

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	input();
	init();
	flid();
	ans();
	return 0;
}