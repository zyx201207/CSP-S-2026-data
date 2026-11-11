//I have 90min
//17:40 get 40pts
#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 1e6 + 5;
constexpr int INF = 1e18;
int a[MAXN];
int n, d;
int sum[MAXN], Min[MAXN];
void work1() {
    cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int result = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sum[j] = 0;
            Min[j] = INF;
        }
        sum[i] = 1;
        Min[i] = 0;
        for(int j = i + 1; j <= n; j++) {
            //kan kan ke yi cong na li hui lai
            int left = i, right = j - 1;
            int ans = -1;
            while(left <= right) {
                int mid = (left + right) >> 1;
                if(llabs(a[j] - a[mid]) <= d) {
                    right = mid - 1;
                    ans = mid;
                } else {
                    left = mid + 1;
                }
            }
            if(ans == -1) {
                break;
            }
            left = ans, right = j - 1;
            int ans2 = left;
            while(left <= right) {
                int mid = (left + right) >> 1;
                if(Min[mid] == Min[ans]) {
                    left = mid + 1;
                    ans2 = mid;
                } else {
                    right = mid - 1;
                }
            }
            Min[j] = Min[ans] + 1;
            for(int k = ans; k <= ans2; k++) {
                sum[j] += sum[k];
            }
            if(!sum[j]) break;
        }
        for(int j = 1; j <= n; j++) {
            result += (sum[j] == 2);
            //cout << sum[j] << ' ' << Min[j] << endl;
        } //cout << endl;
    }
    cout << result << endl;
}
void work2() {
    cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << 0 << endl;
        return ;
    }
    int could = d / (a[2] - a[1]);
    int result = 0;
    for(int i = 1; i <= n; i++) {
        int sy = n - i;
        //kan kan you duo shao zu
        int sum1 = sy / (could + 1);
        sy -= sum1 * (could + 1);
        result += sum1 * could;
        result += sy;
    }
    cout << result << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while(T--) {
        work1();
    }
    return 0;
}

/*
10 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
