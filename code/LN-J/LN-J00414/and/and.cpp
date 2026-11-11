#include <bits/stdc++.h>
using namespace std;
unsigned long long a[500005];
int n;
vector<int> fls[64];
int cal[500005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    memset(a, 0, sizeof(a));
    memset(cal, 0, sizeof(cal));
    cin >> n;
    int m;
    cin >> m;
    unsigned long long tmp;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    int x = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i] > x)
            x = a[i];
    }
    cout << x << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
