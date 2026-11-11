#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == "01" || c1 == "16" || c2 == "01" || c2 == "16")
    {
        cout << 0;
        flag1 = false;
    }
    else
    {
        cout << (c1 == c2);
        flag1 = c1 == c2;
    }

    flag2 = flag1 && (s1[0] == s2[0] && s1[1] == s2[1]);
    cout << flag2;

    int cnt1 = s1[2] - 'A', cnt2 = s2[2] - 'A';
    if (cnt1 > cnt2)
    {
        int tmp = cnt2;
        cnt2 = cnt1;
        cnt1 = tmp;
    }
    cnt1++;
    cnt2++;
    flag3 = flag2 && ((1 <= cnt1 && cnt1 <= 3 && 1 <= cnt2 && cnt2 <= 3) || (cnt1 == 4 && cnt2 == 5));
    cout << flag3;

    flag4 = flag3 && ((cnt1 == 1 && cnt2 == 2) || (cnt1 == 2 && cnt2 == 3) && (cnt2 == 4 && cnt2 == 5));
    cout << flag4;

    return 0;
}
