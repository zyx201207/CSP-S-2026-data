#include <bits/stdc++.h>
using namespace std;

int main () {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    long long n;
    cin >> n;

    vector<pair<long long,char> >s;
    for (long long i = 0; i < n; i++) {
        long long n;
        char c;
        cin >> n >> c;

        s.push_back(make_pair(n, c));
    }

    typedef vector<pair<long long,char> >::size_type vint;
    long long cnt = 0;

    for (vint i = 0, j = s.size() - 1; i < j;) {
        if (s[i].second != s[j].second) {
            if (s[i].first > s[j].first) {
                cnt += s[j].first;
                s[i].first -= s[j].first;
                s[j].first = 0;
                j--;
            } else if (s[i].first < s[j].first) {
                cnt += s[i].first;
                s[j].first -= s[i].first;
                s[i].first = 0;
                i++;
            } else {
                cnt += s[i].first;
                s[i].first = 0;
                s[j].first = 0;
                i++;
                j--;
            }
        } else {
            if (s[i].first > s[j].first) {
                s[i].first -= s[j].first;
                s[j].first = 0;
                j--;
            } else if (s[i].first < s[j].first) {
                s[j].first -= s[i].first;
                s[i].first = 0;
                i++;
            } else {
                s[i].first = 0;
                s[j].first = 0;
                i++;
                j--;
            }
        }
   }

    cout << cnt << endl;

    return 0;
}
