#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, a[500000], lstp[500000], pn[300000];
pair<int, int> plstp[300000];
int nxtlp[300000];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        plstp[i].second = i + 1;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        plstp[a[i] - 1].first = i;
    }
    for (int i = 0; i < n; ++i)
        lstp[i] = plstp[a[i] - 1].first;
    for (int i = 0; i < m; ++i)
        nxtlp[i] = plstp[i].first < n - 1 ? lstp[plstp[i].first + 1] : -1;
    sort(plstp, plstp + m);
    pn[plstp[m - 1].second] = 1;
    for (int i = m - 2; i >= 0; --i)
    {
        pn[plstp[i].second - 1] = pn[a[nxtlp[plstp[i].first]]] + 1;
    }
    printf("#array: {%d(%d)", *a, *lstp);
    for (int i = 1; i < n; i++)
        printf(", %d(%d)", a[i], lstp[i]);
    printf("}\n###\n");
    printf("&plstp: {\n");
    printf("&  [%d]([%d] -> [%d])%d", plstp[0].second, plstp[0].first, nxtlp[plstp[0].second - 1], pn[plstp[0].second - 1]);
    for (int i = 1; i < m; i++)
        printf(",\n&  [%d]([%d] -> [%d])%d", plstp[i].second, plstp[i].first, nxtlp[plstp[i].second - 1], pn[plstp[i].second - 1]);
    return 0;
}
