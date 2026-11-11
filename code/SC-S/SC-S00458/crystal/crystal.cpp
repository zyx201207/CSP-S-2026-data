#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, m;
long long a[N];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	stable_sort(a + 1, a + n + 1);
	int ans = 1;
	for(int mid = 1; mid <= n; mid++) {
		int sum = 1, cost = 0;
		for(int i = 1; i < mid; i++) {
			if(cost + a[mid - i] > m) {
				cout << ans << endl;
				return 0;
			}
			cost += a[mid] - a[mid - i];
			sum++;
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
/*

#include<bits/stdc++.h>
#include<windows.h>
using namespace std;int main() {srand(time(0));cout << "Guess the Number" << endl;cout << "What's the area?   ";int AR;cin >> AR;system("cls");int n = rand() % AR + 1;int l = 1, r = AR;int wintimes = 0;begin:while(1) {cout << "Guess the Number" << endl;if(wintimes == 0) cout << "You never win. :(" << endl;else if(wintimes == 1) cout << "You winned 1 time." << endl;else cout << "You winned " << wintimes << " times." << endl;cout << l << '~' << r << ':' << endl;int x;cin >> x;if(x == -114514) {cout << n << endl;Sleep(500);system("cls");continue;}system("cls");if(x < l || x > r) {cout << l << '~' << r << ':' << endl;cout << "!!!!" << endl;Sleep(500);system("cls");continue;}Sleep(500);cout << '.';Sleep(500);cout << '.';Sleep(500);cout << '.';Sleep(500);system("cls");if(x > n) {cout << "to big" << endl;r = x - 1;} else if(x < n) {cout << "to small" << endl;l = x + 1;} else {cout << "!!CORRECT!!" << endl;Sleep(1000);system("cls");cout << "Press a to play again" << endl;char ch; cin >> ch; if(ch == 'a') { system("cls"); wintimes++; goto begin; } else return 0; } Sleep(1000);system("cls");}return 0;}


*/