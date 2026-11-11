#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,dep[2000001],bb[2000001],fi[2000001],la[2000001],da[2000001],flag[2000001];
int x[2000001];
queue<int> q;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--){
		cin >> n >> d;
		for (int i = 1;i <= n;i++){
			cin >> x[i];
			dep[i] = 0;
			da[i] = 0;
			flag[i] = 0;
		}
		dep[1] = 1;
		while (!q.empty()){
			q.pop();
		}
		q.push(1);
		int dd = 1;
		while (!q.empty()){
			int cur = q.front();
			q.pop();
			while (dd + 1 <= n && x[dd + 1] - x[cur] <= d){
				dd++;
				dep[dd] = dep[cur] + 1;
				q.push(dd);
			}
			bb[cur] = dd;
		}
		for (int i = n;i >= 1;i--){
			if (bb[i] == 0){
				bb[i] = dd;
			}
		}
		for (int i = 1;i <= n;i++){
			if (!fi[dep[i]]){
				fi[dep[i]] = i;
			}
		}
		for (int i = n;i >= 1;i--){
			if (!la[dep[i]]){
				la[dep[i]] = i;
			}
		}
		int ans = 0,dee = 2,kk = 0,d1d = 0,sum = 0;
		for (int i = 1;i <= n;i++){
			if (dep[i] == dep[n]){
				break;
			}
			sum -= da[dep[i]];
			d1d = max(d1d,la[dep[i]]);
			for (int j = max(d1d + 1,fi[dep[i] + 1]);j <= bb[i];j++){
				d1d++;
				if (flag[d1d] == 1){
					sum--;
					da[dep[i] + 1]--;
				}
				flag[d1d] = 0;
			}
			while (kk + 1 <= n && dep[kk + 1] <= i){
				kk++;
				flag[kk] = 0;
			}
			da[dep[i]] = 0;
			while (dee + 1 <= dep[n]){
				int aaa = dee + 1;
				if (la[dee] - fi[dee] == 0){
					if (flag[la[dee]] == 1){
						for (int j = fi[aaa];j <= la[aaa];j++){
							flag[j] = 1;
							da[aaa]++;
							sum++;
						}
					}
					dee = aaa + 1;
				}else if (la[dee] - fi[dee] == 1){
					if (flag[la[dee]] > 1){
						break;
					}if (flag[la[dee]] == 1 || flag[fi[dee]]){
						if (bb[fi[dee]] == bb[la[dee]]){
							break;
						}
						for (int j = fi[aaa];j <= bb[fi[dee]];j++){
							flag[j] = 2;
						}
						for (int j = bb[fi[dee]] + 1;j <= la[aaa];j++){
							flag[j] = flag[la[dee]];
							if (flag[j] == 1){
								da[aaa]++;
								sum++;
							}
						}
					}else{
						for (int j = fi[aaa];j <= bb[fi[dee]];j++){
							flag[j] = 1;
							da[aaa]++;
							sum++;
						}
						for (int j = bb[fi[dee]] + 1;j <= la[aaa];j++){
							flag[j] = 0;
						}
					}
					dee = aaa + 1;
				}else{
					if (flag[la[dee]] > 1){
						break;
					}else if (flag[la[dee] - 1] || flag[la[dee]]){
						if (bb[la[dee] - 1] == bb[la[dee]]){
							break;
						}
						for (int j = bb[la[dee] - 2] + 1;j <= bb[la[dee] - 1];j++){
							flag[j] = 2;
						}
						for (int j = bb[la[dee] - 1] + 1;j <= la[aaa];j++){
							flag[j] = flag[la[dee]];
							if (flag[j] == 1){
								da[aaa]++;
								sum++;
							}
						}
					}else{
						for (int j = bb[la[dee] - 2] + 1;j <= bb[la[dee] - 1];j++){
							flag[j] = 1;
							da[aaa]++;
							sum++;
						}
						for (int j = bb[la[dee] - 1] + 1;j <= la[aaa];j++){
							flag[j] = 0;
						}
					}
					dee = aaa + 1;
				}
			}
			cout << i << " " << sum << "\n";
			ans += sum;
		}
		cout << ans << "\n";
	}
	return 0;
} 
