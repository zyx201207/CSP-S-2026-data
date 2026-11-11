#include <bits/stdc++.h>
using namespace std;

int n, a, s, len;
char c;
deque<char> d;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    while (n--) {
        cin >> a >> c;
        while (a--)
           d.push_back(c);
    }
    while (!d.empty()) {
        s += d.front() != d.back();
        d.pop_front();
        if (d.empty()) break;
        d.pop_back();
    }
    cout << s;
    return 0;
}
