#include "bits/stdc++.h"\
#incldue<string>
using namespace std;

bool hw(string a) {
	for (int i = 0; i < a.size(); i ++) {
		if (a[i] != a.size() - 1 - i)
			return 0;
	}
	return 1;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin >> n;
	string b;
	for (int i = 0; i < n; i ++) {
		int a;
		cin >> a;
		string a1;
		cin >> a1;
		for (int i = 0; i < a; i ++)
			b += a1;
	}
	if (hw(b)) {
		cout << 0;
	}
	sort(b,b+b.size(),[](string a,string b)
	{
		return a> b;
	});
	return 0;
}