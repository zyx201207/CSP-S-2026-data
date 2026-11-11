#include<bits/stdc++.h>
using namespace std;

//inline long long abs(long long n) {
//	return n < 0?(-n):n;
//}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	int n;
	long long m;
	cin >> n >> m;
	if (n == 1) {
		cout << 1;
		return 0;
	} else if (n == 2) {
		int a,b;
		cin >> a >> b;
		if (abs(a - b) < m) {
			cout << 2;
		} else {
			cout << 1;
		}
		return 0;
	}
	vector<long long> an;
	long long input;
	long long sum;
	bool is_a = true; // 是否为A特殊性质 
	cin >> input;
	an.push_back(input);
	for (int t = 1; t < n;t++) {
		cin >> input;
		if (is_a) {
			is_a = (input - an[t - 1]) == 1;
		}
		an.push_back(input);
		sum += input;
	}
	if (is_a) {
		// A特殊性质 
//		cout << "Hello, A" << endl;
		int kksk = 1;
		n--;
		input = an[n];
		while(m > 0) {
			if(input - an[--n] <= m) {
				m -= input - an[n];
				kksk++;
			} else {
				break;
			}
		}
		cout << kksk;
		return 0;
	}
	sort(an.begin(), an.end());
//	int start_most = 0;
//	int most_count = 1;
//	long long now_most = an[start_most];
//	int k = 1;
//	while(an[k] == now_most) {
//		most_count
//	}
//	for (int t = 0; t < n;t++) {
////		cout << an[t] << " ";
//	}
	int medium = (n + 1) / 2; // 计算中点
	long long avg = sum / (n + 1); // 计算平均数
	long long min_abs = abs(an[medium] - avg); // 当前与avg的差的绝对值 
	// 向前比较
	if (abs(an[medium - 1] - avg) < min_abs) {
		// 前面的比较小
		if (abs(an[medium + 1] - avg) < abs(an[medium - 1] - avg)) {
			// 后面的更小
			medium++; 
		} else {
			medium--;
		}
	} else if(abs(an[medium + 1] - avg) < min_abs) {
		// 后面的
		medium++; 
	}
//	cout << "选择的下标: " << medium << "，此时的值: " << an[medium] << endl;
	long long now = an[medium];
	sum = 1;
	int start_index = medium;
	// 从这一点开始向前
	while(m > 0) {
		if(medium < 0) {
//			cout << "kksk:" << m << endl;
			while(m > 0) {
				start_index++;
				if((an[start_index] - an[start_index - 1]) * sum <= m) {
//					cout << "当前排到了第" << start_index << "个下标，此位置数字为" << an[start_index] << "，此时已经累计了" << sum << "个，剩余可支配点数为" << m << "本轮差值为" << an[start_index] - an[start_index - 1] << endl;
					m -= ((an[start_index] - an[start_index - 1]) * sum);
					sum++;
				} else {
//					cout << "目前下标: " << start_index << endl;
					cout << sum;
					return 0;
				}
			}
			break;
		}
		if (now - an[--medium] <= m) {
			if (medium < 0) {
				continue;
			}
//			cout << "对于下标" << medium << "本轮需要点数：" << now - an[medium];
			m = m - (now - an[medium]);
//			cout << "，余下" << m << "点数" << endl;
			sum++;
		} else {
			break;
		}
	} 
	cout << sum;
	return 0;
}
