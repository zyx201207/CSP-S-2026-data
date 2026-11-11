#include <cstdio>
#include <vector>
#include <set>

const int IH = 39;
const int maxn = 5e5 + IH;

int c, n, m, d, q, ans = 0x3f3f3f3f;
int w[maxn];
int trans[500 + IH][maxn];
std::vector<int> atStation[maxn];
std::vector<std::set<int>> line(maxn);

bool atSet(int x, int num)
{
    int _or = line[num].size();
    line[num].insert(x);
    int _nx = line[num].size();
    if (_or == _nx) {
        return true;
    } else {
        line[num].erase(x);
        return false;
    }
}

std::vector<int> findTransfer(int x1, int x2)
{
    std::vector<int> _res;
    for (int i = 1; i <= n; i++) {
        if (atSet(x1, i) == true && atSet(x2, i) == true) {
            _res.push_back(i);
        }
    }
    return _res;
}

/*
void goSubway(int _line, int from, int go, int length)
{
    if (from == go) {
        ans = std::min(ans, length + trans[_line][go]);
        return;
    }
    if (atSet(go, _line)) {
        goSubway(_line, go, go, length);
    } else {
        for (int i : line[_line]);
    }
}
*/

int main(void)
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    scanf("%d %d %d %d %d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1, _ki; i <= n; i++) {
        scanf("%d", &_ki);
        for (int j = 1, _ai, _ti; j <= _ki; j++) {
            scanf("%d %d", &_ai, &_ti);
            atStation[_ai].push_back(i);
            line[i].insert(_ai);
            trans[_ai][j] = _ti;
        }
    }
    for (int i = 1, _x, _y; i <= q; i++) {
        scanf("%d %d", &_x, &_y);
        ans = 0x3f3f3f3f;
        for (int startLine : atStation[_x]) {
            if (atSet(_y, startLine)) {
                ans = std::min(ans, w[_x] + w[_y] + trans[startLine][_x] + trans[startLine][_y]);
            }
        }
        printf("%d\n", ans);
    }

}
