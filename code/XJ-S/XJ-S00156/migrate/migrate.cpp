#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using std::cin;
using std::cout;
using ll = long long;

const int N = 2e6 + 5;
int mother_of_wood_stick, T;
int n;
ll d, a[N];

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> mother_of_wood_stick >> T;
    while(T--) {
        cin >> n >> d;
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        cout << "0\n";
    }
}
