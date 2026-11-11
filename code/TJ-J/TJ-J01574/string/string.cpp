#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
char ch[100005];
long long cnt = 0;

int main() {

	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cin >> ch[i];
	}
	if(ch[0]!=ch[n-1]){
		cout<<min(a[n-1],a[0]);
		return 0;
	}
	cout << "0";
	return 0;
}

