#include <iostream>
#include <vector>
using namespace std;

using PIC = pair<int, char>;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long ptr = 0, lenth = 0, cnt = 0;
    cin >> n;
    vector<PIC> str(n);
    for (int i = 0; i < n; i ++) {
        cin >> str[i].first >> str[i].second;
        lenth += str[i].first;
    }
    int lptr = 0, rptr = n - 1, ldf = 0, rdf = 0;
    while (ptr < lenth / 2) {
        int l = str[lptr].first - ldf, r = str[rptr].first - rdf;
        int m = min(l, r);
        if (str[lptr].second != str[rptr].second) cnt += m;
        ptr += m;
        if (l > r) {
            rptr --;
            ldf += r;
            rdf = 0;
        }
        else if (l < r) {
            lptr ++;
            rdf += l;
            ldf = 0;
        }
        else {
            rptr --;
            lptr ++;
            ldf = 0;
            rdf = 0;
        }
    }
    cout << cnt;
    return 0;
}