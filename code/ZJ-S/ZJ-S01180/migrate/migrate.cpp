#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

long long c, t;
long long pathMin, pathCnt;

void findMinRoadCnt(long long siLen, long long cur, long long end, long long cnt, long long bgst, map<long long, bool> pathExist, vector<long long> SpecificPath) {
    if (cur == end) {
        if (SpecificPath.size() == pathMin) pathCnt++;
        else if (SpecificPath.size() < pathMin) {
            pathMin = SpecificPath.size();
            pathCnt = 1;
        } 
        return;
    }
    for (long long i = 1; i <= siLen; i++) {
        if (pathExist[cur + i] && cur + i <= bgst) {
            SpecificPath.push_back(cur + i);
            findMinRoadCnt(siLen, cur + i, end, cnt + 1, bgst, pathExist, SpecificPath);
            SpecificPath.pop_back();
        }
    }
}

bool checkA(long long n, vector<long long> x) {
    for (long long i = 1; i <= n - 2; i++) {
        if (x[i + 1] - x[i] != x[i + 2] - x[i + 1]) return false;
    }
    return true;
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--) {
        long long n, d, doublePath = 0;
        cin >> n >> d;
        vector<long long> x(n + 1);
        map<long long, bool> pathExist;
        for (long long i = 1; i <= n; i++) {
            cin >> x[i];
        }
        long long minVar = *min_element(x.begin() + 1, x.end());
        if (minVar < 0) {
            long long offset = abs(minVar) + 1;
            for (long long i = 1; i <= n; i++) {
                x[i] += offset; 
            }
        }
        for (long long i = 1; i <= n; i++) {
            pathExist[x[i]] = 1;
        }
        findMinRoadCnt(d, 1, 3, 0, x[n], pathExist, {0});
        for (long long i = 1; i <= n; i++) {
            for (long long j = i + 1; j <= n; j++) {
                //cout << pathExist[j] << endl;
                pathMin = 1e9, pathCnt = 0;
                findMinRoadCnt(d, i, j, 0, x[n], pathExist, {0});
                if (pathCnt == 2) doublePath++;
            }
        }
        cout << doublePath << endl;
    }
    return 0;
}