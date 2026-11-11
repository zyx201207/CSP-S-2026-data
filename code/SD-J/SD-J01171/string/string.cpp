#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> cs; // 个数
vector<char> cq; 
char C[200005];
long long fzs[200005];
char fzc[200055];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin >> n;
	long long ix, as = 0, cnt = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> ix >> C[i];
		if(C[i] == C[i - 1]) {
			if(cnt - 1 >= 0)
			cs[cnt - 1] += ix;
//			cout << cs[cnt - 1] << ' ';
		}
		else {
			cs.push_back(ix);
			cq.push_back(C[i]);
			cnt++;
		}
	}
	long long len = cs.size();
//	cout << len << '\n';
	for (long long i = 0; i < len; i++) {
		fzs[i] = cs[len - i - 1]; // 数量 
		fzc[i] = cq[len - i - 1];
	}
//	cout << fzs[0] << '\n';
//	for (int i = 0; i < len; i++) {
//		cout << fzs[i] << ' ';
//	}
//	cout << '\n';
	int i = 0, j = 0;
	for (;i < cnt && j < cnt;) {
		if(fzs[i] == cs[j] && fzc[i] == cq[j]) {
			i++;
			j++;
		}
		else if(fzc[i] != cq[j]) { // 不一致的字符 
			if(fzs[i] > cs[j]) {
				fzs[i] -= cs[j];
				as += cs[j];
//				cout << cs[j]<< '\n';
				j++;
			}
			else if(fzs[i] == cs[j]){
				as += fzs[i];
//				cout << fzs[i] << '\n';
				i++, j++;
			}
			else {
				cs[j] -= fzs[i];
				as += fzs[i];
				i++;
//				cout << fzs[i] << '\n';
			}
		}
		else {
			if(fzs[i] > cs[j]) {
				fzs[i] -= cs[j];
//				cout << cs[j]<< '\n';
				j++;
			}
			else if(fzs[i] < cs[j]){
				cs[j] -= fzs[i];
				i++;
			}
			else {
				i++, j++;
			}
		}
	}
	cout << as / 2;
	return 0;
}
//Trick||Treat!
/*两张车票对应的座位是否在同一节车厢；
? 两张车票对应的座位是否在同一节车厢的同一排；
? 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
? 两张车票对应的座位是否相邻。*/
