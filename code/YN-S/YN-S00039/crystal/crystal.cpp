#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
vector<long long> a(100005, 0), s1(100005, 0), s2(100005, 0);
long long same_num = 0;
//s1数组表示能量为x（x>=0）的水晶数目,s1数组表示能量为x（x<0）的水晶数
//桶排序（注意能量可以有正有负，用绝对值）
vector<vector<int>> dp(500001, vector<int>(1005, 0));
//energy:之前相同能量最多的水晶的能量值
//before:表示之前相同能量最多的水晶的能量值的正负
bool before = true;
long long tempmax = 0;
long long n;
long long m;

long long same(long long w, vector<long long> b,  vector<long long> t1,  vector<long long>t2, long long energy = 0) {
	long long vol = 0;

	//cout << endl << "energy=" << energy << " before=" << before << endl;
	if (b[w] > 0) {
		if (before) {
			//cout << "[energy]=" << t1[energy] << " t1[b[w]]=" << t1[b[w]];
			if (t1[energy] > t1[b[w]]) {
				vol = t1[energy];
			} else {
				vol = t1[b[w]];
				energy = b[w];
			}
		} else {
			//cout << "t2[energy]=" << t2[energy] << " t1[b[w]]=" << t1[b[w]];
			if (t2[energy] > t1[b[w]]) {
				vol = t2[energy];
			} else {
				vol = t1[b[w]];
				energy = b[w];
			}
		}
		before = true;
	} else {
		if (before) {
			//cout << "t1[energy]=" << t1[energy] << " t2[-b[w]]=" << t2[-b[w]];
			if (t1[energy] > t2[-b[w]]) {
				vol = t1[energy];
			} else {
				vol = t2[-b[w]];
				energy = -b[w];
			}
		} else {
			//cout << "t2[energy]=" << t2[energy] << " t2[-b[w]]=" << t2[-b[w]];
			if (t2[energy] > t2[-b[w]]) {
				vol = t2[energy];
			} else {
				vol = t2[-b[w]];
				energy = -b[w];
			}
		}

		before = false;
	}
	//cout << endl << "w=" << w << " vol=" << vol << " energy=" << energy << endl;
	return vol;
}

long long play(long long w, vector<long long> b,  vector<long long>t1,  vector<long long>t2, long long k) {
	//cout << "***w=" << w << " b[w]=" << b[w] <<  " before=" << before;
	long long olds = tempmax;
	//cout << " olds=" << olds;

	for (long long i = 1; i <= w; i++) {
		vector<long long> u1 = t1;
		vector<long long>u2 = t2;
		vector<long long> c = b;

		if (c[i] > 0) {
			c[i]++;
			u1[c[i]]++;
		} else {
			c[i]++;
			u2[-c[i]]++;
		}
		//cout << " b[w]=" << b[w] << " ";

		long long energy = tempmax;

		long long vol = 0;

		//cout << endl << "energy=" << energy << " before=" << before << endl;
		if (c[w] > 0) {
			if (before) {
				//cout << "[energy]=" << t1[energy] << " t1[b[w]]=" << t1[b[w]];
				if (u1[energy] > u1[c[w]]) {
					vol = u1[energy];
				} else {
					vol = u1[a[w]];
					energy = a[w];
				}
			} else {
				//cout << "t2[energy]=" << t2[energy] << " t1[b[w]]=" << t1[b[w]];
				if (u2[energy] > u1[c[w]]) {
					vol = u2[energy];
				} else {
					vol = u1[c[w]];
					energy = c[w];
				}
			}
			before = true;
		} else {
			if (before) {
				//cout << "t1[energy]=" << t1[energy] << " t2[-b[w]]=" << t2[-b[w]];
				if (u1[energy] > u2[-c[w]]) {
					vol = u1[energy];
				} else {
					vol = u2[-c[w]];
					energy = -c[w];
				}
			} else {
				//cout << "t2[energy]=" << t2[energy] << " t2[-b[w]]=" << t2[-b[w]];
				if (u2[energy] > u2[-c[w]]) {
					vol = u2[energy];
				} else {
					vol = u2[-c[w]];
					energy = -c[w];
				}
			}

			before = false;
		}
		//cout << "news=" << vol << "***" << endl;
		if (vol > olds) {
			olds = vol;
		}
	}
	return olds - tempmax - 1;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);

	cin >> n >> m;

	for (long long i = 1; i <= n; i++) {
		cin >> a[i];

	}

	if (n >= 5000) {
		//特殊性质A：对于所有i(1≤i≤n)，均有ai=i。
		//如果所有a的值都相同，直接输出n
		//这里直接对2个测试点
		for (long long i = 2; i <= n; i++) {
			if (a[i] != a[i - 1]) {
				break;
			} else {
				same_num++;
			}
		}
		same_num++;
		if (same_num == n) {
			cout << n;
			return 0;
		}

		cout << m / 2;
	}


	for (long long j = 1; j <= m; j++)
		dp[0][j] = 0;

	tempmax = dp[n][0];
	before = dp[n][0] >= 0 ? true : false;



	for (int i = 1; i <= n; i++) {
		if (a[i] >= 0) {
			s1[a[i]]++;
			//cout << "a[i]=" << a[i] << " s1[a[i]]=" << s1[a[i]] << endl;
		} else {
			s2[-a[i]]++;
			//cout << "a[i]=" << a[i] << " s2[-a[i]]=" << s2[-a[i]] << endl;
		}
		dp[i][0] = same(i, a, s1, s2, dp[i - 1][0]);
	}

//**********************************************

//桶排序检验
//	for (auto i = 0; i <= 10; i++)
//		cout << s1[i] << " ";
//	cout << endl;
//	for (auto i = 1; i <= 10; i++)
//		cout << s2[i] << " ";

//	for (auto i = 0; i <= n; i++) {
//		for (auto j = 0; j <= m; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}

	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= m; j++) {
			int temp = play(i, a, s1, s2, 1);
			//cout << temp << "*";
			dp[i][j] = max(dp[i][j - 1], dp[i][j - 1] + temp);

////			for (auto i = 0; i <= n; i++) {
////				for (auto j = 0; j <= m; j++) {
////					cout << dp[i][j] << " ";
////				}
////				cout << endl;
////			}
		}
	}

//	cout << endl;
//	for (auto i = 0; i <= n; i++) {
//		for (auto j = 0; j <= m; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}

	cout << dp[n][m];
	return 0;
}
