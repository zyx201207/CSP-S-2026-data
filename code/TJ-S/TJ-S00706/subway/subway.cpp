#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	vector <int> a;
	vector <int> zh;
	vector <int> sh;
	vector <int> start;
	vector <int> end;
	int c, n, m, d, q;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++){
		int x;
		cin >> x;
		a.push_back(x);
	}
	for (int i = 1;i <= n;i++){
		int x;
		cin >> x;
		for (int i = 1;i <= x * 2;i++){
			if (i % 2 == 1){
				int y;
				cin >> y;
				zh.push_back(y);
			}
			else{
				int y;
				cin >> y;
				sh.push_back(y);
			}
		}
	}
	for (int i = 1;i <= q;i++){
		int p, h;
		cin >> p >> h;
		start.push_back(p);
		end.push_back(h);
	}
	int huanq = 0, huanz = 0;
	for (int i = 1;i <= zh.size() / 2;i++){
		for (int j = zh.size() / 2;j <= zh.size();i++){
			if (zh[i] == zh[j]){
				huanq = i;
				huanz = j;
			}
		}
	}
	int ans1 = a[start[0] - 1] + a[end[0] - 1];
	int ans2 = a[start[1] - 1] + a[end[1] - 1];
	bool ok = false;
	int pos1 = start[0];
	int pos2 = start[1];
	int posz = 0;
	if (n == 2){
		for (int i = 1;i <= zh.size() / 2;i++){
			if (i == end[0]){
				ok = true;
				pos1 = i;
			}
		}
		for (int i = 1;i <= zh.size();i++){
			if (i == end[0]){
				posz = i;
			}
		}
		if(ok){
			for (int i = 0;i < pos1;i++){
				ans1 += sh[i];
			}
		}
		else{
			for (int i = 0;i < huanq;i++){
				ans1 += sh[i];
			}
			for (int i = huanz;i <= posz;i++){
				ans1 += sh[i];
			}
		}
		
		for (int i = 1;i <= zh.size() / 2;i++){
			if (i == end[1]){
				ok = true;
				pos2 = i;
			}
		}
		for (int i = 1;i <= zh.size();i++){
			if (i == end[1]){
				posz = i;
			}
		}
		if(ok){
			for (int i = 0;i < pos2;i++){
				ans2 += sh[i];
			}
		}
		else{
			for (int i = 0;i < huanq;i++){
				ans2 += sh[i];
			}
			for (int i = huanz;i <= posz;i++){
				ans2 += sh[i];
			}
		}
	}
	cout << ans1 << endl << ans2;
	return 0;
}
