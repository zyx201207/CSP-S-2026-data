#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
unsigned long long n, sum, ans;

struct str {
    long long start = 0, finish = 0, number;
    char alpha;
} arr[N];

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i].number >> arr[i].alpha;
        arr[i].start = arr[i - 1].finish + 1;
        arr[i].finish = arr[i].start + arr[i].number;
        sum += arr[i].number;
    }
    unsigned long long l = 1, r = arr[n].finish, posl = 1, posr = n;
    while (l <= (sum + 1) / 2 && r > (sum + 1) / 2) {
        if (arr[posl].alpha == arr[posr].alpha) {
            if (arr[posl].number < arr[posr].number) {
                arr[posr].number -= arr[posl].number;
                r -= arr[posl].number;
                l += arr[posl].number;
                posl++;
            } else if (arr[posl].number == arr[posr].number) {
                r -= arr[posl].number;
                l += arr[posl].number;
                posl++;
                posr--;
            } else {
                arr[posl].number -= arr[posr].number;
                r -= arr[posr].number;
                l += arr[posr].number;
                posr--;
            }
        } else {
            if (arr[posl].number < arr[posr].number) {
                ans += arr[posl].number;
                arr[posr].number -= arr[posl].number;
                r -= arr[posl].number;
                l += arr[posl].number;
                posl++;
            } else if (arr[posl].number == arr[posr].number) {
                ans += arr[posl].number;
                r -= arr[posl].number;
                l += arr[posl].number;
                posl++;
                posr--;
            } else {
                ans += arr[posr].number;
                arr[posl].number -= arr[posr].number;
                r -= arr[posr].number;
                l += arr[posr].number;
                posr--;
            }
        }
    }
    cout << ans;
    return 0;
}
