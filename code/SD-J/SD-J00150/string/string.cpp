#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, pre[N];
struct node {
	long long a;
	char c;
};
node s1[N], s2[N];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> s1[i].a;
		cin >> s1[i].c;
	}
	int idx = 0;
	for(int i = 1; i <= n; i++) {
		if(s1[i].c == s1[i - 1].c) s2[idx].a += s1[i].a;
		else s2[++idx].a = s1[i].a, s2[idx].c = s1[i].c;
//		cout << s2[idx].a << "\n";
	}
	if(idx == 1) {
		cout << 0 << "\n";
		return 0; 
	}
	long long len = 0;
	for(int i = 1; i <= idx; i++) len += s2[i].a;
//	cout <<  len << "\n";
	if(len <= 1e8) {
		string s;
		for(int i = 1; i <= idx; i++) {
			for(int j = 1; j <= s2[i].a; j++) s += s2[i].c; 
		}
		int siz = s.size(), cnt = 0;
//		cout << s << "\n";
		for(int i = 0; i < siz; i++) {
			if(s[i] != s[siz - i - 1]) {
				cnt++;
			}
		}
		cout << cnt / 2 << "\n";
	}
	else {
		long long cnt = 0, mid = (len + 1) / 2, res = 0, pos = 0;
		bool flag = 0;
		for(int i = 1; i <= idx; i++) {
			res += s2[i].a;
			if(res == mid) {
				flag = 1;
				break;
			}
			if(res > mid) {
				pos = i;
				break;
			}
		}
		if(!flag) {
			idx++;
			for(int i = idx - 1; i > pos; i--) {
				s2[i + 1] = s2[i];
			}
			s2[pos].a -= (res - mid);
			s2[pos + 1].a = res - mid;
			s2[pos + 1].c = s2[pos].c; 
		}
//		cout << idx << "\n";
//		for(int i = idx; i >= 1; i--) pre[i] = pre[i + 1] + s2[i].a;
		long long nxt = n, lst = 0;
		bool f = 0;
		char c;
		if(pos == 0) pos = idx / 2;
		for(int i = 1; i <= pos; i++) {
			long long ans = lst, sam = 0;
			for(int j = nxt; j >= i; j--) {
				ans += s2[j].a;
				if(ans >= s2[i].a) {
					if(s2[i].c == s2[j].c) sam += s2[j].a - (ans - s2[i].a);
					nxt = j - 1;
					break;
				}
				if(s2[i].c == s2[j].c) sam += s2[j].a;
			}
			cnt += s2[i].a - sam;
			if(s2[i].c != c && f) cnt += lst;
			if(ans >= s2[i].a) {
				lst = ans - s2[i].a;
				c = s2[nxt + 1].c;
				f = 1;
			}
			else lst = 0, f = 0;
		}
		cout << cnt << "\n";
	}
	return 0;
}
