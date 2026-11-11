#include<bits/stdc++.h>
using namespace std;
int mmap[20001][20001];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int wn[20000];
	// 地铁站入口路程 
	for (int t = 1;t <= m;t++) {
		cin >> c;
		wn[t] = c;
	}
	// 读取线路
	for (int t = 0;t < n;t++) {
		int k; // 经过的站点个数 
		cin >> k;
		int start,co;
		cin >> start >> co; // 先读一组数据 
//		cout << "第" << t << "条线路起始于" << start << "，本站路程为" << co << endl; 
		for(int t1 = 1;t1 < k;t1++) {
			int station,cost;
			cin >> station >> cost;
//			cout << "第" << t << "条线的站点" << station << "，本站路程为" << cost << endl;
			// 更新图信息
			mmap[station][start] = cost + co; // 从新站点到原站点(站台) 
			mmap[start][station] = cost + co;
		} 
	} 
//	for(int i = 1;i <= m;i++) {
//		for(int j = 1;j <= m;j++) {
//			cout << mmap[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << "\n\n";
	for (int i = 1;i <= m;i++) {
		mmap[i][i] = 9999999; 
		for(int j = i + 1;j <= m;j++) {
			for(int k = 1;k <= m;k++) {
				if(mmap[i][j] == 0) {
					mmap[i][j] = 9999999;
					mmap[j][i] = 9999999;
				}
				if(mmap[i][k] == 0) {
					mmap[i][k] = 9999999;
					mmap[k][i] = 9999999;
				}
				if(mmap[k][j] == 0) {
					mmap[k][j] = 9999999;
					mmap[j][k] = 9999999;
				}
				// 判断
				if (mmap[i][j] > mmap[i][k] + mmap[k][j]) {
//					cout << "从" << i << "到" << j << "的线路在绕道" << k << "的情况下可以减少到" << mmap[i][k] + mmap[k][j] << endl;
					mmap[i][j] = mmap[i][k] + mmap[k][j];
					mmap[j][i] = mmap[i][j];
				} 
			}
		}
	}
	vector<long> result;
	// 最终结果
	for(int t = 0;t < q;t++) {
		int st,en;
		cin >> st >> en;
//		cout << "对于从" << st << "到" << en << "的线路车上共" << mmap[st][en] << "消耗，进出站合起来共" << wn[st] + wn[en] << endl;
		result.push_back(wn[st] + wn[en] + mmap[st][en]);
	} 
	for(int t = 0;t < q;t++) {
		cout << result[t] << endl;
	}
//	cout << "\n\n";
//	for(int i = 1;i <= m;i++) {
//		for(int j = 1;j <= m;j++) {
//			cout << mmap[i][j] << " ";
//		}
//		cout << endl;
//	}
	return 0;
} 
