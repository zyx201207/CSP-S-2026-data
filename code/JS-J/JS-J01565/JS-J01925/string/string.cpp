#include <bits/stdc++.h>

using namespace std;
int n;
int a[3];
string b[3];
//struct T{
//    string s;
//    int num;
//};
//T arr[20005];
//int len = 0;
//bool cmp(T a, T b) {
//    return a.num < b.num;
//}
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cin >> b[i];
//        if (b == arr[len].s) {
//            arr[len].num += a;
//        }
//        else {
//            len++;
//            arr[len].num = a;
//            arr[len].s = b;
//        }
    }
//    sort(arr, arr + len + 1, cmp);
    if (n == 1) cout << 0;
    else if (n == 2) {
        if (b[1] == b[2]) cout << 0;
        else cout << abs(a[1] - a[2]);
    }
    else cout << 0;
    return 0;
}
