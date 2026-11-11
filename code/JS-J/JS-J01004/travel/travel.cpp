#include <cstdio>

using namespace std;

int abs(int x)
{
    return x < 0 ? -x : x;
}

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c1, c2, sl1, sl2;
    char sr1, sr2;
    scanf("%d%d%c%d%d%c", &c1, &sl1, &sr1, &c2, &sl2, &sr2);
    bool f1 = c1 == c2, f2 = f1 && sl1 == sl2,
        f3 = f2 && (sr1 <= 'C' && sr2 <= 'C' || sr1 >= 'D' && sr2 >= 'D'), f4 = f3 && abs(sr1 - sr2) == 1;
    printf("%d%d%d%d\n", f1, f2, f3, f4);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
