#include<bits/stdc++.h>

using namespace std;

long long n,ch[28],maxch,z,ans;
pair<long long,char> a[200009],b[200009];
string s1,s2;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	int n1 = n;
	for (int i = 1; i <= n1; i++) {
		cin >> a[i].first >> a[i].second;
		ch[a[i].second-'a'] += a[i].first;
		z += a[i].first;
		if (a[i].second == a[i-1].second) {
			a[i-1].first += a[i].first;
			n1--,i--;
		}
		maxch = max(maxch,ch[a[i].second-'a']);
	}
	bool flag = true;
	for (int i = 1; i <= n1; i++) {
		b[i].first = a[n1-i+1].first;
		b[i].second = a[n1-i+1].second;
		if (a[i].first != b[i].first || a[i].second != b[i].second) {
			flag = false;
		}
	}
	if (flag) {
		cout << 0;
		return 0;
	}
	if (n1 == 1) {
		cout << 0;
	} else if (n1 == 2) {
		cout << min(a[1].first,a[2].first);
	} else {
//		for (int i = 0;i <= 26;i++){
//			if (ch[i] > z/2){
//				cout << z-ch[i];
//				return 0;
//			}
//		}
		
		if (maxch <= 5009 && n1 <= 200009) {
			for (int i = 1; i <= n1; i++) {
				for (int j = 1; j <=a[i].first; j++) {
					s1 += a[i].second;
				}
			}
//			s2 = s1;
//			s2.reserve(s2.size()-1);
			for (int i = 1; i <= n1; i++) {
				for (int j = 1; j <=b[i].first; j++) {
					s2 += b[i].second;
				}
			}
//			cout << s1 << ' ' << s2;
			for (int i = 0; i < s1.size(); i++) {
				if (s1[i] != s2[i]) {
					s2[i] = s1[i];
					s1[s2.size()-i-1] = s1[i];
					ans++;
				}
			}
			cout << ans;
		} else {
			cout << 0;
		}
	}
	return 0;
}
