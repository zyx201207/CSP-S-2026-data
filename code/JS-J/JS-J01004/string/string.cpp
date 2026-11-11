#include <cstdio>
#include <utility>

using namespace std;

int n;
pair<int, char> seq[200000];
int l = 0, r;
long long ans = 0;

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d %c", &seq[i].first, &seq[i].second);
    r = n;
    while (l < r - 1)
    {
        int minlp = seq[l].first < seq[r - 1].first ? l : r - 1, minl = seq[minlp].first;
        if (seq[l].second != seq[r - 1].second)
            ans += minl;
        seq[l].first -= minl;
        seq[r - 1].first -= minl;
        if (seq[l].first == 0)
            ++l;
        if (seq[r - 1].first == 0)
            --r;
    }
    printf("%lld\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
