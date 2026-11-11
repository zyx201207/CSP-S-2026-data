#include <bits/stdc++.h>
using namespace std;

int n;
long long M;
int main () {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<long long> a;
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> M;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		cnt += t;
		a.push_back(t);
	}

	sort(a.begin(), a.end());
	// 找均值
	float t = cnt / n, dt = 0, lastDt = 0;
	int index;
	for (int i = 0; i < (int)a.size(); i++) {
		int c = a[i];
		(c > t) ? dt = c - t : dt = t - c;
		if (lastDt > dt) {
			index = i - 1;
			break;
		}
		lastDt = dt;
	}

	//从均值出发向两边贪心
	int left = index - 1, right = index + 1, cA = a[index], numOfSame = 1;
	while (M) {
		//求两边代价 cL, cR
		int cL, cR;
		if (left >= 0) {
			cL = cA - a[left];
		}
		if (right <= (int)a.size()) {
			cR = numOfSame * (a[right] - cA);
		}

		//比较代价，低者操作
		if (max(cL, cR) == cL && M >= cL) {
			//a.[left] = cA;
			numOfSame ++;
			M -= cL;
			left --;
		} else if (M > cR) {
			numOfSame++;
			M -= cR;
			cA = a[right];
			right ++;
		} else
			break;

		/*cout << "cA: " << cA << endl << "left/cL: " << left << '/' << cL << "; " << "right/cR: " << right << '/' << cR <<
		     "\n\n";
		*/
	}

	cout << numOfSame;
	return 0;
}