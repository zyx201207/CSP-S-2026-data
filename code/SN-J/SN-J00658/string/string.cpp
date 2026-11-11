//白屹桐  西安辅轮中学  SN-J00658
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;
const int N = 2e5 + 10;
int n, m, x, y, cnt;
ll len, sum;
int a[N];
char c[N];
string s = " ";

int main(){

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i] >> c[i];
		len += a[i];
	}
	int j = 1;
	sum = a[1];
	for (int i = 1; i <= len; i++){
		if (i > sum){
			j ++;
			sum += a[j];
		}
		s += c[j];
	}
	for (int i = 1; i <= len / 2; i++){
		if (s[i] != s[len - i + 1]) cnt ++;
	}
	cout << cnt;
	
	return 0;
}

